#ifndef GAME_INSTANCE_H
#define GAME_INSTANCE_H

#include "SFML/Graphics.hpp"

#include "BaseFactory.h"
#include "BulletBase.h"
#include "Ship.h"

#include <memory>
#include <string>
#include <forward_list>

class GameInstance
{
	using SpriteVector = std::vector<std::unique_ptr<sf::Sprite>>;
	using EntityList = std::forward_list<std::unique_ptr<Entity>>;
public:
	GameInstance();
	
	void run();
	
private:
	std::string m_game_name = "CosmicBattles";

	sf::RenderWindow m_window;
	SpriteVector m_background;

	std::unique_ptr<BaseFactory> m_asteroid_manager;
	std::unique_ptr<BaseFactory> m_ship_manager;
	std::unique_ptr<BaseFactory> m_bullet_manager;

	EntityList m_entities;

	void processInput();
	void update(float delta_time);
	void render();

	void initializeBackground();
};
#endif

