#include "GameInstance.h"

#include "SFML/System/Clock.hpp"
#include "Entity.h"
#include "GameWorld.h"
#include "Ship.h"
#include "ShipController.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include "AsteroidManager.h"

GameInstance::GameInstance()
{
	m_window.create(sf::VideoMode::getDesktopMode(), m_game_name, sf::Style::Fullscreen);
	initializeBackground();

	m_asteroid_manager = std::make_unique<AsteroidManager>();

	m_world = std::make_unique<GameWorld>();
	m_world->init();
	
	m_controller = std::make_unique<ShipController>();

	for (auto itr = m_world->m_entities.cbegin(); itr != m_world->m_entities.cend(); ++itr)
	{
		if (itr->get()->getEntityType() == EntityType::ET_Ship)
		{
			m_controller->subscribe(static_cast<Ship*>(itr->get()));
			itr->get()->subscribe(m_world.get());
		}
	}
}

void GameInstance::run()
{
	sf::Clock clock;	
	while (m_window.isOpen())
	{
		float delta_time = clock.restart().asSeconds();
		
		processInput();
		update(delta_time);
		render();
	}
}

void GameInstance::processInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_window.close();
		}

		m_controller->handleInput();
	}
}

void GameInstance::update(float delta_time)
{
	m_asteroid_manager->update(delta_time, m_world.get());

	for (auto itr = m_world->m_entities.cbegin(); itr != m_world->m_entities.cend(); ++itr)
	{
		itr->get()->update(delta_time);
		m_world->checkCollision(itr->get());
	}

	m_world->m_entities.remove_if([](std::unique_ptr<Entity> const & entity) { return entity->shouldRemove(); });
}

void GameInstance::render()
{
	m_window.clear();
	// draw background
	for (auto itr = m_background.cbegin(); itr != m_background.cend(); ++itr)
	{
		m_window.draw(*itr->get());
	}

	// drawn entities
	for (auto itr = m_world->m_entities.cbegin(); itr != m_world->m_entities.cend(); ++itr)
	{
		m_window.draw(itr->get()->getDrawable());
	}
	m_window.display();
}

void GameInstance::initializeBackground()
{
	sf::Texture* background_texture = new sf::Texture();
	background_texture->loadFromFile("resources/background.png");
	sf::Vector2i sprite_size( background_texture->getSize().x, background_texture->getSize().y );

	for (size_t i = 0; i < m_window.getSize().x; i += sprite_size.x)
	{
		for (size_t j = 0; j < m_window.getSize().y; j += sprite_size.y)
		{
			std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>(*background_texture);
			sprite->setPosition(i, j);
			m_background.push_back(std::move(sprite));
		}
	}
}
