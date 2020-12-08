#ifndef ENTITY_H
#define ENTITY_H

#include "HitboxComponent.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

class Entity
{
private:
	void initVariables();

protected:

	sf::Sprite sprite;
	sf::Sound sound;

	HitboxComponent* hitboxComponent;
	HitboxComponent* cutboxComponent;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;

public:
	Entity();
	virtual ~Entity();

	//Component functions
	void setTexture(sf::Texture& texture);
	void setBuffer(sf::SoundBuffer& buffer);
	void createHitboxComponent(sf::Sprite& sprite, 
		float offset_x, float offset_y,
		float width, float height);
	void createCutboxComponent(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);

	//Accessor
	const sf::FloatRect getBounds() const;

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float dir_x, const float dir_y, const float& dt);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};
#endif
