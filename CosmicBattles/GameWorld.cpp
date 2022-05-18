#include "GameWorld.h"
#include "Entity.h"
#include <iostream>
#include "GameInstance.h"
#include "BulletFactory.h"
#include <memory>

GameWorld::GameWorld()
{
	std::cout << "World created " << this << std::endl;
	m_bullet_manager = std::make_unique<BulletFactory>();
}

void GameWorld::onNotify(Entity* in_entity)
{
	
}

void GameWorld::onFactoryNotify(Entity* in_entity)
{

	std::cout << "void GameWorld::onFactoryNotify(Entity* in_entity)" << std::endl;
	m_entities.push_front(m_bullet_manager->createEntity(in_entity->getPosition(), in_entity->getDirection()));
}

