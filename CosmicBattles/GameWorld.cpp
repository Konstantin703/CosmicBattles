#include "GameWorld.h"

GameWorld* GameWorld::instance_ = nullptr;

GameWorld& GameWorld::getInstance()
{
	if (instance_ == nullptr)
	{
		instance_ = new GameWorld();
	}
	return *instance_;
}

//bool GameWorld::isOnBoarder(const sf::Vector2f& in_vector) const
//{
//	return in_vector.x <= 0.f || in_vector.x >= X_BOARDER || in_vector.y <= 0.f || in_vector.y >= Y_BOARDER;
//}