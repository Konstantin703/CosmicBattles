#ifndef ASTEROID_MANAGER_H
#define ASTEROID_MANAGER_H

#include "BaseFactory.h"

class GameWorld;

class AsteroidManager : public BaseFactory //, public BaseObserver
{
public:
	AsteroidManager();
	virtual ~AsteroidManager() = default;

	std::unique_ptr<Entity> createEntity(const sf::Vector2f in_position, const float in_direction = 0) override;

	sf::Vector2f getRandomPosition();
private:
	// borders of the world for now
	struct SpawnZone
	{
		int min_val = 0;
		int max_val = 2000;
	};

	SpawnZone m_spawn_zone;
};

#endif