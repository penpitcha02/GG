#include "EndGameState.h"

//Initializer functions
void EndGameState::initVariable()
{

}

void EndGameState::initBackground()
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

void EndGameState::initView()
{
	this->view.setSize(sf::Vector2f(1440.0f, 810.0f));
}

void EndGameState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
}

void EndGameState::initButton()
{
	////Button1
	//if (!this->button1idleTexture.loadFromFile("img/menubutton/PlayButton1.png"))
	//	printf("LOAD BUTTON 1 IDLE MAI DAI AAAAAAA");

	//if (!this->button1hoverTexture.loadFromFile("img/menubutton/PlayButtonHighlight1.png"))
	//	printf("LOAD BUTTON 1 HOVER MAI DAI AAAAAAA");

	//if (!this->button1activeTexture.loadFromFile("img/menubutton/PlayButtonPressed1.png"))
	//	printf("LOAD BUTTON 1 ACTIVE MAI DAI AAAAAAA");

	//this->buttons["GAME_STATE"] = new Button(1050, 200, 172.5, 107.5,
	//	&this->button1idleTexture, &this->button1hoverTexture, &this->button1activeTexture);

	////Button2
	//if (!this->button2idleTexture.loadFromFile("img/menubutton/HelpButton1.png"))
	//	printf("LOAD BUTTON 2 IDLE MAI DAI AAAAAAA");

	//if (!this->button2hoverTexture.loadFromFile("img/menubutton/HelpButtonHighlight1.png"))
	//	printf("LOAD BUTTON 2 HOVER MAI DAI AAAAAAA");

	//if (!this->button2activeTexture.loadFromFile("img/menubutton/HelpButtonPressed1.png"))
	//	printf("LOAD BUTTON 2 ACTIVE MAI DAI AAAAAAA");

	//this->buttons["HELP_STATE"] = new Button(1050, 350, 172.5, 107.5,
	//	&this->button2idleTexture, &this->button2hoverTexture, &this->button2activeTexture);

	//Button3
	if (!this->button3idleTexture.loadFromFile("img/menubutton/QuitButton1.png"))
		printf("LOAD BUTTON 3 IDLE MAI DAI AAAAAAA");

	if (!this->button3hoverTexture.loadFromFile("img/menubutton/QuitButtonHighlight1.png"))
		printf("LOAD BUTTON 3 HOVER MAI DAI AAAAAAA");

	if (!this->button3activeTexture.loadFromFile("img/menubutton/QuitButtonPressed1.png"))
		printf("LOAD BUTTON 3 ACTIVE MAI DAI AAAAAAA");

	this->buttons["QUIT_STATE"] = new Button(1200, 700, 172.5, 107.5,
		&this->button3idleTexture, &this->button3hoverTexture, &this->button3activeTexture);
}

EndGameState::EndGameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariable();
	this->initBackground();
	this->initView();
	this->initKeybinds();
	this->initButton();
}

EndGameState::~EndGameState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}


void EndGameState::updateInput(const float& dt)
{


}

void EndGameState::updateView()
{
	this->view.setCenter(sf::Vector2f(720.0f, 405.0f));
}

void EndGameState::updateButtons()
{
	/*Update all the buttons in the state and handles their functionality*/
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	////New Game
	//if (this->buttons["GAME_STATE"]->isPressed())
	//{
	//	this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	//}

	//Quit The Game
	if (this->buttons["QUIT_STATE"]->isPressed())
	{
		this->endState();
	}
}

void EndGameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateView();

	this->updateButtons();
}

void EndGameState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void EndGameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	
	target->setView(this->view);

	target->draw(this->background);

	target->draw(this->shop);

	target->draw(this->fade);

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
