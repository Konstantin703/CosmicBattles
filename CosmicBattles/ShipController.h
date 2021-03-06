#ifndef SHIP_CONTROLLER_H
#define SHIP_CONTROLLER_H

#include "Ship.h"

class Ship;

class ShipController
{
public:
	ShipController() = default;
	~ShipController() = default;

	void handleInput();

	void subscribe(Ship* in_ship) { m_ship = in_ship; }

private:
	Ship* m_ship;

};
#endif
