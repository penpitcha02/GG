#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow& window)
{
	if (!this->font.loadFromFile("font/maaja.ttf"))
	{
		throw("LOAD MAIDAI KRUB");
	}

	//Init game over text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(150);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Don't Cry Na");

	//Init background
	this->background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x * 3), static_cast<float>(window.getSize().y)));
	this->background.setFillColor(sf::Color(20, 20, 20, 200));

	//Init container
	/*this->container.setSize(sf::Vector2f(static_cast<float>(window.getSize().x) / 4.f, static_cast<float>(window.getSize().y)));
	this->container.setFillColor(sf::Color(20, 20, 20, 200));*/
}

GameOver::~GameOver()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

std::map<std::string, Button*>& GameOver::getButtons()
{
	return this->buttons;
}

void GameOver::textSetPosition(float x, float y)
{
	return this->gameOverText.setPosition(sf::Vector2f(x, y));
}

void GameOver::buttonSetPosition(const std::string key, float x, float y)
{
	return this->buttons[key]->setPosition(x, y);
}

//Functions
const bool GameOver::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}

void GameOver::addButton(const std::string key, sf::Texture* idle, sf::Texture* hover, sf::Texture* active)
{
	this->buttons[key] = new Button(0, 0, 172.5, 107.5,
		idle, hover, active);
}

void GameOver::update(const sf::Vector2f& mousePos)
{
	for (auto& i : this->buttons)
	{
		i.second->update(mousePos);
	}
}

void GameOver::render(sf::RenderTarget& target)
{
	target.draw(this->background);

	for (auto& i : this->buttons)
	{
		i.second->render(target);
	}

	target.draw(this->gameOverText);
}
