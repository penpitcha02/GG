#include "RankState.h"

//Initializer functions
void RankState::initVariable()
{

}

void RankState::initMusic()
{
	if (!this->music.openFromFile("music/Gurenge.wav"))
		printf("LOAD MAI DAI AAAAAAA");
	this->music.play();
	this->music.setLoop(true);
}

void RankState::initBackground()
{
	//Background
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("img/Endgamebg.png"))
	{
		printf("LOAD MENU BACKGROUND MAI DAI AAAAAAA");
	}

	this->background.setTexture(&this->backgroundTexture);

	//Shop
	this->shop.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x*2),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->shopTexture.loadFromFile("img/Shop.png"))
	{
		printf("LOAD MENU BACKGROUND MAI DAI AAAAAAA");
	}

	this->shop.setTexture(&this->shopTexture);

	this->shop.setPosition(-500.f, 0.f);

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

void RankState::initName()
{
	if (!this->font.loadFromFile("font/maaja.ttf"))
	{
		throw("LOAD MAIDAI KRUB");
	}

	//Name
	this->nameText.setFont(this->font);
	this->nameText.setCharacterSize(50);
	this->nameText.setFillColor(sf::Color::White);
	this->nameText.setPosition(25.f, 725.f);
	this->nameText.setString("Penpitcha Sappakun 63010709");
}

void RankState::initView()
{
	this->view.setSize(sf::Vector2f(1440.0f, 810.0f));
}

void RankState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
}

void RankState::initButton()
{
	if (!this->button3idleTexture.loadFromFile("img/menubutton/QuitButton1.png"))
		printf("LOAD BUTTON 3 IDLE MAI DAI AAAAAAA");

	if (!this->button3hoverTexture.loadFromFile("img/menubutton/QuitButtonHighlight1.png"))
		printf("LOAD BUTTON 3 HOVER MAI DAI AAAAAAA");

	if (!this->button3activeTexture.loadFromFile("img/menubutton/QuitButtonPressed1.png"))
		printf("LOAD BUTTON 3 ACTIVE MAI DAI AAAAAAA");

	this->buttons["QUIT_STATE"] = new Button(1200, 650, 172.5, 107.5,
		&this->button3idleTexture, &this->button3hoverTexture, &this->button3activeTexture);
}

RankState::RankState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariable();
	this->initMusic();
	this->initBackground();
	this->initName();
	this->initView();
	this->initKeybinds();
	this->initButton();
}

RankState::~RankState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}


void RankState::updateInput(const float& dt)
{


}

void RankState::updateView()
{
	this->view.setCenter(sf::Vector2f(720.0f, 405.0f));
}

void RankState::updateButtons()
{
	/*Update all the buttons in the state and handles their functionality*/
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//Quit The Game
	if (this->buttons["QUIT_STATE"]->isPressed())
	{
		this->music.stop();
		this->states->push(new MainMenuState(this->window, this->supportedKeys, this->states));
		this->endState();
	}
}

void RankState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateView();

	this->updateButtons();
}

void RankState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void RankState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	
	target->setView(this->view);

	target->draw(this->background);

	target->draw(this->shop);

	target->draw(this->fade);

	target->draw(this->nameText);

	this->renderButtons(*target);

	//REMOVE LATER!
	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);*/
}
