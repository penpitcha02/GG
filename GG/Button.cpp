#include "Button.h"

Button::Button(float x, float y, float width, float height,
	sf::Texture* idleColor, sf::Texture* hoverColor, sf::Texture* activeColor)
{
	this->buttonState = BTN_IDLE;
	
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setTexture(this->idleColor);

	if (!this->soundBuffer.loadFromFile("sfx/hardpop.wav"))
	{
		printf("LOAD sound MAI DAI AAAAAAA");
	}
	this->sound.setBuffer(this->soundBuffer);
}

Button::~Button()
{
}

//Accessors
const bool Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
	{
		return true;
	}

	return false;
}

void Button::setPosition(float x, float y)
{
	return this->shape.setPosition(sf::Vector2f(x, y));
}

//Functions

void Button::update(const sf::Vector2f& mousePos)
{
	/*Update the booleans for hover and pressed*/

	//Idle
	this->buttonState = BTN_IDLE;

	//Hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setTexture(this->idleColor);
		break;

	case BTN_HOVER:
		this->shape.setTexture(this->hoverColor);
		break;

	case BTN_ACTIVE:
		this->shape.setTexture(this->activeColor);
		this->sound.play();
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
