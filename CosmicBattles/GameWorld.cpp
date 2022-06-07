#include "GameWorld.h"
#include "Entity.h"
#include <iostream>
#include "GameInstance.h"
#include "BulletFactory.h"
#include <memory>
#include "ShipFactory.h"

void GameWorld::init()
{
	m_bullet_manager = std::make_unique<BulletFactory>();
	
	m_ship_manager = std::make_unique<ShipFactory>();
	m_entities.push_front(m_ship_manager->createEntity(sf::Vector2f(1200.f, 600.f)));
}

void GameWorld::onFactoryNotify(Entity* in_entity)
{
	if (!m_bullet_manager.get())
	{
		return;
	}
	m_entities.push_front(m_bullet_manager->createEntity(in_entity->getPosition(), in_entity->getDirection()));
}

void GameWorld::checkCollision(Entity* in_entity)
{
	for (auto itr = m_entities.cbegin(); itr != m_entities.cend(); ++itr)
	{
		if (in_entity == itr->get())
		{
			continue;
		}

		// process entity intersection
		if (in_entity->getEntityBounds().intersects(itr->get()->getEntityBounds()))
		{
			in_entity->onHit(*itr->get());
			break;
		}

		// process borders intersection
	}
}

