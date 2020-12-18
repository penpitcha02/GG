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

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);

	auto image = sf::Image{};
	if (!image.loadFromFile("img/icon.png"))
	{
		printf_s("ERROR::GAME::ICON");
	}

	this->window->setIcon(1858, 1858, image.getPixelsPtr());
}

void Game::initKeys()
{
	this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
	this->supportedKeys["A"] = sf::Keyboard::Key::A;
	this->supportedKeys["D"] = sf::Keyboard::Key::D;
	this->supportedKeys["W"] = sf::Keyboard::Key::W;
	this->supportedKeys["S"] = sf::Keyboard::Key::S;
	this->supportedKeys["Space"] = sf::Keyboard::Key::Space;
	this->supportedKeys["Q"] = sf::Keyboard::Key::Q;
	this->supportedKeys["E"] = sf::Keyboard::Key::E;

	//DEBUG REMOVE LATER!
	for (auto i : this->supportedKeys)
	{
		std::cout << i.first << "" << i.second << "\n";
	}
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}



//Constructors/Destructors
Game::Game()
{
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Game::~Game() 
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}


//Function
void Game::endApplication()
{
	std::cout << "Ending Application" << "\n";
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

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

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Application end
	else
	{
		this->endApplication();
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();
	
	//Render items
	if (!this->states.empty())
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
