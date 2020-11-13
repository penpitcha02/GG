#include "Player.h"

//Initializer functions
void Player::initVariables()
{
	this->attacking = false;

	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player::initComponents()
{
	
}


//Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet) 
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 100.f, 80.f, 200.f, 300.f);
	this->createCutboxComponent(this->sprite, 100.f, 80.f, 300.f, 300.f);
	this->createMovementComponent(600.f, 20.f, 10.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 5, 0, 475, 500);
	this->animationComponent->addAnimation("WALKLEFTRIGHT", 10.f, 0, 1, 3, 1, 475, 500);
	//this->animationComponent->addAnimation("WALKUP", 10.f, 0, 4, 3, 4, 475, 500);
	//this->animationComponent->addAnimation("WALKDOWN", 10.f, 0, 3, 3, 3, 475, 500);
	this->animationComponent->addAnimation("ATTACK", 5.f, 0, 2, 5, 2, 475, 500);
}

Player::~Player()
{
}

//Accessor
const sf::FloatRect Player::HitboxgetBounds() const
{
	return this->hitboxComponent->getBounds();
}

const sf::FloatRect Player::CutboxgetBounds() const
{
	return this->cutboxComponent->getBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}


//Modifier
void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

//Functions
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
	{
		this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->sprite.setOrigin(0.f, 0.f);
		this->sprite.setScale(1.f, 1.f);
		this->animationComponent->play("WALKLEFTRIGHT", dt);
	} 
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->sprite.setOrigin(450.f, 0.f);
		this->sprite.setScale(-1.f, 1.f);
		this->animationComponent->play("WALKLEFTRIGHT", dt);
	}
}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	this->cutboxComponent->update();

}
