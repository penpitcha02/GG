#include "MainMenuState.h"

//Initializer functions
void MainMenuState::initVariable()
{
	
}

void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("img/MenuBackground.png"))
	{
		throw "LOAD MENU BACKGROUND MAI DAI AAAAAAA";
	}

	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("font/arialbi.ttf"))
	{
		throw("LOAD MAIDAI KRUB");
	}
}

void MainMenuState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
}

void MainMenuState::initButton()
{
	//Button1
	if (!this->button1idleTexture.loadFromFile("img/PlayButton1.png"))
		throw "LOAD BUTTON 1 IDLE MAI DAI AAAAAAA";

	if (!this->button1hoverTexture.loadFromFile("img/PlayButtonHighlight1.png"))
		throw "LOAD BUTTON 1 HOVER MAI DAI AAAAAAA";

	if (!this->button1activeTexture.loadFromFile("img/PlayButtonPressed1.png"))
		throw "LOAD BUTTON 1 ACTIVE MAI DAI AAAAAAA";

	this->buttons["GAME_STATE"] = new Button(1050, 200, 172.5, 107.5,
		&this->font, "New Game",
		&this->button1idleTexture, &this->button1hoverTexture, &this->button1activeTexture);

	//Button2
	if (!this->button2idleTexture.loadFromFile("img/HelpButton1.png"))
		throw "LOAD BUTTON 2 IDLE MAI DAI AAAAAAA";

	if (!this->button2hoverTexture.loadFromFile("img/HelpButtonHighlight1.png"))
		throw "LOAD BUTTON 2 HOVER MAI DAI AAAAAAA";

	if (!this->button2activeTexture.loadFromFile("img/HelpButtonPressed1.png"))
		throw "LOAD BUTTON 2 ACTIVE MAI DAI AAAAAAA";

	this->buttons["Score"] = new Button(1050, 350, 172.5, 107.5,
		&this->font, "Score",
		&this->button2idleTexture, &this->button2hoverTexture, &this->button2activeTexture);

		//Button3
	if (!this->button3idleTexture.loadFromFile("img/QuitButton1.png"))
		throw "LOAD BUTTON 3 IDLE MAI DAI AAAAAAA";

	if (!this->button3hoverTexture.loadFromFile("img/QuitButtonHighlight1.png"))
		throw "LOAD BUTTON 3 HOVER MAI DAI AAAAAAA";

	if (!this->button3activeTexture.loadFromFile("img/QuitButtonPressed1.png"))
		throw "LOAD BUTTON 3 ACTIVE MAI DAI AAAAAAA";

	this->buttons["EXIT_STATE"] = new Button(1050, 550, 172.5, 107.5,
		&this->font, "Quit",
		&this->button3idleTexture, &this->button3hoverTexture, &this->button3activeTexture);
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariable();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButton();
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}


void MainMenuState::endState()
{
	std::cout << "Ending MainMenuState!" << "\n";
}

void MainMenuState::updateInput(const float& dt)
{

	
}

void MainMenuState::updateButtons()
{
	/*Update all the buttons in the state and handles their functionality*/
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//New Game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	//Quit The Game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);

	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);

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
