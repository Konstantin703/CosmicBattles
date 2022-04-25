#ifndef SHIP_CONTROLLER_H
#define SHIP_CONTROLLER_H

#include <string>
#include <memory>
#include <SFML/Window.hpp>
#include "Ship.h"

class ShipController
{
public:
	ShipController() {};
	~ShipController() {};

	void handleInput(sf::Event& in_event);

	std::shared_ptr<Ship> m_owner;
	inline Ship* getOwner() const { return m_owner.get(); }
};
#endif
