#ifndef SHIP_H
#define SHIP_H

#include "SFML/Graphics.hpp"
#include "Entity.h"

struct ShipStats
{
	float max_rotate_speed = 0.f;
	float current_rotate_speed = 0.f;

	float move_speed = 0.f;
	float slow_down_ratio = 0.f;

	float current_acceleration = 0.f;
	float m_current_direction = 0.f;
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

	inline void setCurrentRotationSpeed(float in_value) { m_ship_stats.current_rotate_speed = in_value; }
	inline float getRotationSpeed() const { return m_ship_stats.max_rotate_speed; }

	inline void setCurrentLocation(const sf::Vector2f& in_location) { m_location = in_location; }
	inline sf::Vector2f getCurrentLocation() const { return m_location; }

	inline bool isAccelerating() const { return m_is_accelerating; }
	inline void setIsAccelerating(bool in_value) { m_is_accelerating = in_value; }

	inline bool isRotating() { return m_ship_stats.current_rotate_speed != 0.f; }

	void shoot(GameWorld& in_world);
	bool canShoot() const;

	// ~ Entity class implementation
	void update(float in_delta_time, const GameWorld& in_world) override;
	sf::Drawable* getDrawable() override;
	// ~ end 
private:
	bool m_is_accelerating = false;
	
	// should be in gun
	float m_reload_rate = 1.f;
	float m_current_reload_rate = 0.f;
	// ~ should be in gun 

	sf::Vector2f m_location;
	
	ShipStats m_ship_stats;
	std::shared_ptr<sf::Sprite> m_sprite;

	float calculateSpeed() const;

	void accelerate(float in_value);
	void slowDown(float in_value);

	friend bool operator==(const Ship& left_value, const Ship& right_value);
	friend bool operator!=(const Ship& left_value, const Ship& right_value);
};

#endif
