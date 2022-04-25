#include "SFML/System/Clock.hpp"

#include "GameInstance.h"
#include "Ship.h"
#include "BulletBase.h"
#include "Entity.h"
#include "ShipController.h"

#include <iostream>
#include <memory>

GameInstance::GameInstance()
{
	m_window.create(sf::VideoMode(m_screen_width, m_screen_height), m_game_name);

	m_player_controller = std::make_unique<ShipController>();
	std::shared_ptr<Ship> ship = std::make_shared<Ship>(500.f, 500.f);
 	m_player_controller->m_owner = std::move(ship);
	//TODO: randomize position and rotation closer to playable single player demo

	m_entities.reserve(10); 
	m_entities.resize(0);
	
	m_entities.push_back(m_player_controller->m_owner);
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
	}
}

void GameInstance::update(float delta_time)
{
	for (auto itr = m_entities.crbegin(); itr != m_entities.crend(); ++itr)
	{
		itr->get()->update(delta_time);
	}
}

void GameInstance::render()
{
	m_window.clear();
	for (auto itr = m_entities.crbegin(); itr != m_entities.crend(); ++itr)
	{
		m_window.draw(*itr->get()->getDrawable());
	}
	m_window.display();
}
