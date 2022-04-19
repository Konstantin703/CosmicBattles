#ifndef GAME_INSTANCE_H
#define GAME_INSTANCE_H

#include "SFML/Graphics.hpp"

#include "Ship.h"

#include <memory>
#include <string>

class GameInstance
{
public:
	GameInstance();

	sf::RenderWindow m_window;

	std::unique_ptr<Ship> m_player;
	
	void run();

private:
	const int m_screen_width = 1024;
	const int m_screen_height = 768;

	std::string m_game_name = "CosmicBattles";

	void processInput();
	void update(float delta_time);
	void render();
};
#endif

