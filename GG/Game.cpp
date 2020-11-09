#include "Game.h"



//Static function


//Initializer function
void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");

	std::string title = "GG";
	sf::VideoMode window_bounds(1440, 810);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;


	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	this->window=new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

void Game::initStates()
{
	this->states.push(new GameState(this->window));
}


//Constructors/Destructors
Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game() 
{
	delete this->window;

	while (this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
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

	if (this->states.empty())
		this->states.top()->update(this->dt);
}

void Game::render()
{
	this->window->clear();
	
	//Render items
	if (this->states.empty())
		this->states.top()->render();

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
