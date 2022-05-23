#include "AsteroidManager.h"
#include "Asteroid.h"
#include "GameWorld.h"
#include <complex>
#include "MathLibrary.h"

AsteroidManager::AsteroidManager()
{
	// oohhhhhh what a mess...
	// work out strings in for loops
	std::unique_ptr<sf::Texture> big_texture1 = std::make_unique<sf::Texture>();
	if (big_texture1->loadFromFile("resources/meteors/meteor_big1.png"))
	{
		m_texture_vector.push_back(std::move(big_texture1));
	}
	std::unique_ptr<sf::Texture> big_texture2 = std::make_unique<sf::Texture>();
	if (big_texture2->loadFromFile("resources/meteors/meteor_big2.png"))
	{
		m_texture_vector.push_back(std::move(big_texture2));
	}
	std::unique_ptr<sf::Texture> big_texture3 = std::make_unique<sf::Texture>();
	if (big_texture3->loadFromFile("resources/meteors/meteor_big3.png"))
	{
		m_texture_vector.push_back(std::move(big_texture3));
	}
	std::unique_ptr<sf::Texture> big_texture4 = std::make_unique<sf::Texture>();
	if (big_texture4->loadFromFile("resources/meteors/meteor_big4.png"))
	{
		m_texture_vector.push_back(std::move(big_texture4));
	}
	// medium rocks
	std::unique_ptr<sf::Texture> medium_texture1 = std::make_unique<sf::Texture>();
	if (medium_texture1->loadFromFile("resources/meteors/meteor_med1.png"))
	{
		m_texture_vector.push_back(std::move(medium_texture1));
	}
	std::unique_ptr<sf::Texture> medium_texture2 = std::make_unique<sf::Texture>();
	if (medium_texture2->loadFromFile("resources/meteors/meteor_med2.png"))
	{
		m_texture_vector.push_back(std::move(medium_texture2));
	}
	// small rocks
	std::unique_ptr<sf::Texture> small_texture1 = std::make_unique<sf::Texture>();
	if (small_texture1->loadFromFile("resources/meteors/meteor_small1.png"))
	{
		m_texture_vector.push_back(std::move(small_texture1));
	}
	std::unique_ptr<sf::Texture> small_texture2 = std::make_unique<sf::Texture>();
	if (small_texture2->loadFromFile("resources/meteors/meteor_small2.png"))
	{
		m_texture_vector.push_back(std::move(small_texture2));
	}
}

std::unique_ptr<Entity> AsteroidManager::createEntity(const sf::Vector2f in_position, const float in_direction)
{
	srand(time(nullptr));
	return std::make_unique<Asteroid>(*m_texture_vector[rand() % m_texture_vector.size()].get(), in_position, in_direction);
}

void AsteroidManager::update(float in_delta_time, GameWorld* in_world)
{
	m_current_spawn_time += in_delta_time;
	if (m_current_spawn_time > m_max_spawn_time)
	{
		// find ship location
		// probably better notify the controller
		// and get the postion there
		sf::Vector2f ship_loc;
		for (auto itr = in_world->m_entities.cbegin(); itr != in_world->m_entities.cend(); ++itr)
		{
			if (itr->get()->getEntityType() == EntityType::ET_Ship)
			{
				ship_loc = itr->get()->getPosition();
			}
		}

		sf::Vector2f start = getRandomPosition();
		in_world->m_entities.push_front(createEntity(start, MathLibrary::calculateAngle(start, ship_loc)));

		m_current_spawn_time = 0.f;
	}
}

sf::Vector2f AsteroidManager::getRandomPosition()
{
	srand(time(nullptr));

	int roll = rand() % 4;

	int x = 0;
	int y = 0;

	switch (roll)
	{
	case 0:
		x = m_spawn_zone.min_val;
		y = rand() % m_spawn_zone.max_val;
		break;
	case 1:
		x = m_spawn_zone.max_val;
		y = rand() % m_spawn_zone.max_val;
		break;
	case 2:
		x = rand() % m_spawn_zone.max_val;
		y = m_spawn_zone.min_val;
		break;
	case 3:
		x = rand() % m_spawn_zone.max_val;
		y = m_spawn_zone.max_val;
		break;
	}

	return sf::Vector2f(x, y);
}
