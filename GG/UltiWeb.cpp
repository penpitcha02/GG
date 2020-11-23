#include "UltiWeb.h"

//Variables
void UltiWeb::initVariables()
{
	this->speed = 3.f;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->damage = 5;
	this->points = 5;

	this->attackCooldownMax = 50.f;
	this->attackCooldown = this->attackCooldownMax;
}

//Con-De
UltiWeb::UltiWeb(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 70.f, 60.f, 110.f, 130.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("WALK", 10.f, 0, 0, 0, 0, 303, 182);
}

UltiWeb::~UltiWeb()
{
}

//Accessor
const sf::FloatRect UltiWeb::getBounds() const
{
	return this->hitboxComponent->getBounds();
}

const int& UltiWeb::getPoints() const
{
	return this->points;
}

const int& UltiWeb::getDamage() const
{
	return this->damage;
}

const int& UltiWeb::getHp() const
{
	return this->hp;
}

const int& UltiWeb::getHpMax() const
{
	return this->hpMax;
}

//Modifier
void UltiWeb::setHp(const int hp)
{
	this->hp = hp;
}

void UltiWeb::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

//Functions
const bool UltiWeb::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void UltiWeb::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}

void UltiWeb::attackwebBackLeft()
{
	this->sprite.move(-this->speed, 0.f);
}

void UltiWeb::attackwebBackRight()
{
	this->sprite.move(this->speed, 0.f);
}

void UltiWeb::updateAnimation(const float& dt)
{
	this->animationComponent->play("WALK", dt);
}

void UltiWeb::update(const float& dt)
{
	this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();
}
