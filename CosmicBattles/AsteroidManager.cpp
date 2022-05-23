#include "AsteroidManager.h"
#include "Asteroid.h"
#include "GameWorld.h"

AsteroidManager::AsteroidManager()
{
	std::unique_ptr<sf::Texture> big_texture = std::make_unique<sf::Texture>();
	if (big_texture->loadFromFile("resources/meteor_big.png"))
	{
		m_texture_vector.push_back(std::move(big_texture));
	}

	//std::unique_ptr<sf::Texture> medium_texture = std::make_unique<sf::Texture>();
	//if (medium_texture->loadFromFile("resources/meteor_med.png"))
	//{
	//	m_texture_vector.push_back(medium_texture);
	//}
}

std::unique_ptr<Entity> AsteroidManager::createEntity(const sf::Vector2f in_position, const float in_direction)
{
	return std::make_unique<Asteroid>(*m_texture_vector[0].get(), in_position, in_direction);
}

void AsteroidManager::update(float in_delta_time, GameWorld* in_world)
{
	m_current_spawn_time += in_delta_time;
	if (m_current_spawn_time > m_max_spawn_time)
	{
		// calculate position
		// calculate direction
		in_world->m_entities.push_front(createEntity(sf::Vector2f(0.f, 500.f), 0.f));
		m_current_spawn_time = 0.f;
	}
}