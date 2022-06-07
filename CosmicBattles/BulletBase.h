#ifndef BULLET_BASE_H
#define BULLET_BASE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <memory>

class BulletBase : public Entity
{
public:
	BulletBase(const sf::Texture& in_texture, const sf::Vector2f& in_position = sf::Vector2f(), const float in_direction = 0.f);
	virtual ~BulletBase() = default;

	void update(float in_delta_time) override;
	void onHit(const Entity& in_entity) override;

private:
	float m_life_time = 0.f;

};
#endif
