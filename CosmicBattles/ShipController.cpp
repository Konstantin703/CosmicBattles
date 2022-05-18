#include "ShipController.h"
#include "Ship.h"
#include "SFML/Window/Keyboard.hpp"


void ShipController::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		m_ship->setCurrentRotationSpeed(-m_ship->getRotationSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_ship->setCurrentRotationSpeed(m_ship->getRotationSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_ship->setIsAccelerating(true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_ship->shoot();
	}

	if (sf::Event::KeyReleased && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		if (m_ship->isAccelerating())
		{
			m_ship->setIsAccelerating(false);

		}
	}

	if (sf::Event::KeyReleased &&
		!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		if (m_ship->isRotating())
		{
			m_ship->setCurrentRotationSpeed(0.f);
		}
	}
}
