#include "Game.h"



//Static function


//Initializer function
void Game::initWindow()
{
	this->window=new sf::RenderWindow(sf::VideoMode(1440, 810), "SFML works!");
}


//Constructors/Destructors
Game::Game()
{
	this->initWindow();
}

Game::~Game() 
{
	delete this->window;
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

//Function
void Game::updateSFMLEvents()
{

		while (this->window->pollEvent(this->sfEvent))
		{
			if (this->sfEvent.type == sf::Event::Closed)
				this->window->close();
		}

}

void Game::update()
{
	this->updateSFMLEvents();

}

void Game::render()
{
	this->window->clear();
	
	//Render items

	this->window->display();
}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
