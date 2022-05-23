#ifndef BASE_FACTORY_H
#define BASE_FACTORY_H

#include "SFML/Graphics/Texture.hpp"
#include <memory.h>

class Entity;

class BaseFactory
{
	using TexturesVector = std::vector<std::unique_ptr<sf::Texture>>;
public:
	virtual ~BaseFactory() = default;

	virtual std::unique_ptr<Entity> createEntity(const sf::Vector2f in_position, const float in_direction = 0) = 0;

protected:
	TexturesVector m_texture_vector;
};
#endif
