#ifndef SHIP_H
#define SHIP_H

#include "Entity.h"
#include "SFML/Graphics.hpp"

#include <memory>
#include "ShipController.h"

class ShipController;

struct ShipStats
{
	float max_rotate_speed = 0.f;
	float move_speed = 0.f;
	float slow_down_ratio = 0.f;

	float current_rotate_speed = 0.f;
	float current_acceleration = 0.f;
	float current_direction = 0.f;
	// TODO: process these values in future iterations
	float fuel_ratio = 0.f;
	float health = 0.f;
};

class Ship : public Entity
{
public:
	Ship(const sf::Texture& in_texture, const sf::Vector2f& in_position = sf::Vector2f(), const float in_direction = 0.f);
	
	virtual ~Ship() {};

	inline void setCurrentRotationSpeed(float in_value) { m_ship_stats.current_rotate_speed = in_value; }
	inline float getRotationSpeed() const { return m_ship_stats.max_rotate_speed; }

	inline bool isAccelerating() const { return m_is_accelerating; }
	inline void setIsAccelerating(bool in_value) { m_is_accelerating = in_value; }

	inline bool isRotating() { return m_ship_stats.current_rotate_speed != 0.f; }

	void shoot();
	bool canShoot() const;

	void update(float in_delta_time) override;

private:
	bool m_is_accelerating = false;
	
	// should be in gun
	float m_reload_rate = 0.f;
	float m_current_reload_rate = 0.f;
	// ~ should be in gun 
	
	ShipStats m_ship_stats;

	float calculateSpeed() const;

	void accelerate(float in_value);
	void slowDown(float in_value);
};

#endif
