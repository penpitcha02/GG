#include "Boss.h"

//Initializer functions
void Boss::initVariables()
{
	this->attacking = false;

	this->hpMax = 1000;
	this->hp = this->hpMax;
	this->damage = 50;
	this->points = 100;

	this->attackCooldownMax = 50.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Boss::initComponents()
{

}


//Constructors / Destructors
Boss::Boss(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 85.f, 85.f, 120.f, 250.f);

	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE", 5.f, 0, 0, 0, 0, 300, 400);
	this->animationComponent->addAnimation("ATTACK", 20.f, 0, 1, 3, 1, 300, 400);
	this->animationComponent->addAnimation("DIE", 5.f, 0, 2, 0, 2, 300, 400);
}

Boss::~Boss()
{
}

//Accessor
const sf::FloatRect Boss::HitboxgetBounds() const
{
	return this->hitboxComponent->getBounds();
}

const int& Boss::getPoints() const
{
	return this->points;
}

const int& Boss::getDamage() const
{
	return this->damage;
}

const int& Boss::getHp() const
{
	return this->hp;
}

const int& Boss::getHpMax() const
{
	return this->hpMax;
}

//Modifier 
void Boss::setHp(const int hp)
{
	this->hp = hp;
}

void Boss::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

//Functions
const bool Boss::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Boss::updateCoolDown()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 1.f;
	}
}

void Boss::updateAttack()
{
	if (canAttack())
	{
		this->attacking = true;
	}
}

void Boss::updateAnimation(const float& dt)
{
	if (this->hp > 0)
	{
		this->animationComponent->play("ATTACK", dt);
	}
	else
	{
		this->animationComponent->play("DIE", dt);
	}
}

void Boss::update(const float& dt)
{
	this->updateCoolDown();

	this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();
}
