#ifndef BULLET_FACTORY_H
#define BULLET_FACTORY_H

#include "BaseFactory.h"

class BulletFactory : public BaseFactory
{
public:
	BulletFactory();
	virtual ~BulletFactory() = default;

	std::unique_ptr<Entity> createEntity(const sf::Vector2f in_position, const float in_direction = 0) override;

};

#endif