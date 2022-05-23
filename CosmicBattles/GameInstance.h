#ifndef GAME_INSTANCE_H
#define GAME_INSTANCE_H

#include "SFML/Graphics.hpp"

#include "BaseFactory.h"
#include "BulletBase.h"
#include "Ship.h"

#include <memory>
#include <string>
#include <forward_list>
#include "AsteroidManager.h"


class GameInstance
{
	using SpriteVector = std::vector<std::unique_ptr<sf::Sprite>>;

public:
	GameInstance();
	
	void run();
	
private:
	std::string m_game_name = "CosmicBattles";

	sf::RenderWindow m_window;
	SpriteVector m_background;

	std::unique_ptr<ShipController> m_controller;
	std::unique_ptr<GameWorld> m_world;
	std::unique_ptr<AsteroidManager> m_asteroid_manager;

	void processInput();
	void update(float delta_time);
	void render();

	void initializeBackground();
};
#endif

