#include "Asteroid.h"
#include "Entity.h"

Asteroid::Asteroid(const sf::Texture& in_texture, const sf::Vector2f& in_position, const float in_direction)
	: Entity{ in_texture, in_position, in_direction }
{
	m_type = EntityType::ET_Asteroid;
}

void Asteroid::update(float in_delta_time)
{
	float rotation_rate = 200.f;
	m_direction = in_delta_time * rotation_rate;
	m_sprite->rotate(m_direction);
}