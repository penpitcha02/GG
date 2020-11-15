#include "BigMons.h"

//Variables
void BigMons::initVariables()
{
	this->attacking = false;

	this->type = 0;
	this->speed = 8.f;
	this->hpMax = 10;
	this->hp = 0;
	this->damage = 1;
	this->points = 5;
}

//Con-De
BigMons::BigMons(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("WALKLEFTRIGHT", 10.f, 0, 1, 3, 1, 475, 500);
	this->animationComponent->addAnimation("ATTACK", 5.f, 0, 2, 5, 2, 475, 500);
}

BigMons::~BigMons()
{
}

//Accessor
const sf::FloatRect BigMons::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& BigMons::getPoints() const
{
	return this->points;
}

const int& BigMons::getDamage() const
{
	return this->damage;
}

//Functions

void BigMons::bigmonsBackLeft()
{
	this->sprite.move(-this->speed, 0.f);
}

void BigMons::bigmonsBackRight()
{
	this->sprite.move(this->speed, 0.f);
}

void BigMons::bigmonsBackUp()
{
	this->sprite.move(0.f, -this->speed);
}

void BigMons::bigmonsBackDown()
{
	this->sprite.move(0.f, this->speed);
}

void BigMons::updateAttack(const float& dt)
{
	this->animationComponent->play("ATTACK", dt);
}

void BigMons::updateAnimation(const float& dt)
{
	this->animationComponent->play("WALKLEFTRIGHT", dt);
}

void BigMons::update(const float& dt)
{

	this->updateAttack(dt);

	this->updateAnimation(dt);

}



