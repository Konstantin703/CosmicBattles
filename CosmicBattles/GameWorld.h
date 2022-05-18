#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "SFML/System/Vector2.hpp"
#include <memory>

#include "Entity.h"
#include <iostream>

#include "BaseFactory.h"
#include <forward_list>

class Entity;
class BaseFactory;


class GameWorld
{
	using EntityList = std::forward_list<std::unique_ptr<Entity>>;
public:
	GameWorld();

	void onNotify(Entity* in_entity);
	void onFactoryNotify(Entity* in_entity);

	std::unique_ptr<BaseFactory> m_bullet_manager;

	EntityList m_entities;


private:


	const float X_BOARDER = 1500.f;
	const float Y_BOARDER = 900.f;
};

#endif
