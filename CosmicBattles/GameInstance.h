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
	using SpriteVector = std::vector<std::unique_ptr<sf::Sprite>>;
public:
	GameInstance();
	
	void run();
	
private:
	std::string m_game_name = "CosmicBattles";

	sf::RenderWindow m_window;
	SpriteVector m_background;
	std::unique_ptr<GameWorld> m_world;

	std::unique_ptr<ShipController> m_player_controller;

	void processInput();
	void update(float delta_time);
	void render();

	void InitializeBackground();
};
#endif

