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
	//Background
	if (!this->backgroundTexture.loadFromFile("img/NightGame.png"))
	{
		printf("LOAD MENU BACKGROUND MAI DAI AAAAAAA");
	}

	//if (!this->shopTexture.loadFromFile("img/Shop.png"))
	//{
	//	printf("LOAD MENU BACKGROUND MAI DAI AAAAAAA");
	//}

	//Pause Menu
	if (!this->button1idleTexture.loadFromFile("img/menubutton/PlayButton1.png"))
		printf("LOAD BUTTON 1 IDLE MAI DAI AAAAAAA");

	if (!this->button1hoverTexture.loadFromFile("img/menubutton/PlayButtonHighlight1.png"))
		printf("LOAD BUTTON 1 HOVER MAI DAI AAAAAAA");

	if (!this->button1activeTexture.loadFromFile("img/menubutton/PlayButtonPressed1.png"))
		printf("LOAD BUTTON 1 ACTIVE MAI DAI AAAAAAA");

	//Player
	if (!this->textures["PLAYER_SHEET"].loadFromFile("img/3-3.png"))
	{
		printf("LOAD PLAYER IDLE MAI DAIIII");
	}

	//Coconuts
	if (!this->textures["COCONUTS_SHEET"].loadFromFile("img/BigMons-1.png"))
	{
		printf("LOAD PLAYER IDLE MAI DAIIII");
	}
	
	//Bigmons
	if (!this->textures["BIGMONS_SHEET"].loadFromFile("img/3-3.png"))
	{
		printf("LOAD PLAYER IDLE MAI DAIIII");
	}
}

void GameState::initPauseMenu()
{
	this->pmenu = new PauseMenu(*this->window);

	this->pmenu->addButton("QUIT_STATE", 720.f, 405.f, &this->button1idleTexture, &this->button1hoverTexture, &this->button1activeTexture);
}


void GameState::initBackground()
{
	this->background.setSize(sf::Vector2f(2880.f, 810.f));
	this->background.setTexture(&this->backgroundTexture);

	/*this->shop.setSize(sf::Vector2f(4320.f, 810.f));
	this->shop.setTexture(&this->shopTexture);*/
}

void GameState::initView()
{
	this->view.setSize(sf::Vector2f(1440.0f, 810.0f));
}

void GameState::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("font/arialbi.ttf"))
	{
		throw("LOAD MAIDAI KRUB");
	}
	//Init point text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(80);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over!");

	//Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 5.f));
	this->playerHpBar.setFillColor(sf::Color::White);
	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 100));

	//Init bigmons GUI
	/*this->bigmonsHpBar.setSize(sf::Vector2f(200.f, 10.f));
	this->bigmonsHpBar.setFillColor(sf::Color::White);
	this->bigmonsHpBarBack = this->playerHpBar;
	this->bigmonsHpBarBack.setFillColor(sf::Color(25, 25, 25, 100));*/

	//Init game over text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(20);
	this->pointText.setFillColor(sf::Color::Blue);
	this->pointText.setString("test");
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

void GameState::initMonsters()
{
	this->spawnTimerMax2 = 50.f;
	this->spawnTimer2 = this->spawnTimerMax2;
}

void GameState::initBigmons()
{
	this->spawnTimerMax3 = 50.f;
	this->spawnTimer3 = this->spawnTimerMax3;
}


//Constructors / Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTexture();
	this->initPauseMenu();
	this->initBackground();
	this->initView();
	this->initGUI();
	this->initSystem();

	this->initPlayers();
	this->initCoconuts();
	this->initMonsters();
	this->initBigmons();
}

GameState::~GameState()
{
	delete this->pmenu;

	delete this->player;

	for (auto* i : this->coconuts)
	{
		delete i;
	}

	for (auto* i : this->monsters)
	{
		delete i;
	}
}

//Functions
void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
	{
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}
}

void GameState::updatePlayerInput(const float& dt)
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
}

void GameState::updatePauseMenuButtons()
{
	if (this->pmenu->isButtonPressed("QUIT_STATE"))
	{
		this->endState();
	}
}


void GameState::updateView()
{
	this->view.setCenter(this->player->GetPosition().x + 220.f, this->window->getSize().y / 2.f);

	//Left Collision
	if (this->view.getCenter().x < 720.f)
	{
		this->view.setCenter(720.f, this->window->getSize().y / 2.f);
	}
	//Right Collision
	if (this->view.getCenter().x > 2100.f)
	{
		this->view.setCenter(2100.f, this->window->getSize().y / 2.f);
	}
}

