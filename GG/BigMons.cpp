#include "BigMons.h"

//Variables
void BigMons::initVariables()
{
	this->attacking = false;

	this->type = 0;
	this->speed = 8.f;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->damage = 10;
	this->points = 5;

	this->attackCooldownMax = 50.f;
	this->attackCooldown = this->attackCooldownMax;
}

//Con-De
BigMons::BigMons(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 70.f, 0.f, 60.f, 176.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("WALK", 10.f, 0, 0, 6, 0, 202, 176);
}

BigMons::~BigMons()
{
}

//Accessor
const sf::FloatRect BigMons::getBounds() const
{
	return this->hitboxComponent->getBounds();
}

const int& BigMons::getPoints() const
{
	return this->points;
}

const int& BigMons::getDamage() const
{
	return this->damage;
}

const int& BigMons::getHp() const
{
	return this->hp;
}

const int& BigMons::getHpMax() const
{
	return this->hpMax;
}

void BigMons::setHp(const int hp)
{
	this->hp = hp;
}

void BigMons::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

//Functions
const bool BigMons::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void BigMons::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}

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

void BigMons::updateAnimation(const float& dt)
{
	this->animationComponent->play("WALK", dt);
}

void BigMons::update(const float& dt)
{
	this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();
}



