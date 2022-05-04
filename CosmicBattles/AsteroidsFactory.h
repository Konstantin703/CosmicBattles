#ifndef ASTEROIDS_FACTORY_H
#define ASTEROIDS_FACTORY_H

#include "SFML/Graphics/Texture.hpp"
#include "Entity.h"
#include <memory>
#include <vector>
#include "SFML/System/Vector2.hpp"

class AsteroidsFactory
{
	using TexturesVector = std::vector<std::unique_ptr<sf::Texture>>;
public:
	AsteroidsFactory();

	std::unique_ptr<Entity> createEntity(const sf::Vector2f in_position, const float in_direction = 0);

	//sf::Texture* getByIndex(int in_index) const;

private:
	TexturesVector m_texture_vector;
};

#endif
