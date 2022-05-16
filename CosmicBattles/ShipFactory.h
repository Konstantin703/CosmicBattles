#ifndef SHIP_FACTORY_H
#define SHIP_FACTORY_H

#include "BaseFactory.h"

class ShipFactory : public BaseFactory
{
public:
	ShipFactory();

	~ShipFactory() = default;

	std::unique_ptr<Entity> createEntity(const sf::Vector2f in_position, const float in_direction = 0) override;
};

#endif