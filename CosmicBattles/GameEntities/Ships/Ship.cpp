
#include "BulletBase.h"
#include "Ship.h"
#include "MathLibrary.h"
#include <memory>
#include <iostream>

Ship::Ship(float in_pos_x, float in_pos_y)
{
	// probably memory leak, 
	// should be fixed in the future with sprite holder class implementation
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("resources/spaceship.png");

	m_sprite = std::make_unique<sf::Sprite>(*texture);
	m_sprite->setPosition(in_pos_x, in_pos_y);
	m_sprite->setOrigin((texture->getSize().x / 2), (texture->getSize().y / 2));

	m_ship_stats.rotate_speed = 120.f;
	m_ship_stats.move_speed = 250.f;
	m_ship_stats.slow_down_ratio = 2.f;
}

// TODO: divide into multiple methods
// think about another solution of handling events
void Ship::update(float in_delta_time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_sprite->rotate(-m_ship_stats.rotate_speed * in_delta_time);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_sprite->rotate(m_ship_stats.rotate_speed * in_delta_time);
	}

	if (m_is_accelerating)
	{
		m_current_direction = m_sprite->getRotation();
		accelerate(in_delta_time);
	}

	if (!m_is_accelerating)
	{
		slowDown(in_delta_time / 2);
	}

	float delta_x = calculateSpeed()  * MathLibrary::calculateCosine(m_current_direction, 90.f) * in_delta_time;
	float delta_y = calculateSpeed() * MathLibrary::calculateSine(m_current_direction, 90.f) * in_delta_time;
	m_sprite->move(delta_x, delta_y);
}

BulletBase* Ship::shoot()
{
	std::cout << "Ship shoot" << std::endl;
	return new BulletBase(m_sprite->getPosition(), m_sprite->getRotation());
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
