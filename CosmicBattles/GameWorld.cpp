#include "GameWorld.h"
#include "Entity.h"
#include <iostream>
#include "GameInstance.h"
#include "BulletFactory.h"
#include <memory>
#include "AsteroidsFactory.h"
#include "ShipFactory.h"

void GameWorld::Init()
{
	m_bullet_manager = std::make_unique<BulletFactory>();
	////TODO: randomize position and rotation closer to playable single player demo
	m_asteroid_manager = std::make_unique<AsteroidsFactory>();

	sf::Vector2f pos1{ 300.f, 400.f };
	m_entities.push_front(m_asteroid_manager->createEntity(pos1));

	pos1 = sf::Vector2f{ 500.f, 250.f };
	m_entities.push_front(m_asteroid_manager->createEntity(pos1));

	pos1 = sf::Vector2f{ 800.f, 650.f };
	m_entities.push_front(m_asteroid_manager->createEntity(pos1));

	pos1 = sf::Vector2f{ 500.f, 950.f };
	m_entities.push_front(m_asteroid_manager->createEntity(pos1));

	pos1 = sf::Vector2f{ 900.f, 250.f };
	m_entities.push_front(m_asteroid_manager->createEntity(pos1));


	m_ship_manager = std::make_unique<ShipFactory>();
	m_entities.push_front(m_ship_manager->createEntity(sf::Vector2f(1200.f, 600.f)));
}

void GameWorld::onFactoryNotify(Entity* in_entity)
{
	if (!m_bullet_manager.get())
	{
		return;
	}

	std::cout << "void GameWorld::onFactoryNotify(Entity* in_entity)" << std::endl;
	m_entities.push_front(m_bullet_manager->createEntity(in_entity->getPosition(), in_entity->getDirection()));
}

