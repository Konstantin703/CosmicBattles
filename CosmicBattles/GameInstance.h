#ifndef GAME_INSTANCE_H
#define GAME_INSTANCE_H

#include "SFML/Graphics.hpp"

#include "BulletBase.h"
#include "ShipController.h"

#include <memory>
#include <string>

class GameInstance
{
	using EntityVector = std::vector<std::shared_ptr<Entity>>;
public:
	GameInstance();

	sf::RenderWindow m_window;

	std::unique_ptr<ShipController> m_player_controller;
	
	void run();

	// temporary variable for raw shooting
	//std::unique_ptr<BulletBase> m_bullet;

private:
	const int m_screen_width = 1024;
	const int m_screen_height = 768;
	std::string m_game_name = "CosmicBattles";

	EntityVector m_entities;

	void processInput();
	void update(float delta_time);
	void render();
};
#endif

