#include "Coconut.h"

void Coconut::initCoconut()
{
	this->coconut.setRadius(50.f);
}

void Coconut::initVariables()
{
	this->type		= 0;
	this->speed		= 10.f;
	this->hpMax		= 10;
	this->hp		= 0;
	this->damage	= 1;
	this->points	= 5;
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



//Functions
void Coconut::update()
{
	this->coconut.move(0.f, this->speed);
}

void Coconut::render(sf::RenderTarget* target)
{
	target->draw(this->coconut);
}
