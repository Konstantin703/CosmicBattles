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
			// if it is bullet and shouldn't collide with owner
			if (in_entity->getEntityType() == EntityType::ET_Bullet && itr->get()->getEntityType() != EntityType::ET_Ship)
			{
				// TODO: call events 
				// asteroid crushes into smaller parts
				// pick ups appear
				in_entity->setRemove();
				itr->get()->setRemove();
				break;
			}

			// if asteroid collide ship
			// do damage to ship
			if (in_entity->getEntityType() == EntityType::ET_Asteroid && itr->get()->getEntityType() == EntityType::ET_Ship)
			{
				in_entity->setRemove();
				break;
			}
		}

		// process borders intersection
	}
}

