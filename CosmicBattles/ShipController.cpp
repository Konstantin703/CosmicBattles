#include "ShipController.h"
#include "SFML/Window/Event.hpp"
#include "Ship.h"

void ShipController::handleInput(sf::Event& in_event)
{
	if (!m_owner.get())
	{
		return;
	}

	switch (in_event.key.code)
	{
	case sf::Keyboard::Left:
		m_owner->setCurrentRotationSpeed(-m_owner->getRotationSpeed());
		break;
	case sf::Keyboard::Right:
		m_owner->setCurrentRotationSpeed(m_owner->getRotationSpeed());
		break;
	case sf::Keyboard::Up:
		m_owner->setIsAccelerating(true);
		break;
	}

	// still messy, but works
	// TODO: refactor 
	if (in_event.type == sf::Event::KeyReleased && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_owner->isAccelerating())
		{
			m_owner->setIsAccelerating(false);
		}
	}
	if (in_event.type == sf::Event::KeyReleased &&
		!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		if (m_owner->isRotating())
		{
			m_owner->setCurrentRotationSpeed(0.f);
		}
	}
}
