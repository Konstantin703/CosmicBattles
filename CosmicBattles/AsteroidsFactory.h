#ifndef ASTEROIDS_FACTORY_H
#define ASTEROIDS_FACTORY_H

#include "BaseFactory.h"
#include "Entity.h"
#include <memory>
#include <vector>
#include "SFML/System/Vector2.hpp"

class AsteroidsFactory : public BaseFactory
{
public:
	AsteroidsFactory();

	~AsteroidsFactory() {};

	std::unique_ptr<Entity> createEntity(const sf::Vector2f in_position, const float in_direction = 0) override;
	
};

#endif
