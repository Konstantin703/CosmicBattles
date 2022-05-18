#include "BulletBase.h"
#include "Entity.h"
#include "MathLibrary.h"
#include <memory>
#include <iostream>
#include <algorithm>

BulletBase::BulletBase(const sf::Texture& in_texture, const sf::Vector2f& in_position, const float in_direction)
	: Entity{ in_texture, in_position, in_direction }
{
	m_type = EntityType::ET_Bullet;
}

void BulletBase::update(float in_delta_time)
{
	float speed = 600.f;
	float delta_x = speed  * MathLibrary::calculateCosine(m_direction, 90.f) * in_delta_time;
	float delta_y = speed * MathLibrary::calculateSine(m_direction, 90.f) * in_delta_time;
	m_sprite->move(delta_x, delta_y);

	//m_listener->onNotify(this);
}

