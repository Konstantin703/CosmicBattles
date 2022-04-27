#include "SFML/System/Clock.hpp"

#include "GameInstance.h"
#include "Ship.h"
#include "BulletBase.h"
#include "Entity.h"
#include "ShipController.h"
#include "GameWorld.h"

#include <iostream>
#include <memory>

GameInstance::GameInstance()
{
	m_window.create(sf::VideoMode(m_screen_width, m_screen_height), m_game_name);
	m_world = std::make_unique<GameWorld>();
	m_player_controller = std::make_unique<ShipController>();

	//TODO: randomize position and rotation closer to playable single player demo
	std::shared_ptr<Ship> ship = std::make_shared<Ship>(500.f, 500.f);
 	m_player_controller->m_owner = std::move(ship);
	m_world->m_entities.push_back(m_player_controller->m_owner);
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
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		m_player_controller->handleInput(event);
		
		// bad, this come out of scope of controller class
		// TODO: rework later
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			m_world->m_entities.push_back(m_player_controller->m_owner->shoot());
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
	for (auto itr = m_world->m_entities.crbegin(); itr != m_world->m_entities.crend(); ++itr)
	{
		m_window.draw(*itr->get()->getDrawable());
	}
	m_window.display();
}
