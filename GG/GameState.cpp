#include "GameState.h"

//Initializer functions
void GameState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

void GameState::initTexture()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("img/3-3.png"))
	{
		printf("LOAD PLAYER IDLE MAI DAIIII");
	}

	if (!this->backgroundTexture.loadFromFile("img/Game.png"))
	{
		printf("LOAD MENU BACKGROUND MAI DAI AAAAAAA");
	}
}

void GameState::initBackground()
{
	this->background.setSize(sf::Vector2f(1440.f, 810.f));
	this->background.setTexture(&this->backgroundTexture);
}

void GameState::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("font/arialbi.ttf"))
	{
		throw("LOAD MAIDAI KRUB");
	}
	//Init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(20);
	this->pointText.setFillColor(sf::Color::Blue);
	this->pointText.setString("test");

	//Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

void GameState::initSystem()
{
	this->points = 0;
}

void GameState::initPlayers()
{
	this->player = new Player(0, 340, this->textures["PLAYER_SHEET"]); 
}

void GameState::initCoconuts()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}


//Constructors / Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTexture();
	this->initBackground();
	this->initGUI();
	this->initSystem();

	this->initPlayers();
	this->initCoconuts();
}

GameState::~GameState()
{
	delete this->player;
	for (auto* i : this->coconuts)
	{
		delete i;
	}
}


void GameState::updateInput(const float& dt)
{

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(0.f, 1.f, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void GameState::updateGUI()
{
	std::stringstream ss;
	ss << "Ponits: " << this->points;

	this->pointText.setString(ss.str());

	//Update player GUI;
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));
}

void GameState::updateCollision()
{
	//Left Collision
	if (this->player->GetPosition().x < -100.f)
	{
		this->player->setPosition(-100.f, this->player->GetPosition().y);
	}
	//Right Collision
	else if (this->player->GetPosition().x + this->player->getBounds().width >= 1580.f)
	{
		this->player->setPosition(1580.f - this->player->getBounds().width, this->player->GetPosition().y);
	}
	//Top Collision
	if (this->player->GetPosition().y < 50.f)
	{
		this->player->setPosition(this->player->GetPosition().x, 50.f);
	}
	//Bottom Collision
	else if (this->player->GetPosition().y + this->player->getBounds().height >= 850.f)
	{
		this->player->setPosition(this->player->GetPosition().x, 850.f - this->player->getBounds().height);
	}
}

void GameState::updateCoconutsAndCombat()
{
	this->spawnTimer += 2.f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->coconuts.push_back(new Coconut(rand() % this->window->getSize().x - 20.f, -100.f));
		this->spawnTimer = 0.f;
	}

	for (int i = 0; i < this->coconuts.size(); ++i)
	{
		bool coconut_removed = false;
		this->coconuts[i]->update();

		//Remove if chop the coconut
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->HitboxgetBounds().intersects(this->coconuts[i]->getBounds()) && !coconut_removed)
		{
			this->points += this->coconuts[i]->getPoints();

			printf("+1\n");
			this->coconuts.erase(this->coconuts.begin() + i);
			coconut_removed = true;
		}
		//Coconuts Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->coconuts[i]->getBounds()) && !coconut_removed)
		{
			this->player->loseHp(this->coconuts[i]->getDamage());

			printf("-1\n");
			this->coconuts.erase(this->coconuts.begin() + i);
			coconut_removed = true;
			
		}

		//Remove coconuts at the bottom of the screen
		if (!coconut_removed)
		{
			if (this->coconuts[i]->getBounds().top > this->window->getSize().y)
			{
				this->coconuts.erase(this->coconuts.begin() + i);
				std::cout << this->coconuts.size() << "\n";
				coconut_removed = true;
			}
		}
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();

	this->updateInput(dt);

	this->player->update(dt);

	this->updateCollision();

	this->updateCoconutsAndCombat();

	this->updateGUI();
}

void GameState::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->player->render(*target);

	for (auto* coconut : this->coconuts)
	{
		coconut->render(target);
	}

	this->renderGUI();
}
