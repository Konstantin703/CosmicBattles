#ifndef BULLET_BASE_H
#define BULLET_BASE_H

#include <SFML/Graphics.hpp>

#include "Entity.h"

#include <memory>

class BulletBase : public Entity
{
public:
	BulletBase() = delete;
	explicit BulletBase(const sf::Vector2f& in_position, const float in_direction);

	BulletBase(const BulletBase& in_object);
	BulletBase(BulletBase&& in_object);

	inline float getDirection() const { return m_direction; }
	inline void setDirection(float in_value) { m_direction = in_value; }

	//inline sf::CircleShape* getBullet() const { return m_bullet.get(); }

	// ~ Entity class implementation
	void update(float in_delta_time) override;
	sf::Drawable* getDrawable() override;
	// ~ end 	
	
private:
	float m_life_time = 0.f;
	float m_direction = 0.f;
	// the visual representation should be in another container class
	std::unique_ptr<sf::CircleShape> m_bullet;
};
#endif
