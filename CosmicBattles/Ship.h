#ifndef SHIP_H
#define SHIP_H

#include "SFML/Graphics.hpp"
#include "Entity.h"

struct ShipStats
{
	float rotate_speed = 0.f;
	float move_speed = 0.f;
	float slow_down_ratio = 0.f;

	float current_acceleration = 0.f;
	// TODO: process these values in future iterations
	float fuel_ratio = 0.f;
	float health = 0.f;
};

class Ship : public Entity
{
public:
	Ship() = delete;
	explicit Ship(float in_pos_x, float in_pos_y);

	inline bool isAccelerating() const { return m_is_accelerating; }
	inline void setIsAccelerating(bool in_value) { m_is_accelerating = in_value; }

	std::unique_ptr<BulletBase> shoot();

	// ~ Entity class implementation
	void update(float in_delta_time) override;
	sf::Drawable* getDrawable() override;
	// ~ end 
private:
	bool m_is_accelerating = false;
	float m_current_direction = 0.f;
	
	ShipStats m_ship_stats;
	std::unique_ptr<sf::Sprite> m_sprite;

	float calculateSpeed() const;

	void accelerate(float in_value);
	void slowDown(float in_value);
};
#endif
