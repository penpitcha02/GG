#include "Coconut.h"

void Coconut::initVariables()
{
	this->type		= 0;
	this->speed		= 10.f;
	this->hpMax		= 10;
	this->hp		= 0;
	this->damage	= 1;
	this->points	= 5;
}

void Coconut::initCoconut()
{
	this->coconut.setRadius(50.f);
	this->coconut.setOutlineThickness(1.f);
	this->coconut.setOutlineColor(sf::Color::Green);
	if (!this->coconutTexture.loadFromFile("img/Coconut1.png"))
	{
		printf("LOAD COCONUT MAI DAI AAAAAAA");
	}
	this->coconut.setTexture(&this->coconutTexture);
}

Coconut::Coconut(float pos_x, float pos_y)
{
	this->initCoconut();
	this->initVariables();

	this->coconut.setPosition(pos_x, pos_y);
}

Coconut::~Coconut()
{
}


//Accessors
const sf::FloatRect Coconut::getBounds() const
{
	return this->coconut.getGlobalBounds();
}

const int& Coconut::getPoints() const
{
	return this->points;
}

const int& Coconut::getDamage() const
{
	return this->damage;
}



//Functions
void Coconut::update()
{
	this->coconut.move(0.f, this->speed);
}

void Coconut::render(sf::RenderTarget* target)
{
	target->draw(this->coconut);
}
