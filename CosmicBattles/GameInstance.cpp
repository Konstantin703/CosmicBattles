#include "GameInstance.h"

#include "SFML/System/Clock.hpp"

#include "BulletBase.h"
#include "Entity.h"
#include "GameWorld.h"
#include "Ship.h"
#include "ShipController.h"

#include <iostream>
#include <memory>

GameInstance::GameInstance()
{
	m_window.create(sf::VideoMode::getDesktopMode(), m_game_name, sf::Style::Fullscreen);
	initializeBackground();

	m_world = std::make_unique<GameWorld>();
	m_asteroid_manager = std::make_unique<AsteroidsFactory>();
	
	sf::Vector2f pos1{ 300.f, 400.f };
	m_world->m_entities.push_back(m_asteroid_manager->createEntity(pos1));

	pos1 = sf::Vector2f{ 500.f, 250.f };
	m_world->m_entities.push_back(m_asteroid_manager->createEntity(pos1));

	pos1 = sf::Vector2f{ 800.f, 650.f };
	m_world->m_entities.push_back(m_asteroid_manager->createEntity(pos1));

	pos1 = sf::Vector2f{ 500.f, 950.f };
	m_world->m_entities.push_back(m_asteroid_manager->createEntity(pos1));

	pos1 = sf::Vector2f{ 900.f, 250.f };
	m_world->m_entities.push_back(m_asteroid_manager->createEntity(pos1));

	//m_player_controller = std::make_unique<ShipController>();

	////TODO: randomize position and rotation closer to playable single player demo
	//std::shared_ptr<Ship> ship = std::make_shared<Ship>(500.f, 500.f);
 //	m_player_controller->m_owner = std::move(ship);
	//m_world->m_entities.push_back(m_player_controller->m_owner);
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
		//m_player_controller->handleInput(event);
		
		// bad, this come out of scope of controller class
		// TODO: rework later
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//m_player_controller->m_owner->shoot(*m_world.get());
		}
	}
}

void GameInstance::update(float delta_time)
{
	for (auto itr = m_world->m_entities.crbegin(); itr != m_world->m_entities.crend(); ++itr)
	{
		itr->get()->update(delta_time);
	}
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
	for (auto itr = m_world->m_entities.crbegin(); itr != m_world->m_entities.crend(); ++itr)
	{
		m_window.draw(*itr->get()->getDrawable());
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