void GameState::updateGUI()
{
	this->pointText.setPosition(this->view.getCenter().x - this->pointText.getGlobalBounds().width, 10.f);

	this->playerHpBar.setPosition(this->view.getCenter().x - 710, 10.f);
	this->playerHpBarBack.setPosition(this->playerHpBar.getPosition());

	this->gameOverText.setPosition(this->view.getCenter().x - this->pointText.getGlobalBounds().width, 10.f);

	std::stringstream ss;
	ss << "Ponits: " << this->points;

	this->pointText.setString(ss.str());

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
	else if (this->points < 20)
	{
		if (this->player->GetPosition().x + this->player->getBounds().width >= 1580.f)
		{
			this->player->setPosition(1580.f - this->player->getBounds().width, this->player->GetPosition().y);
		}
		else if(this->player->GetPosition().x + this->player->getBounds().width >= 2740.f)
		{
		this->player->setPosition(2740.f - this->player->getBounds().width, this->player->GetPosition().y);
		}
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

void GameState::updateCoconutsAndCombat(const float& dt)
{
	if (this->points < 20.f)
	{
		this->spawnTimer += 2.f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->coconuts.push_back(new Coconut(rand() % this->window->getSize().x, -100.f, this->textures["COCONUTS_SHEET"]));
			this->spawnTimer = 0.f;
		}
	}

	for (int i = 0; i < this->coconuts.size(); ++i)
	{
		bool coconut_removed = false;

		this->coconuts[i]->update(dt);

		//Coconuts Follow Player
		if (this->coconuts[i]->GetPosition().x > this->player->GetPosition().x + 237.5f)
		{
			this->coconuts[i]->coconutBackLeft();
		}
		if (this->coconuts[i]->GetPosition().x < this->player->GetPosition().x + 237.5f)
		{
			this->coconuts[i]->coconutBackRight();
		}
		if (this->coconuts[i]->GetPosition().y > this->player->GetPosition().y)
		{
			this->coconuts[i]->coconutBackUp();
		}
		if (this->coconuts[i]->GetPosition().y < this->player->GetPosition().y)
		{
			this->coconuts[i]->coconutBackDown();
		}


		//Left Collision
		if (this->coconuts[i]->GetPosition().x < 0.f)
		{
			this->coconuts[i]->setPosition(0.f, this->coconuts[i]->GetPosition().y);
		}
		//Right Collision
		else if (this->coconuts[i]->GetPosition().x + this->coconuts[i]->getBounds().width >= 1440.f)
		{
			this->coconuts[i]->setPosition(1440.f - this->coconuts[i]->getBounds().width, this->coconuts[i]->GetPosition().y);
		}
		//Top Collision
		if (this->coconuts[i]->GetPosition().y < 0.f)
		{
			this->coconuts[i]->setPosition(this->coconuts[i]->GetPosition().x, 0.f);
		}
		//Bottom Collision
		else if (this->coconuts[i]->GetPosition().y + this->coconuts[i]->getBounds().height >= 810.f)
		{
			this->coconuts[i]->setPosition(this->coconuts[i]->GetPosition().x, 810.f - this->coconuts[i]->getBounds().height);
		}

		//Remove if chop the coconut
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CutboxgetBounds().intersects(this->coconuts[i]->getBounds()) && !coconut_removed)
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

		////Remove coconuts at the bottom of the screen
		//if (!coconut_removed)
		//{
		//	if (this->coconuts[i]->getBounds().top > this->window->getSize().y)
		//	{
		//		this->coconuts.erase(this->coconuts.begin() + i);
		//		std::cout << this->coconuts.size() << "\n";
		//		coconut_removed = true;
		//	}
		//}
	}
}

void GameState::updateMonstersAndCombat()
{
	if (this->points < 20.f)
	{
		this->spawnTimer2 += 2.f;
		if (this->spawnTimer2 >= this->spawnTimerMax2)
		{
			this->monsters.push_back(new Monster(1440.f, this->player->GetPosition().y + 250.f));
			this->spawnTimer2 = 0.f;
		}
	}

	for (int i = 0; i < this->monsters.size(); ++i)
	{
		bool monster_removed = false;

		//Monster Follow Player
		if (this->monsters[i]->GetPosition().x > this->player->GetPosition().x + 237.5f)
		{
			this->monsters[i]->monsterBackLeft();
		}
		if (this->monsters[i]->GetPosition().x < this->player->GetPosition().x + 237.5f)
		{
			this->monsters[i]->monsterBackRight();
		}
		if (this->monsters[i]->GetPosition().y > this->player->GetPosition().y + 250.f)
		{
			this->monsters[i]->monsterBackUp();
		}
		if (this->monsters[i]->GetPosition().y < this->player->GetPosition().y + 250.f)
		{
			this->monsters[i]->monsterBackDown();
		}

		//Remove if attack the monster
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CutboxgetBounds().intersects(this->monsters[i]->getBounds()) && !monster_removed)
		{
			this->points += this->monsters[i]->getPoints();

			printf("+1\n");
			this->monsters.erase(this->monsters.begin() + i);
			monster_removed = true;
		}
		//Monster Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->monsters[i]->getBounds()))
		{
			this->player->loseHp(this->monsters[i]->getDamage());

			printf("-1\n");
			this->monsters.erase(this->monsters.begin() + i);
			monster_removed = true;
		}
	}
}

