#include "GameState.h"

//Initializer functions
void GameState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
}

void GameState::initTexture()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("img/3-1.png"))
	{
		printf("LOAD PLAYER IDLE MAI DAIIII");
	}

	if (!this->backgroundTexture.loadFromFile("img/Gamebg.png"))
	{
		printf("LOAD MENU BACKGROUND MAI DAI AAAAAAA");
	}

	if (!this->shopTexture.loadFromFile("img/Shop.png"))
	{
		printf("LOAD MENU BACKGROUND MAI DAI AAAAAAA");
	}
}

void GameState::initBackground()
{
	this->background.setSize(sf::Vector2f(4320.f, 810.f));
	this->background.setTexture(&this->backgroundTexture);

	this->shop.setSize(sf::Vector2f(4320.f, 810.f));
	this->shop.setTexture(&this->shopTexture);
}

void GameState::initPlayers()
{
	this->player = new Player(0, 0, this->textures["PLAYER_SHEET"]); 
}


//Constructors / Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTexture();
	this->initBackground();
	this->initPlayers();
}

GameState::~GameState()
{
	delete this->player;
}


void GameState::updateInput(const float& dt)
{

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();

	this->updateInput(dt);

	this->player->update(dt);


}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->player->render(*target);

	target->draw(this->shop);
}
