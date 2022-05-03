#include "GameWorld.h"

#include "Entity.h"
#include "Ship.h"

GameWorld::GameWorld()
{
	m_entities.reserve(10);
	m_entities.resize(0);

	// temporary
	std::shared_ptr<Ship> dummy_ship = std::make_shared<Ship>(700.f, 700.f);
	m_entities.push_back(dummy_ship);
}

bool GameWorld::isOnBoarder(const sf::Vector2f& in_vector) const
{
	return in_vector.x <= 0.f || in_vector.x >= X_BOARDER || in_vector.y <= 0.f || in_vector.y >= Y_BOARDER;
}