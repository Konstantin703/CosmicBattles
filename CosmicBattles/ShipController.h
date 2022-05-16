#ifndef SHIP_CONTROLLER_H
#define SHIP_CONTROLLER_H

#include "Ship.h"

class Ship;

class ShipController
{
public:
	ShipController() = default;
	~ShipController() = default;

	void handleInput(Ship* in_ship);

};
#endif
