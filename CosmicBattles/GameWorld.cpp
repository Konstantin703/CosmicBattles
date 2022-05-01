#include "GameWorld.h"
#include "Ship.h"

GameWorld::GameWorld()
{
	m_entities.reserve(10);
	m_entities.resize(0);

	// temporary
	std::shared_ptr<Ship> dummy_ship = std::make_shared<Ship>(700.f, 700.f);
	m_entities.push_back(dummy_ship);
}
