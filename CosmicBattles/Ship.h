#ifndef SHIP_H
#define SHIP_H

#include "SFML/Graphics.hpp"
#include "Entity.h"

class BulletBase;

struct ShipStats
{
	float max_rotate_speed = 0.f;
	float current_rotate_speed = 0.f;

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
	explicit Ship(float in_pos_x, float in_pos_y);
	Ship(const Ship& in_object);
	Ship(Ship&& in_object);
	Ship& operator=(Ship&& in_object);
	
	virtual ~Ship() {};

	Ship() = delete;
	Ship& operator=(const Ship& in_object) = delete;

	inline bool isAccelerating() const { return m_is_accelerating; }
	inline void setIsAccelerating(bool in_value) { m_is_accelerating = in_value; }

	inline void setCurrentRotationSpeed(float in_value) { m_ship_stats.current_rotate_speed = in_value; }
	inline float getRotationSpeed() const { return m_ship_stats.max_rotate_speed; }

	inline bool isRotating() { return m_ship_stats.current_rotate_speed != 0.f; }

	std::unique_ptr<BulletBase> shoot();

	// ~ Entity class implementation
	void update(float in_delta_time) override;
	sf::Drawable* getDrawable() override;
	// ~ end 
private:
	bool m_is_accelerating = false;
	float m_current_direction = 0.f;
	
	ShipStats m_ship_stats;
	std::shared_ptr<sf::Sprite> m_sprite;

	float calculateSpeed() const;

	void accelerate(float in_value);
	void slowDown(float in_value);

	friend bool operator==(const Ship& left_value, const Ship& right_value);
	friend bool operator!=(const Ship& left_value, const Ship& right_value);
};

#endif
