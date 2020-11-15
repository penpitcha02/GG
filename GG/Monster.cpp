#include "Monster.h"

//Variables
void Monster::initVariables()
{
	this->type = 0;
	this->speed = 8.f;
	this->hpMax = 10;
	this->hp = 0;
	this->damage = 1;
	this->points = 5;
}

//Initializaer functions
void Monster::initMonster()
{
	this->monster.setRadius(50.f);
	this->monster.setOutlineThickness(1.f);
	this->monster.setOutlineColor(sf::Color::Green);
	if (!this->monsterTexture.loadFromFile("img/Coconut1.png"))
	{
		printf("LOAD COCONUT MAI DAI AAAAAAA");
	}
	this->monster.setTexture(&this->monsterTexture);
}

//Con-De
Monster::Monster(float pos_x, float pos_y)
{
	this->initMonster();
	this->initVariables();

	this->monster.setPosition(pos_x, pos_y);
}

Monster::~Monster()
{
}

//Accessors
const sf::FloatRect Monster::getBounds() const
{
	return this->monster.getGlobalBounds();
}

const int& Monster::getPoints() const
{
	return this->points;
}

const int& Monster::getDamage() const
{
	return this->damage;
}

//Functions
void Monster::monsterBackLeft()
{
	this->monster.move(-this->speed, 0.f);
}

void Monster::monsterBackRight()
{
	this->monster.move(this->speed, 0.f);
}

void Monster::monsterBackUp()
{
	this->monster.move(0.f, -this->speed);
}

void Monster::monsterBackDown()
{
	this->monster.move(0.f, this->speed);
}

void Monster::render(sf::RenderTarget* target)
{
	target->draw(this->monster);
}
