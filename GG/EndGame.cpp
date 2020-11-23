#include "EndGame.h"

EndGame::EndGame(sf::RenderWindow& window)
{
	if (!this->endgameTexture.loadFromFile("img/Endgame.png"))
	{
		throw("LOAD MAIDAI KRUB");
	}

	//Init background
	this->background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x * 3), static_cast<float>(window.getSize().y)));
	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	//Init container
	this->endgame.setSize(sf::Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));
	this->endgame.setTexture(&this->endgameTexture);
}

EndGame::~EndGame()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

std::map<std::string, Button*>& EndGame::getButtons()
{
	return this->buttons;
}

void EndGame::setPosition(float x, float y)
{
	return this->endgame.setPosition(sf::Vector2f(x, y));
}

void EndGame::buttonSetPosition(const std::string key, float x, float y)
{
	return this->buttons[key]->setPosition(x, y);
}

//Functions
const bool EndGame::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}

void EndGame::addButton(const std::string key, sf::Texture* idle, sf::Texture* hover, sf::Texture* active)
{
	this->buttons[key] = new Button(0, 0, 172.5, 107.5,
		idle, hover, active);
}

void EndGame::update(const sf::Vector2f& mousePos)
{
	for (auto& i : this->buttons)
	{
		i.second->update(mousePos);
	}
}

void EndGame::render(sf::RenderTarget& target)
{
	target.draw(this->background);
	target.draw(this->endgame);

	for (auto& i : this->buttons)
	{
		i.second->render(target);
	}
}
