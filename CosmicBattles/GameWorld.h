#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "SFML/System/Vector2.hpp"
#include <memory>

class GameWorld
{
public:
	static GameWorld& getInstance();

	// no copying for singleton
	GameWorld(const GameWorld&) = delete;
	GameWorld& operator=(const GameWorld&) = delete;

	//bool isOnBoarder(const sf::Vector2f& in_vector) const;

private:
	GameWorld() = default;

	static GameWorld* instance_;

	const float X_BOARDER = 1500.f;
	const float Y_BOARDER = 900.f;
};

#endif
