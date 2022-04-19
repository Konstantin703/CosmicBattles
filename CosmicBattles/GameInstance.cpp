#include "SFML/System/Clock.hpp"

#include "GameInstance.h"
#include "Ship.h"

#include <iostream>

GameInstance::GameInstance()
{
	m_window.create(sf::VideoMode(m_screen_width, m_screen_height), m_game_name);
	
	//TODO: randomize position and rotation closer to playable single player demo
	m_player = std::make_unique<Ship>(500.f, 500.f);
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

// TODO: think about another solution for handling multiple events
void GameInstance::processInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_player->setIsAccelerating(true);
			}
			break;
		case sf::Event::KeyReleased:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				break;
			}
			if (m_player->isAccelerating())
			{
				m_player->setIsAccelerating(false);
			}
			break;
		case sf::Event::Closed:
			m_window.close();
			break;
		}
	}
}

void GameInstance::update(float delta_time)
{
	if (m_player)
	{
		m_player->update(delta_time);
	}
}

void GameInstance::render()
{
	m_window.clear();
	m_window.draw(m_player->getSprite());
	m_window.display();
}
