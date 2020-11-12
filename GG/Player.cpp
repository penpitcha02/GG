#include "Player.h"

//Initializer functions
void Player::initVariables()
{
}

void Player::initComponents()
{
	
}

//Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet) 
{
	this->initVariables();
	
	this->setPosition(x, y);

	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 0, 5, 0, 475, 475);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 0, 1, 3, 1, 475, 475);

}

Player::~Player()
{
}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	if (this->movementComponent->getState(IDLE))
		this->animationComponent->play("IDLE_RIGHT", dt);
	else if(this->movementComponent->getState(MOVING_RIGHT))
		this->animationComponent->play("WALK_RIGHT", dt);
}
