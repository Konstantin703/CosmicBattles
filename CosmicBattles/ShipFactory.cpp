#include "ShipFactory.h"

#include "Ship.h"

#include <stdlib.h>
#include <time.h>

ShipFactory::ShipFactory()
{
	std::unique_ptr<sf::Texture> ship_one = std::make_unique<sf::Texture>();
	if (ship_one->loadFromFile("resources/spaceship01.png"))
	{
		m_texture_vector.push_back(std::move(ship_one));
	}

	std::unique_ptr<sf::Texture> ship_two = std::make_unique<sf::Texture>();
	if (ship_two->loadFromFile("resources/spaceship02.png"))
	{
		m_texture_vector.push_back(std::move(ship_two));
	}

	std::unique_ptr<sf::Texture> ship_three = std::make_unique<sf::Texture>();
	if (ship_three->loadFromFile("resources/spaceship03.png"))
	{
		m_texture_vector.push_back(std::move(ship_three));
	}
}

std::unique_ptr<Entity> ShipFactory::createEntity(const sf::Vector2f in_position, const float in_direction)
{
	srand(time(nullptr));
	return std::make_unique<Ship>(*m_texture_vector[rand() % m_texture_vector.size()].get(), in_position, in_direction);
}