#include "Player.h"

//Initializer functions
void Player::initVariables()
{
	this->attacking = false;

	this->hpMax = 1000;
	this->hp = this->hpMax;
	this->damage = 1;

	this->attackCooldownMax = 50.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Player::initComponents()
{
	
}


//Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet) 
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 150.f, 85.f, 120.f, 250.f);
	this->createCutboxComponent(this->sprite, 210.f, 60.f, 200.f, 300.f);
	this->createMovementComponent(600.f, 20.f, 10.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 5, 0, 475, 500);
	this->animationComponent->addAnimation("WALK", 10.f, 0, 1, 3, 1, 475, 500);
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

const int& Player::faceLeft() const
{
	return this->movementComponent->getState(MOVING_LEFT);
}

const int& Player::faceRight() const
{
	return this->movementComponent->getState(MOVING_RIGHT);
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

const int& Player::getDamage() const
{
	return this->damage;
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
const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateCoolDown()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 1.f;
	}
}

void Player::updateAttack()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->canAttack())
	{
		this->attacking = true;
	}
}

const bool Player::isAttacking()
{
	if (this->attacking)
	{
		return true;
	}
	return false;
}

void Player::updateCutbox()
{
	this->cutboxComponent->update();

	if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->cutboxComponent->setScale(1.f, 1.f);
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->cutboxComponent->setScale(-1.f, 1.f);
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
		this->animationComponent->play("WALK", dt);
	} 
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->sprite.setOrigin(420.f, 0.f);
		this->sprite.setScale(-1.f, 1.f);
		this->animationComponent->play("WALK", dt);
	}
}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	this->updateCoolDown();

	this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	this->updateCutbox();
}
