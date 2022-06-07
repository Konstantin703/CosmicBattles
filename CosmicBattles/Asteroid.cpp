#include "Asteroid.h"
#include "Entity.h"
#include "MathLibrary.h"

Asteroid::Asteroid(const sf::Texture& in_texture, const sf::Vector2f& in_position, const float in_direction)
	: Entity{ in_texture, in_position, in_direction }
{
	m_type = EntityType::ET_Asteroid;
}

void Asteroid::update(float in_delta_time)
{
	float rotation_rate = 200.f;
	float speed = 500.f;
	m_sprite->rotate(in_delta_time * rotation_rate);

	float delta_x = speed * MathLibrary::calculateCosine(m_direction) * in_delta_time;
	float delta_y = speed * MathLibrary::calculateSine(m_direction) * in_delta_time;
	m_position += sf::Vector2f(delta_x, delta_y);

	m_sprite->move(delta_x, delta_y);
}

void Asteroid::onHit(const Entity& in_entity)
{
	// asteroid manager -> notify
	if (m_listener)
	{
		m_listener->onNotify(*this);
	}
	setRemove();
}