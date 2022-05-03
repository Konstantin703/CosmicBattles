#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "SFML/System/Vector2.hpp"
#include <memory>
#include <vector>

class Entity;

class GameWorld
{
	using EntityVector = std::vector<std::shared_ptr<Entity>>;
public:
	GameWorld();

	bool isOnBoarder(const sf::Vector2f& in_vector) const;

	EntityVector m_entities;
private:
	const float X_BOARDER = 1200.f;
	const float Y_BOARDER = 900.f;
};

#endif
