#include "UltiDragon.h"

//Variables
void UltiDragon::initVariables()
{
	this->speed = 10.f;
	this->damage = 50;

	this->attackCooldownMax = 50.f;
	this->attackCooldown = this->attackCooldownMax;
}

//Con-De
UltiDragon::UltiDragon(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 200.f, 500.f, 1000.f, 200.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("FLY", 15.f, 0, 0, 1, 0, 1920, 1080);
}

UltiDragon::~UltiDragon()
{
}

void UltiDragon::SetScale(float x, float y)
{
	return sprite.setScale(x, y);
}

//Accessor
const sf::FloatRect UltiDragon::getBounds() const
{
	return this->hitboxComponent->getBounds();
}

const int& UltiDragon::getDamage() const
{
	return this->damage;
}

//Functions
const bool UltiDragon::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void UltiDragon::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 10.f;
	}
}

void UltiDragon::moveLeft()
{
	this->sprite.move(-this->speed, 0.f);
}

void UltiDragon::moveRight()
{
	this->sprite.move(this->speed, 0.f);
}

void UltiDragon::leftHitbox()
{
	this->hitboxComponent->setScale(-1.f, 1.f);
	this->hitboxComponent->setPosition(this->sprite.getPosition().x - 200.f, this->sprite.getPosition().y + 500.f);
}

void UltiDragon::rightHitbox()
{
	this->hitboxComponent->setScale(1.f, 1.f);
}

void UltiDragon::updateAnimation(const float& dt)
{
	this->animationComponent->play("FLY", dt);
}

void UltiDragon::update(const float& dt)
{
	this->updateAttack();

	this->updateAnimation(dt);

	this->hitboxComponent->update();
}
