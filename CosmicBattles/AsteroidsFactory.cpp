#include "AsteroidsFactory.h"
#include "Asteroid.h"

AsteroidsFactory::AsteroidsFactory()
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

std::unique_ptr<Entity> AsteroidsFactory::createEntity(const sf::Vector2f in_position, const float in_direction)
{
	return std::make_unique<Asteroid>(*m_texture_vector[0].get(), in_position, in_direction);
}