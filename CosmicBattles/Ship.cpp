#include "Ship.h"

#include "BulletBase.h"
#include "GameWorld.h"
#include "MathLibrary.h"
#include "Entity.h"
#include "ShipController.h"
#include <memory>

#include <iostream>
#include <vector>

Ship::Ship(const sf::Texture& in_texture, const sf::Vector2f& in_position, const float in_direction)
	: Entity{ in_texture, in_position, in_direction }
{
	m_ship_stats.max_rotate_speed = 120.f;
	m_ship_stats.move_speed = 250.f;
	m_ship_stats.slow_down_ratio = 2.f;

	m_controller = std::make_unique<ShipController>();
}

void Ship::update(float in_delta_time)
{
	if (m_controller.get())
	{
		m_controller->handleInput(this);
	}

	if (m_is_accelerating)
	{
		m_ship_stats.current_direction = m_sprite->getRotation();
		accelerate(in_delta_time);
	}
	if (!m_is_accelerating)
	{
		slowDown(in_delta_time / m_ship_stats.slow_down_ratio);
	}

	m_current_reload_rate -= in_delta_time;

	float delta_x = calculateSpeed()  * MathLibrary::calculateCosine(m_ship_stats.current_direction, 90.f) * in_delta_time;
	float delta_y = calculateSpeed() * MathLibrary::calculateSine(m_ship_stats.current_direction, 90.f) * in_delta_time;
	m_position += sf::Vector2f(delta_x, delta_y);


	m_sprite->move(delta_x, delta_y);
	m_sprite->rotate(m_ship_stats.current_rotate_speed * in_delta_time);
}
//
//void Ship::shoot(GameWorld& in_world)
//{
//	if (!canShoot())
//	{
//		return;
//	}
//	m_current_reload_rate = m_reload_rate;
//	in_world.m_entities.push_back(std::make_unique<BulletBase>(m_sprite->getPosition(), m_sprite->getRotation()));
//}

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
