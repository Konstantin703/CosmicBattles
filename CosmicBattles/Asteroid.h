#ifndef ASTERIOD_H
#define ASTERIOD_H

#include "Entity.h"

class Asteroid : public Entity
{
public:
	Asteroid(const sf::Texture& in_texture, const sf::Vector2f& in_position = sf::Vector2f(), const float in_direction = 0.f);

	void update(float in_delta_time) override;
private:

};

#endif // ASTERIOD_H
