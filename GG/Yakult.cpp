#include "Yakult.h"

//Variables
void Yakult::initVariables()
{
	this->heal = 10;
}

//Con-De
Yakult::Yakult(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 65.f, 50.f, 60.f, 150.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("STILL", 10.f, 0, 0, 0, 0, 188.f, 266.f);
}

Yakult::~Yakult()
{
}

//Accessor
const sf::FloatRect Yakult::getBounds() const
{
	return this->hitboxComponent->getBounds();
}

const int& Yakult::getHeal() const
{
	return this->heal;
}

void Yakult::updateAnimation(const float& dt)
{
	this->animationComponent->play("STILL", dt);
}

void Yakult::update(const float& dt)
{

	this->updateAnimation(dt);

	this->hitboxComponent->update();
}