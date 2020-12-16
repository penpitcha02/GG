#include "Monster.h"

//Variables
void Monster::initVariables()
{
	this->speed = 1.5f;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->damage = 5;
	this->points = 10;

	this->attackCooldownMax = 50.f;
	this->attackCooldown = this->attackCooldownMax;
}

//Con-De
Monster::Monster(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 70.f, 60.f, 110.f, 130.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("WALK", 10.f, 0, 0, 1, 0, 234, 264);
}

Monster::~Monster()
{
}

//Accessor
const sf::FloatRect Monster::getBounds() const
{
	return this->hitboxComponent->getBounds();
}

const int& Monster::getPoints() const
{
	return this->points;
}

const int& Monster::getDamage() const
{
	return this->damage;
}

const int& Monster::getHp() const
{
	return this->hp;
}

const int& Monster::getHpMax() const
{
	return this->hpMax;
}

//Modifier
void Monster::setHp(const int hp)
{
	this->hp = hp;
}

void Monster::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

//Functions
const bool Monster::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Monster::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}

void Monster::monsterBackLeft()
{
	this->sprite.move(-this->speed, 0.f);
}

void Monster::monsterBackRight()
{
	this->sprite.move(this->speed, 0.f);
}

void Monster::monsterBackUp()
{
	this->sprite.move(0.f, -this->speed);
}

void Monster::monsterBackDown()
{
	this->sprite.move(0.f, this->speed);
}

void Monster::updateAnimation(const float& dt)
{
	this->animationComponent->play("WALK", dt);
}

void Monster::update(const float& dt)
{
	this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();
}



