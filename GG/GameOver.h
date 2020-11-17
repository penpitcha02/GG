#ifndef GAMEOVER_H
#define GAMEOVER_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

#include "Button.h"

class GameOver
{
private:
	sf::Text gameOverText;
	sf::Font font;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, Button*> buttons;

public:
	GameOver(sf::RenderWindow& window);
	virtual ~GameOver();

	//Accessor
	std::map<std::string, Button*>& getButtons();
	void setPosition(float x, float y);
	void textSetPosition(float x, float y);
	void buttonSetPosition(const std::string key, float x, float y);

	//Functions
	const bool isButtonPressed(const std::string key);
	void addButton(const std::string key, sf::Texture* idle, sf::Texture* hover, sf::Texture* active);
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget& target);
};
#endif