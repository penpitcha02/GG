#include "Player.h"

//Initializer functions
void Player::initVariables()
{
	this->attacking = false;
}

void Player::initComponents()
{
	
}


//Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet) 
{
	this->initVariables();

	this->setPosition(x, y);
	this->getPosition();

	this->createHitboxComponent(this->sprite, 10.f, 10.f, 430.f, 500.f);
	this->createMovementComponent(150.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 5, 0, 475, 475);
	this->animationComponent->addAnimation("WALK", 10.f, 0, 1, 3, 1, 475, 475);
	this->animationComponent->addAnimation("ATTACK", 7.f, 0, 2, 5, 2, 475, 500);
}

Player::~Player()
{
}


void Player::updateAttack()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->attacking = true;
	}
}

void Player::updateAnimation(const float& dt)
{
	if (this->attacking)
	{
		if (this->animationComponent->play("ATTACK", dt, true))
		{
			this->attacking = false;
		}
	}

	if (this->movementComponent->getState(IDLE))
		this->animationComponent->play("IDLE", dt);
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->sprite.setOrigin(0.f, 0.f);
		this->sprite.setScale(1.f, 1.f);
		this->animationComponent->play("WALK", dt);
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->sprite.setOrigin(450.f, 0.f);
		this->sprite.setScale(-1.f, 1.f);
		this->animationComponent->play("WALK", dt);
	}
}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();

}
