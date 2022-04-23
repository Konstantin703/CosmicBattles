#include "BulletBase.h"
#include <memory>
#include <iostream>
#include <algorithm>

BulletBase::BulletBase(const sf::Vector2f& in_position, const float in_direction)
{
	m_life_time = 3.f;
	m_bullet = std::make_unique<sf::CircleShape>(10.f);
	m_bullet->setFillColor(sf::Color::Red);
	m_bullet->setPosition(in_position);
	
	m_direction = in_direction;
}

BulletBase::BulletBase(const BulletBase& in_object)
{
	m_life_time = in_object.m_life_time;
	m_bullet = std::make_unique<sf::CircleShape>(*in_object.getBullet());
	m_direction = in_object.m_direction;
}

BulletBase::BulletBase(BulletBase&& in_object)
{
	m_life_time = in_object.m_life_time;
	m_bullet = std::make_unique<sf::CircleShape>(*in_object.getBullet());
	m_direction = in_object.m_direction;

	in_object.m_bullet = nullptr;
	in_object.m_direction = 0.f;
	in_object.m_life_time = 0.f;
}


void BulletBase::update(float in_delta_time)
{
	std::cout << "Bullet is flying!!" << std::endl;
}