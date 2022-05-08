#include "ShipController.h"
#include "Ship.h"
#include "SFML/Window/Keyboard.hpp"


void ShipController::handleInput(Ship* in_ship)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		in_ship->setCurrentRotationSpeed(-in_ship->getRotationSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		in_ship->setCurrentRotationSpeed(in_ship->getRotationSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		in_ship->setIsAccelerating(true);
	}

	if (sf::Event::KeyReleased && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (in_ship->isAccelerating())
		{
			in_ship->setIsAccelerating(false);
		}
	}

	if (sf::Event::KeyReleased &&
		!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		if (in_ship->isRotating())
		{
			in_ship->setCurrentRotationSpeed(0.f);
		}
	}
}
