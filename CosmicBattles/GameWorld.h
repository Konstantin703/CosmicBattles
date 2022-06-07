#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "SFML/System/Vector2.hpp"
#include <memory>

#include "Entity.h"
#include <iostream>

#include "BaseFactory.h"
#include <forward_list>
#include "BaseObserver.h"
#include <unordered_map>

class Entity;

class GameWorld: public BaseObserver
{
	using EntityList = std::forward_list<std::unique_ptr<Entity>>;
	using FactoryMap = std::unordered_map<int, std::unique_ptr<BaseFactory>>;
public:
	GameWorld() = default;
	virtual ~GameWorld() = default;

	void init();

	void update(float in_delta_time);

	void onNotify(const Entity& in_entity) override;

	void checkCollision(Entity* in_entity);

	FactoryMap m_factories;
	EntityList m_entities;

private:
	const float X_BOARDER = 2000.f;
	const float Y_BOARDER = 1500.f;

	float m_max_spawn_time = 1.5f;
	float m_current_spawn_time = 0.f;
};

#endif
