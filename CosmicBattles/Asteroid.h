#ifndef ASTERIOD_H
#define ASTERIOD_H

#include "Entity.h"

enum class AsteroidSize
{
	AS_Large,
	AS_Medium,
	None
};

class Asteroid : public Entity
{
public:
	Asteroid(const sf::Texture& in_texture, const sf::Vector2f& in_position = sf::Vector2f(), const float in_direction = 0.f);
	virtual ~Asteroid() = default;

	void update(float in_delta_time) override;

	inline AsteroidSize getAsteroidSize() const { return m_size; }
	inline void setAsteroidSize(AsteroidSize in_size) { m_size = in_size; }

	void onHit(const Entity& in_entity) override;
	
private:
	AsteroidSize m_size = AsteroidSize::None;
};

#endif // ASTERIOD_H
