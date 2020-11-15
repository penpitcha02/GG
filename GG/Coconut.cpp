#include "Coconut.h"

//Variables
void Coconut::initVariables()
{
	this->type = 0;
	this->speed = 4.f;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->damage = 1;
	this->points = 5;
}

//Con-De
Coconut::Coconut(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 32.f, 35.f, 65.f, 70.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("FLY", 10.f, 0, 0, 1, 0, 126.f, 114.f);
}

Coconut::~Coconut()
{
}

//Accessor
const sf::FloatRect Coconut::getBounds() const
{
	return this->hitboxComponent->getBounds();
}

const int& Coconut::getPoints() const
{
	return this->points;
}

const int& Coconut::getDamage() const
{
	return this->damage;
}

const int& Coconut::getHp() const
{
	return this->hp;
}

const int& Coconut::getHpMax() const
{
	return this->hpMax;
}

void Coconut::setHp(const int hp)
{
	this->hp = hp;
}

void Coconut::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

//Functions

void Coconut::coconutBackLeft()
{
	this->sprite.move(-this->speed, 0.f);
}

void Coconut::coconutBackRight()
{
	this->sprite.move(this->speed, 0.f);
}

void Coconut::coconutBackUp()
{
	this->sprite.move(0.f, -this->speed);
}

void Coconut::coconutBackDown()
{
	this->sprite.move(0.f, this->speed);
}

void Coconut::updateAnimation(const float& dt)
{
	this->animationComponent->play("FLY", dt);
}

void Coconut::update(const float& dt)
{

	this->updateAnimation(dt);

	this->hitboxComponent->update();
}



