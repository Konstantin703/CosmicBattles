#include "Ship.h"

#include "BulletBase.h"
#include "GameWorld.h"
#include "MathLibrary.h"

#include <memory>

#include <iostream>
//#include <algorithm>

#include <vector>

Ship::Ship(float in_pos_x, float in_pos_y)
	: m_location{in_pos_x, in_pos_y}
{
	// probably memory leak, 
	// should be fixed in the future with sprite holder class implementation
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("resources/spaceship.png");

	m_sprite = std::make_shared<sf::Sprite>(*texture);
	m_sprite->setPosition(m_location);
	m_sprite->setOrigin((texture->getSize().x / 2), (texture->getSize().y / 2));

	m_ship_stats.max_rotate_speed = 120.f;
	m_ship_stats.move_speed = 250.f;
	m_ship_stats.slow_down_ratio = 2.f;
}

Ship::Ship(const Ship& in_object)
{
	m_sprite = in_object.m_sprite;
	m_location = in_object.m_location;

	m_ship_stats.max_rotate_speed = in_object.m_ship_stats.max_rotate_speed;
	m_ship_stats.move_speed = in_object.m_ship_stats.max_rotate_speed;
	m_ship_stats.slow_down_ratio = in_object.m_ship_stats.max_rotate_speed;
}

Ship::Ship(Ship&& in_object)
{
	std::swap(*this, in_object);
}

Ship& Ship::operator=(Ship&& in_object)
{
	if (*this != in_object)
	{
		std::swap(*this, in_object);
	}

	return *this;
}

void Ship::update(float in_delta_time, const GameWorld& in_world)
{
	if (m_is_accelerating)
	{
		m_ship_stats.m_current_direction = m_sprite->getRotation();
		accelerate(in_delta_time);
	}
	if (!m_is_accelerating)
	{
		slowDown(in_delta_time / m_ship_stats.slow_down_ratio);
	}

	m_current_reload_rate -= in_delta_time;

	float delta_x = calculateSpeed()  * MathLibrary::calculateCosine(m_ship_stats.m_current_direction, 90.f) * in_delta_time;
	float delta_y = calculateSpeed() * MathLibrary::calculateSine(m_ship_stats.m_current_direction, 90.f) * in_delta_time;
	m_location += sf::Vector2f(delta_x, delta_y);

	if (in_world.isOnBoarder(m_location))
	{
		m_is_accelerating = false;
		m_ship_stats.m_current_direction += 180.f;
	}

	m_sprite->move(delta_x, delta_y);
	m_sprite->rotate(m_ship_stats.current_rotate_speed * in_delta_time);
}

sf::Drawable* Ship::getDrawable()
{
	return m_sprite.get();
}

void Ship::shoot(GameWorld& in_world)
{
	if (!canShoot())
	{
		return;
	}
	m_current_reload_rate = m_reload_rate;
	in_world.m_entities.push_back(std::make_unique<BulletBase>(m_sprite->getPosition(), m_sprite->getRotation()));
}

float Ship::calculateSpeed() const
{
	return m_ship_stats.move_speed * m_ship_stats.current_acceleration;
}

void Ship::accelerate(float in_value)
{
	if (m_ship_stats.current_acceleration >= 1.f)
	{
		m_ship_stats.current_acceleration = 1.f;
	}
	m_ship_stats.current_acceleration += in_value;
}

void Ship::slowDown(float in_value)
{
	if (m_ship_stats.current_acceleration <= 0.f)
	{
		m_ship_stats.current_acceleration = 0.f;
	}
	m_ship_stats.current_acceleration -= in_value;
}

bool Ship::canShoot() const
{
	return m_current_reload_rate <= 0.f;
}

bool operator==(const Ship& left_value, const Ship& right_value)
{
	return &left_value == &right_value;
}

bool operator!=(const Ship& left_value, const Ship& right_value)
{
	return !(left_value == right_value);
}