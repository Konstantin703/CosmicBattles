#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <memory>
#include <vector>

class Entity;

class GameWorld
{
	using EntityVector = std::vector<std::shared_ptr<Entity>>;
public:
	GameWorld();

	EntityVector m_entities;
private:

};

#endif
