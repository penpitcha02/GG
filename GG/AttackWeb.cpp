#include "AttackWeb.h"

//Variables
void AttackWeb::initVariables()
{
	this->speed = 1.f;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->damage = 5;
	this->points = 5;

	this->attackCooldownMax = 50.f;
	this->attackCooldown = this->attackCooldownMax;
}

//Con-De
AttackWeb::AttackWeb(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 70.f, 60.f, 110.f, 130.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("WALK", 10.f, 0, 0, 0, 0, 316, 210);
}

AttackWeb::~AttackWeb()
{
}

//Accessor
const sf::FloatRect AttackWeb::getBounds() const
{
	return this->hitboxComponent->getBounds();
}

const int& AttackWeb::getPoints() const
{
	return this->points;
}

const int& AttackWeb::getDamage() const
{
	return this->damage;
}

const int& AttackWeb::getHp() const
{
	return this->hp;
}

const int& AttackWeb::getHpMax() const
{
	return this->hpMax;
}

//Modifier
void AttackWeb::setHp(const int hp)
{
	this->hp = hp;
}

void AttackWeb::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

//Functions
const bool AttackWeb::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void AttackWeb::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}

void AttackWeb::attackwebBackLeft()
{
	this->sprite.move(-this->speed, 0.f);
}

void AttackWeb::attackwebBackRight()
{
	this->sprite.move(this->speed, 0.f);
}

void AttackWeb::updateAnimation(const float& dt)
{
	this->animationComponent->play("WALK", dt);
}

void AttackWeb::update(const float& dt)
{
	this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();
}



