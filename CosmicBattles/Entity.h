#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics.hpp"
#include <memory>
#include "SFML/Graphics/Texture.hpp"

enum class EntityType
{
	ET_Ship,
	ET_Asteroid,
	ET_Bullet,
	None
};

class Entity
{
public:
	Entity(const sf::Texture& in_texture, const sf::Vector2f& in_position = sf::Vector2f(), const float in_direction = 0.f)
		: m_sprite{ std::make_unique<sf::Sprite>(in_texture) }
		, m_position{ in_position }
		, m_direction{ in_direction }
	{
		m_sprite->setPosition(m_position);
		m_sprite->setRotation(m_direction);
		m_sprite->setOrigin((in_texture.getSize().x / 2), (in_texture.getSize().y / 2));
	}

	virtual ~Entity() = default;

	// virtual method to override in child classes
	virtual void update(float in_delta_time) = 0;

	sf::Drawable& getDrawable() const { return *m_sprite.get(); }
	sf::FloatRect getEntityBounds() const { return m_sprite->getGlobalBounds(); }

	inline void setPosition(const sf::Vector2f& in_position) { m_position = in_position; }
	inline sf::Vector2f getPosition() const { return m_position; }

	inline void setDirection(const float in_direction) { m_direction = in_direction; }
	inline float getDirection() const { return m_direction; }

	inline void setRemove() { m_should_remove = true; }
	inline bool shouldRemove() const { return m_should_remove == true; }

	inline EntityType getEntityType() const { return m_type; }

protected:
	bool m_should_remove = false;

	std::unique_ptr<sf::Sprite> m_sprite;
	sf::Vector2f m_position;
	float m_direction;
	EntityType m_type = EntityType::None;

};
#endif 
