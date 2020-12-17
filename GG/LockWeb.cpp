#include "LockWeb.h"

//Variables
void LockWeb::initVariables()
{
	this->speed = 3.f;
	this->hpMax = 4;
	this->hp = this->hpMax;
	this->points = 15;
}

//Con-De
LockWeb::LockWeb(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 0, 0, 210, 367);
}

LockWeb::~LockWeb()
{
}

//Accessor
const sf::FloatRect LockWeb::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& LockWeb::getPoints() const
{
	return this->points;
}

const int& LockWeb::getHp() const
{
	return this->hp;
}

const int& LockWeb::getHpMax() const
{
	return this->hpMax;
}

void LockWeb::setHp(const int hp)
{
	this->hp = hp;
}

void LockWeb::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

//Functions
void LockWeb::updateAnimation(const float& dt)
{
	this->animationComponent->play("IDLE", dt);
}

void LockWeb::update(const float& dt)
{
	this->updateAnimation(dt);
}



