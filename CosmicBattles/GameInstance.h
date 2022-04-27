#ifndef GAME_INSTANCE_H
#define GAME_INSTANCE_H

#include "SFML/Graphics.hpp"

#include "BulletBase.h"
#include "ShipController.h"
#include "GameWorld.h"

#include <memory>
#include <string>

class GameInstance
{
public:
	GameInstance();
	
	void run();
	
private:
	const int m_screen_width = 1280;
	const int m_screen_height = 900;
	std::string m_game_name = "CosmicBattles";

	sf::RenderWindow m_window;
	std::unique_ptr<GameWorld> m_world;

	std::unique_ptr<ShipController> m_player_controller;

	void processInput();
	void update(float delta_time);
	void render();
};
#endif

