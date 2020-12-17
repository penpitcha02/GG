#include "MainMenuState.h"

//Initializer functions
void MainMenuState::initVariable()
{
	
}

void MainMenuState::initMusic()
{
	if (!this->music.openFromFile("music/Tanjirou.wav"))
		printf("LOAD MAI DAI AAAAAAA");
	this->music.play();
	this->music.setLoop(true);
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

	if (!this->backgroundTexture.loadFromFile("img/Menu.png"))
	{
		printf("LOAD MENU BACKGROUND MAI DAI AAAAAAA");
	}

	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initView()
{
	this->view.setSize(sf::Vector2f(1440.0f, 810.0f));
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
	if (!this->button1idleTexture.loadFromFile("img/menubutton/PlayButton1.png"))
		printf("LOAD BUTTON 1 IDLE MAI DAI AAAAAAA");

	if (!this->button1hoverTexture.loadFromFile("img/menubutton/PlayButtonHighlight1.png"))
		printf("LOAD BUTTON 1 HOVER MAI DAI AAAAAAA");

	if (!this->button1activeTexture.loadFromFile("img/menubutton/PlayButtonPressed1.png"))
		printf("LOAD BUTTON 1 ACTIVE MAI DAI AAAAAAA");

	this->buttons["GAME_STATE"] = new Button(1050, 200, 172.5, 107.5,
		&this->button1idleTexture, &this->button1hoverTexture, &this->button1activeTexture);

	//Button2
	if (!this->button2idleTexture.loadFromFile("img/menubutton/HelpButton1.png"))
		printf("LOAD BUTTON 2 IDLE MAI DAI AAAAAAA");

	if (!this->button2hoverTexture.loadFromFile("img/menubutton/HelpButtonHighlight1.png"))
		printf("LOAD BUTTON 2 HOVER MAI DAI AAAAAAA");

	if (!this->button2activeTexture.loadFromFile("img/menubutton/HelpButtonPressed1.png"))
		printf("LOAD BUTTON 2 ACTIVE MAI DAI AAAAAAA");

	this->buttons["HELP_STATE"] = new Button(1050, 350, 172.5, 107.5,
		&this->button2idleTexture, &this->button2hoverTexture, &this->button2activeTexture);

		//Button3
	if (!this->button3idleTexture.loadFromFile("img/menubutton/QuitButton1.png"))
		printf("LOAD BUTTON 3 IDLE MAI DAI AAAAAAA");

	if (!this->button3hoverTexture.loadFromFile("img/menubutton/QuitButtonHighlight1.png"))
		printf("LOAD BUTTON 3 HOVER MAI DAI AAAAAAA");

	if (!this->button3activeTexture.loadFromFile("img/menubutton/QuitButtonPressed1.png"))
		printf("LOAD BUTTON 3 ACTIVE MAI DAI AAAAAAA");

	this->buttons["QUIT_STATE"] = new Button(1050, 550, 172.5, 107.5,
		&this->button3idleTexture, &this->button3hoverTexture, &this->button3activeTexture);
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariable();
	this->initMusic();
	this->initBackground();
	this->initView();
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


void MainMenuState::updateInput(const float& dt)
{

	
}

void MainMenuState::updateView()
{
	this->view.setCenter(sf::Vector2f(720.0f, 405.0f));
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
		this->music.stop();
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
		this->endState();
	}

	//How to play
	if (this->buttons["HELP_STATE"]->isPressed())
	{
		this->states->push(new HowToState(this->window, this->supportedKeys, this->states));
	}


	//Quit The Game
	if (this->buttons["QUIT_STATE"]->isPressed())
	{
		this->music.stop();
		this->endState();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateView();

	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target)
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

	target->setView(this->view);

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