void GameState::updateBigmonsAndCombat(const float& dt)
{
	if (this->points >= 20.f)
	{
		this->spawnTimer3 += 1.f;
		if (this->spawnTimer3 >= this->spawnTimerMax3)
		{
			this->bigmons.push_back(new BigMons(4300.f, this->player->GetPosition().y + 250.f, this->textures["BIGMONS_SHEET"]));
			this->spawnTimer3 = 0.f;
		}
	}


	for (int i = 0; i < this->bigmons.size(); ++i)
	{
		bool bigmons_removed = false;

		/*this->bigmonsHpBar.setPosition(this->bigmons[i]->GetPosition());
		this->bigmonsHpBarBack.setPosition(this->bigmons[i]->GetPosition());

		float bigmonsHpPercent = static_cast<float>(this->bigmons[i]->getHp()) / this->bigmons[i]->getHpMax();
		this->bigmonsHpBar.setSize(sf::Vector2f(300.f * bigmonsHpPercent, this->bigmonsHpBar.getSize().y));*/
		
		if (this->player->HitboxgetBounds().intersects(this->bigmons[i]->getBounds()))
		{
			this->bigmons[i]->updateAttack(dt);
		}
		else
		{
			this->bigmons[i]->updateAnimation(dt);
		}

		//Bigmons Follow Player
		if (this->bigmons[i]->GetPosition().x > this->player->GetPosition().x + 237.5f)
		{
			this->bigmons[i]->bigmonsBackLeft();
		}
		if (this->bigmons[i]->GetPosition().x < this->player->GetPosition().x + 237.5f)
		{
			this->bigmons[i]->bigmonsBackRight();
		}
		if (this->bigmons[i]->GetPosition().y > this->player->GetPosition().y + 250.f)
		{
			this->bigmons[i]->bigmonsBackUp();
		}
		if (this->bigmons[i]->GetPosition().y < this->player->GetPosition().y + 250.f)
		{
			this->bigmons[i]->bigmonsBackDown();
		}

		//Remove if attack the bigmons
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CutboxgetBounds().intersects(this->bigmons[i]->getBounds()) && !bigmons_removed)
		{
			this->points += this->bigmons[i]->getPoints();

			this->bigmons[i]->loseHp(this->player->getDamage());

			printf("+1\n");
		}
		//Bigmons Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->bigmons[i]->getBounds()))
		{
			this->bigmons[i]->updateAttack(dt);

			this->player->loseHp(this->bigmons[i]->getDamage());

			printf("-1\n");
		}

		if (this->bigmons[i]->getHp() <= 0)
		{
			this->bigmons.erase(this->bigmons.begin() + i);
			bigmons_removed = true;
		}
	}
}


void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateKeytime(dt);
	this->updateInput(dt);
	
	if (!this->paused && this->player->getHp() != 0) //Unpause update
	{
		this->updatePlayerInput(dt);

		this->updateView();

		this->player->update(dt);

		this->updateCollision();

		this->updateCoconutsAndCombat(dt);

		this->updateMonstersAndCombat();
		
		this->updateBigmonsAndCombat(dt);
	
		this->updateGUI();
	}
	else //Pause update
	{
		this->pmenu->update(this->mousePosView);

		this->updatePauseMenuButtons();
	}
}

void GameState::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	/*this->window->draw(this->bigmonsHpBarBack);
	this->window->draw(this->bigmonsHpBar);*/
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	//View
	target->setView(this->view);

	//Background
	target->draw(this->background);

	//Player
	this->player->render(*target);

	//Shop
	/*target->draw(this->shop);*/

	
	//Coconuts
	for (auto* coconut : this->coconuts)
	{
		coconut->render(*target);
	}

	//Monsters
	for (auto* monster : this->monsters)
	{
		monster->render(target);
	}

	//BigMons
	for (auto* bigmon : this->bigmons)
	{
		bigmon->render(*target);
	}


	//GUI
	this->renderGUI();

	//Game Over
	if (this->player->getHp() <= 0)
		this->window->draw(this->gameOverText);

	//Pause Menu
	if (this->paused) 
	{
		this->pmenu->render(*target);
	}
}
