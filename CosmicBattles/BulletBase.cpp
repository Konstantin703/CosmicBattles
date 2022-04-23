#include "BulletBase.h"
#include <memory.h>
#include <iostream>

BulletBase::BulletBase(const sf::Vector2f& in_position, const float in_direction)
{
	m_life_time = 3.f;
	m_bullet = new sf::CircleShape(20.f);
	m_bullet->setFillColor(sf::Color::Red);
	m_bullet->setPosition(in_position);
	
	m_direction = in_direction;
}

BulletBase::~BulletBase()
{
	delete m_bullet;
}
void BulletBase::update(float in_delta_time)
{
	std::cout << "Bullet is flying!!" << std::endl;
}