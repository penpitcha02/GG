#include "HowToState.h"

//Initializer functions
void HowToState::initVariable()
{

}

void HowToState::initBackground()
{
	//Background
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("img/Howtoplay.png"))
	{
		printf("LOAD MENU BACKGROUND MAI DAI AAAAAAA");
	}

	this->background.setTexture(&this->backgroundTexture);

}

void HowToState::initView()
{
	this->view.setSize(sf::Vector2f(1440.0f, 810.0f));
}

void HowToState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
}

HowToState::HowToState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariable();
	this->initBackground();
	this->initView();
	this->initKeybinds();
}

HowToState::~HowToState()
{
	
}


void HowToState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->endState();
	}
}

void HowToState::updateView()
{
	this->view.setCenter(sf::Vector2f(720.0f, 405.0f));
}

void HowToState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateView();
}

void HowToState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->setView(this->view);

	target->draw(this->background);
}
