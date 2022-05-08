#ifndef SHIP_CONTROLLER_H
#define SHIP_CONTROLLER_H

#include "Ship.h"

class Ship;

class ShipController
{
public:
	ShipController() {};
	~ShipController() {};

	void handleInput(Ship* in_ship);

	//std::unique_ptr<Ship> m_owner;
	//inline Ship* getOwner() const { return m_owner.get(); }
};
#endif
