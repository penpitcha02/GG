#include "NameState.h"

//Initializer functions
void NameState::initVariable()
{
	if (!this->font.loadFromFile("font/maaja.ttf"))
	{
		throw("LOAD MAIDAI KRUB");
	}
}

void NameState::initMusic()
{
	if (!this->music.openFromFile("music/Nandemonaiya.wav"))
		printf("LOAD MAI DAI AAAAAAA");
	this->music.play();
	this->music.setLoop(true);
}

void NameState::initBackground()
{
	//Background
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("img/Menu.png"))
	{
		printf("LOAD MENU BACKGROUND MAI DAI AAAAAAA");
	}

	this->background.setTexture(&this->backgroundTexture);

	//Fade
	this->fade.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);
	this->fade.setFillColor(sf::Color(20, 20, 20, 100));
}

void NameState::initView()
{
	this->view.setSize(sf::Vector2f(1440.0f, 810.0f));
}

void NameState::initTextBox()
{
	
}

void NameState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
}

NameState::NameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariable();
	this->initMusic();
	this->initBackground();
	this->initView();
	this->initKeybinds();
}

NameState::~NameState()
{

}


void NameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		this->music.stop();
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
		this->endState();
	}
}

void NameState::updateView()
{
	this->view.setCenter(sf::Vector2f(720.0f, 405.0f));
}

void NameState::updateTextBox()
{
	
}

void NameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateView();
}

void NameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->setView(this->view);

	target->draw(this->background);

	target->draw(this->fade);
}
