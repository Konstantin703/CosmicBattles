#ifndef ENTITY_H
#define ENTITY_H

/*
* abstract class for drawing, updating game objects on the screen
*/
class Entity
{
public:
	virtual void update(float in_delta_time) = 0;
	virtual sf::Drawable* getDrawable() = 0;
	virtual ~Entity() {};
};

#endif 
