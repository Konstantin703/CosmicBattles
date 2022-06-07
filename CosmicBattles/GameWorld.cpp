#include "GameWorld.h"
#include "Entity.h"
#include <iostream>
#include "GameInstance.h"
#include "BulletFactory.h"
#include <memory>
#include "ShipFactory.h"
#include <utility>
#include "AsteroidManager.h"
#include "MathLibrary.h"

void GameWorld::init()
{
	m_factories.insert(std::make_pair(static_cast<int>(EntityType::ET_Bullet), std::make_unique<BulletFactory>()));
	m_factories.insert(std::make_pair(static_cast<int>(EntityType::ET_Asteroid), std::make_unique<AsteroidManager>()));
	
	std::unique_ptr<BaseFactory> ship_factory = std::make_unique<ShipFactory>();
	m_entities.push_front(ship_factory->createEntity(sf::Vector2f(1200.f, 600.f)));

	m_factories.insert(std::make_pair(static_cast<int>(EntityType::ET_Ship), std::move(ship_factory)));
}

void GameWorld::update(float in_delta_time)
{
	// for asteroids spawning 
	m_current_spawn_time += in_delta_time;
	if (m_current_spawn_time > m_max_spawn_time)
	{
		sf::Vector2f ship_loc;

		auto itr = std::find_if(m_entities.cbegin(), m_entities.cend(),
			[](std::unique_ptr<Entity> const & entity) { return entity->getEntityType() == EntityType::ET_Ship; });
		if (itr != m_entities.cend())
		{
			ship_loc = itr->get()->getPosition();
		}

		auto factory = m_factories.find(static_cast<int>(EntityType::ET_Asteroid));
		sf::Vector2f start = static_cast<AsteroidManager*>(factory->second.get())->getRandomPosition();

		std::unique_ptr<Entity> entity = factory->second.get()->createEntity(start, MathLibrary::calculateAngle(start, ship_loc));
		entity->subscribe(this);
		m_entities.push_front(std::move(entity));

		m_current_spawn_time = 0.f;
	}
}

void GameWorld::onNotify(const Entity& in_entity)
{
	switch (in_entity.getEntityType())
	{
	case EntityType::ET_Ship:
		m_entities.push_front(
			m_factories.find(
				static_cast<int>(EntityType::ET_Bullet))->second.get()->createEntity(
					in_entity.getPosition(), in_entity.getDirection()
				)
		);
		break;
	case EntityType::ET_Asteroid:
		m_entities.push_front(
			m_factories.find(
				static_cast<int>(EntityType::ET_Asteroid))->second.get()->createEntity(
					in_entity.getPosition(), in_entity.getDirection()
				)
		);
		break;
	}
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

