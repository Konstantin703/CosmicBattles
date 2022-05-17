#include "BulletFactory.h"
#include "BulletBase.h"

BulletFactory::BulletFactory()
{
	std::unique_ptr<sf::Texture> bullet = std::make_unique<sf::Texture>();
	if (bullet->loadFromFile("resources/bullet.png"))
	{
		m_texture_vector.push_back(std::move(bullet));
	}
}

std::unique_ptr<Entity> BulletFactory::createEntity(const sf::Vector2f in_position, const float in_direction)
{
	return std::make_unique<BulletBase>(*m_texture_vector[0].get(), in_position, in_direction);
}
