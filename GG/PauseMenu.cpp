#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow& window)
{
	//Init background
	this->background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x*3), static_cast<float>(window.getSize().y)));
	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	//Init container
	this->container.setSize(sf::Vector2f(static_cast<float>(window.getSize().x) / 4.f, static_cast<float>(window.getSize().y)));
	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition(static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f, 0.f);

	//Init text
	this->menuText.setFillColor(sf::Color(255, 255, 255, 255));
	this->menuText.setCharacterSize(30);
	this->menuText.setString("Paused");
	this->menuText.setPosition(this->container.getPosition());
}

PauseMenu::~PauseMenu()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

std::map<std::string, Button*>& PauseMenu::getButtons()
{
	return this->buttons;
}



//Functions
const bool PauseMenu::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}

void PauseMenu::addButton(const std::string key, float x, float y, sf::Texture* idle, sf::Texture* hover, sf::Texture* active)
{
	this->buttons[key] = new Button(x, y, 172.5, 107.5,
		idle, hover, active);
}

void PauseMenu::update(const sf::Vector2f& mousePos)
{
	for (auto& i : this->buttons)
	{
		i.second->update(mousePos);
	}
}

void PauseMenu::render(sf::RenderTarget& target)
{
	target.draw(this->background);
	target.draw(this->container);

	for (auto &i : this->buttons)
	{
		i.second->render(target);
	}

	target.draw(this->menuText);
}
