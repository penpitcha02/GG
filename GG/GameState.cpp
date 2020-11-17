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
		printf("LOAD GAME BACKGROUND MAI DAI AAAAAAA");
	}

	//LongWeb
	if (!this->longweb1Texture.loadFromFile("img/Longweb.png"))
	{
		printf("LOAD LONGWEB 1 MAI DAI AAAAAAA");
	}
	if (!this->longweb2Texture.loadFromFile("img/Longweb.png"))
	{
		printf("LOAD LONGWEB 2 MAI DAI AAAAAAA");
	}

	//Viewweb
	if (!this->viewwebTexture.loadFromFile("img/Viewweb.png"))
	{
		printf("LOAD VIEWWEB MAI DAI AAAAAAA");
	}

	//Pause Menu
	if (!this->button1idleTexture.loadFromFile("img/menubutton/PlayButton1.png"))
		printf("LOAD BUTTON 1 IDLE MAI DAI AAAAAAA");

	if (!this->button1hoverTexture.loadFromFile("img/menubutton/PlayButtonHighlight1.png"))
		printf("LOAD BUTTON 1 HOVER MAI DAI AAAAAAA");

	if (!this->button1activeTexture.loadFromFile("img/menubutton/PlayButtonPressed1.png"))
		printf("LOAD BUTTON 1 ACTIVE MAI DAI AAAAAAA");

	//Game Over
	if (!this->button2idleTexture.loadFromFile("img/menubutton/PlayButton1.png"))
		printf("LOAD BUTTON 2 IDLE MAI DAI AAAAAAA");

	if (!this->button2hoverTexture.loadFromFile("img/menubutton/PlayButtonHighlight1.png"))
		printf("LOAD BUTTON 2 HOVER MAI DAI AAAAAAA");

	if (!this->button2activeTexture.loadFromFile("img/menubutton/PlayButtonPressed1.png"))
		printf("LOAD BUTTON 2 ACTIVE MAI DAI AAAAAAA");


	//Player
	if (!this->textures["PLAYER_SHEET"].loadFromFile("img/Grandpa.png"))
	{
		printf("LOAD PLAYER MAI DAIIII");
	}

	//Boss
	if (!this->textures["BOSS_SHEET"].loadFromFile("img/Boss.png"))
	{
		printf("LOAD BOSS MAI DAIIII");
	}

	//Coconuts
	if (!this->textures["COCONUTS_SHEET"].loadFromFile("img/Coconut.png"))
	{
		printf("LOAD COCONUT MAI DAIIII");
	}

	//Monsters
	if (!this->textures["SHEET"].loadFromFile("img/Monster.png"))
	{
		printf("LOAD MONSTER MAI DAIIII");
	}
	
	//Bigmons
	if (!this->textures["BIGMONS_SHEET"].loadFromFile("img/Bigmonster.png"))
	{
		printf("LOAD BIGMONS MAI DAIIII");
	}

	//Lockwebs
	if (!this->textures["LOCKWEB_SHEET"].loadFromFile("img/Lockweb.png"))
	{
		printf("LOAD LOCKWEB MAI DAIIII");
	}

	//Lockwebs
	if (!this->textures["ATTACKWEB_SHEET"].loadFromFile("img/Attackweb.png"))
	{
		printf("LOAD ATTACKWEB IDLE MAI DAIIII");
	}
}

void GameState::initPauseMenu()
{
	this->pmenu = new PauseMenu(*this->window);

	this->pmenu->addButton("QUIT_STATE", &this->button1idleTexture, &this->button1hoverTexture, &this->button1activeTexture);
}

void GameState::initGameOver()
{
	this->gameover = new GameOver(*this->window);

	this->gameover->addButton("RANK_STATE", &this->button2idleTexture, &this->button2hoverTexture, &this->button2activeTexture);

	//Init  last score text
	this->lastScoreText.setFont(this->font);
	this->lastScoreText.setCharacterSize(50);
	this->lastScoreText.setFillColor(sf::Color::White);
}


void GameState::initBackground()
{
	this->background.setSize(sf::Vector2f(4320.f, 810.f));
	this->background.setTexture(&this->backgroundTexture);
}

void GameState::initView()
{
	this->view.setSize(sf::Vector2f(1440.0f, 810.0f));
}

void GameState::initWeb()
{
	this->longweb1.setSize(sf::Vector2f(256.f, 410.f));
	this->longweb1.setTexture(&this->longweb1Texture);
	this->longweb1.setPosition(1300.f, -10.f);
	this->longweb1.setScale(1.f, 1.25f);

	this->longweb2.setSize(sf::Vector2f(256.f, 410.f));
	this->longweb2.setTexture(&this->longweb2Texture);
	this->longweb2.setPosition(1300.f, 820.f);
	this->longweb2.setScale(1.f, -1.25f);

	this->viewweb.setSize(sf::Vector2f(1440.f, 810.f));
	this->viewweb.setTexture(&this->viewwebTexture);
	this->viewweb.setPosition(0.f, -300.f);
}


void GameState::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("font/arialbi.ttf"))
	{
		throw("LOAD MAIDAI KRUB");
	}
	////Init point text
	//this->gameOverText.setFont(this->font);
	//this->gameOverText.setCharacterSize(80);
	//this->gameOverText.setFillColor(sf::Color::Red);
	//this->gameOverText.setString("Game Over!");

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

	//Init score text
	this->scoreText.setFont(this->font);
	this->scoreText.setCharacterSize(20);
	this->scoreText.setFillColor(sf::Color::Blue);
	this->scoreText.setString("test");
}

void GameState::initSystem()
{
	this->score = 0;

	this->lastscore = this->score;

	this->cantMove = false;
}


void GameState::initPlayer()
{
	this->player = new Player(0, 340, this->textures["PLAYER_SHEET"]); 
}

void GameState::initBoss()
{
	this->boss = new Boss(0, 340, this->textures["BOSS_SHEET"]);
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

void GameState::initLockwebs()
{
	this->spawnTimerMax4 = 100.f;
	this->spawnTimer4 = this->spawnTimerMax3;
}


//Constructors / Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTexture();
	this->initPauseMenu();
	this->initGameOver();

	this->initBackground();
	this->initView();
	this->initWeb();

	this->initGUI();
	this->initSystem();

	this->initPlayer();
	this->initCoconuts();
	this->initMonsters();
	this->initBigmons();
	this->initLockwebs();
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
		{
			if (this->player->getHp() != 0)
				this->unpauseState();
		}
	}
}

void GameState::updatePlayerInput(const float& dt)
{
	//Update player input
	if (!cantMove)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
			this->player->move(-1.f, 0.f, dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
			this->player->move(1.f, 0.f, dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
			this->player->move(0.f, -1.f, dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
			this->player->move(0.f, 1.f, dt);
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
			this->player->move(0.f, 0.f, dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
			this->player->move(0.f, 0.f, dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
			this->player->move(0.f, 0.f, dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
			this->player->move(0.f, 0.f, dt);
	}
}

void GameState::updatePauseMenuButtons()
{
	this->pmenu->setPosition(this->view.getCenter().x - 180.f, this->view.getCenter().y - 405.f);

	this->pmenu->buttonSetPosition("QUIT_STATE", this->view.getCenter().x - 86.25, this->view.getCenter().y - 86.25);

	if (this->pmenu->isButtonPressed("QUIT_STATE"))
	{
		this->endState();
	}
}

void GameState::updateGameOverButton()
{
	//Last score
	this->lastScoreText.setPosition(this->view.getCenter().x - this->lastScoreText.getGlobalBounds().width, 400.f);

	std::stringstream ss;
	ss << "Your Score : " << this->lastscore;

	this->lastScoreText.setString(ss.str());

	this->gameover->setPosition(this->view.getCenter().x - 180.f, this->view.getCenter().y - 405.f);

	this->gameover->textSetPosition(this->view.getCenter().x - 180.f, this->view.getCenter().y - 405.f);

	this->gameover->buttonSetPosition("RANK_STATE", this->view.getCenter().x - 86.25, this->view.getCenter().y + 100.f);

	if (this->gameover->isButtonPressed("RANK_STATE"))
	{
		this->states->push(new EndGameState(this->window, this->supportedKeys, this->states));
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
	if (this->view.getCenter().x > 3600.f)
	{
		this->view.setCenter(3600.f, this->window->getSize().y / 2.f);
	}
}

void GameState::updateLongWeb()
{
	if (this->score >= 500)
	{
		this->longweb1.move(0.f, -10.f);
		this->longweb2.move(0.f, 10.f);
	}
}

void GameState::updateViewWeb()
{
	this->viewweb.setPosition(this->view.getCenter().x - 720.f, 0.f);	
}


void GameState::updateGUI()
{
	this->scoreText.setPosition(this->view.getCenter().x - this->scoreText.getGlobalBounds().width, 10.f);

	this->playerHpBar.setPosition(this->view.getCenter().x - 710, 10.f);
	this->playerHpBarBack.setPosition(this->playerHpBar.getPosition());

	/*this->gameOverText.setPosition(this->view.getCenter().x - this->pointText.getGlobalBounds().width, 10.f);*/

	std::stringstream ss;
	ss << "Score : " << this->score;

	this->scoreText.setString(ss.str());

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
	else if (this->score < 500)
	{
		if (this->player->GetPosition().x + this->player->getBounds().width >= 1580.f)
		{
			this->player->setPosition(1580.f - this->player->getBounds().width, this->player->GetPosition().y);
		}
	}
	else if(this->player->GetPosition().x + this->player->getBounds().width >= 4470.f)
	{
		this->player->setPosition(4470.f - this->player->getBounds().width, this->player->GetPosition().y);
	}
	
	//Top Collision
	if (this->player->GetPosition().y < 200.f)
	{
		this->player->setPosition(this->player->GetPosition().x, 200.f);
	}
	//Bottom Collision
	else if (this->player->GetPosition().y + this->player->getBounds().height >= 870.f)
	{
		this->player->setPosition(this->player->GetPosition().x, 870.f - this->player->getBounds().height);
	}
}

void GameState::updateCoconutsAndCombat(const float& dt)
{
	if (this->score < 500.f)
	{
		this->spawnTimer += 0.2f;
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
		if (this->coconuts[i]->GetPosition().x > this->player->GetPosition().x + 200.f)
		{
			this->coconuts[i]->coconutBackLeft();
		}
		if (this->coconuts[i]->GetPosition().x < this->player->GetPosition().x + 200.f)
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
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CutboxgetBounds().intersects(this->coconuts[i]->getBounds()) 
			&& !coconut_removed /*&& this->player->canAttack()*/)
		{
			this->score += this->coconuts[i]->getPoints();

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

void GameState::updateMonstersAndCombat(const float& dt)
{
	if (this->score < 500.f)
	{
		this->spawnTimer2 += 0.2f;
		if (this->spawnTimer2 >= this->spawnTimerMax2)
		{
			this->monsters.push_back(new Monster(1440.f, this->player->GetPosition().y + 250.f, this->textures["SHEET"]));
			this->spawnTimer2 = 0.f;
		}
	}

	for (int j = 0; j < this->monsters.size(); ++j)
	{
		bool monster_removed = false;

		this->monsters[j]->update(dt);

		//Monster Follow Player
		if (this->monsters[j]->GetPosition().x > this->player->GetPosition().x + 200.f)
		{
			this->monsters[j]->monsterBackLeft();
		}
		if (this->monsters[j]->GetPosition().x < this->player->GetPosition().x + 200.f)
		{
			this->monsters[j]->monsterBackRight();
		}
		if (this->monsters[j]->GetPosition().y > this->player->GetPosition().y + 150.f)
		{
			this->monsters[j]->monsterBackUp();
		}
		if (this->monsters[j]->GetPosition().y < this->player->GetPosition().y + 150.f)
		{
			this->monsters[j]->monsterBackDown();
		}

		//Monster lose if attack the monster
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CutboxgetBounds().intersects(this->monsters[j]->getBounds()) 
			&& !monster_removed)
		{
			this->score += this->monsters[j]->getPoints();
			
			this->monsters[j]->loseHp(this->player->getDamage());

			printf("+1\n");
		}
		//Monster Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->monsters[j]->getBounds()) && this->monsters[j]->canAttack())
		{
			this->player->loseHp(this->monsters[j]->getDamage());

			printf("-5\n");
		}

		//Remove if monster die
		if (this->monsters[j]->getHp() <= 0)
		{
			this->monsters.erase(this->monsters.begin() + j);
			monster_removed = true;
		}
	}
}

void GameState::updateBigmonsAndCombat(const float& dt)
{
	if (this->score >= 500.f)
	{
		this->spawnTimer3 += 0.2f;
		if (this->spawnTimer3 >= this->spawnTimerMax3)
		{
			this->bigmons.push_back(new BigMons(rand() % this->window->getSize().x * 2, rand() % this->window->getSize().y, 
				this->textures["BIGMONS_SHEET"]));
			this->spawnTimer3 = 0.f;
		}
	}


	for (int k = 0; k < this->bigmons.size(); ++k)
	{
		bool bigmons_removed = false;

		this->bigmons[k]->update(dt);

		//Bigmons Follow Player
		if (this->bigmons[k]->GetPosition().x > this->player->GetPosition().x + 100.f)
		{
			this->bigmons[k]->bigmonsBackLeft();
		}
		if (this->bigmons[k]->GetPosition().x < this->player->GetPosition().x + 100.f)
		{
			this->bigmons[k]->bigmonsBackRight();
		}
		if (this->bigmons[k]->GetPosition().y > this->player->GetPosition().y + 200.f)
		{
			this->bigmons[k]->bigmonsBackUp();
		}
		if (this->bigmons[k]->GetPosition().y < this->player->GetPosition().y + 200.f)
		{
			this->bigmons[k]->bigmonsBackDown();
		}

		//Bigmon lose hp if attack the bigmons
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CutboxgetBounds().intersects(this->bigmons[k]->getBounds())
			&& !bigmons_removed /*&& this->player->canAttack()*/)
		{
			this->score += this->bigmons[k]->getPoints();

			this->bigmons[k]->loseHp(this->player->getDamage());

			printf("+1\n");
		}
		//Bigmons Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->bigmons[k]->getBounds()) && this->bigmons[k]->canAttack())
		{

			this->player->loseHp(this->bigmons[k]->getDamage());

			/*this->player->setPosition(this->player->GetPosition().x - 20.f, this->player->GetPosition().y);

			this->bigmons[i]->setPosition(this->monsters[i]->GetPosition().x + 20.f, this->monsters[i]->GetPosition().y);*/

			printf("-10\n");
		}

		//Remove if bigmon die
		if (this->bigmons[k]->getHp() <= 0)
		{
			this->bigmons.erase(this->bigmons.begin() + k);
			bigmons_removed = true;
		}
	}
}

void GameState::updateLockwebsAndCombat(const float& dt)
{
	if (this->score >= 500.f)
	{
		this->spawnTimer4 += 0.2f;
		if (this->spawnTimer4 >= this->spawnTimerMax4)
		{
			this->lockwebs.push_back(new LockWeb(this->player->GetPosition().x + 200.f, this->player->GetPosition().y,
				this->textures["LOCKWEB_SHEET"]));
			this->spawnTimer4 = 0.f;
		}
	}


	for (int l = 0; l < this->lockwebs.size(); ++l)
	{
		bool lockwebs_removed = false;

		this->lockwebs[l]->setPosition(this->player->GetPosition().x + 100.f, this->player->GetPosition().y);

		this->lockwebs[l]->update(dt);

		//Lockweb lose hp if attack the bigmons
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CutboxgetBounds().intersects(this->lockwebs[l]->getBounds())
			&& !lockwebs_removed /*&& this->player->canAttack()*/ && this->cantMove)
		{
			this->score += this->lockwebs[l]->getPoints();

			this->lockwebs[l]->loseHp(this->player->getDamage());

			printf("+1\n");
		}
		//Lockweb Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->lockwebs[l]->getBounds()))
		{

			this->cantMove = true;

			printf("-10\n");
		}

		//Remove if lockweb die
		if (this->lockwebs[l]->getHp() <= 0)
		{
			this->lockwebs.erase(this->lockwebs.begin() + l);
			lockwebs_removed = true;
			this->cantMove = false;
		}
	}
}

void GameState::updateAttackWebsAndCombat(const float& dt)
{
	if (this->score >= 500.f)
	{
		this->spawnTimer += 0.2f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->attackwebs.push_back(new AttackWeb(1440.f, this->player->GetPosition().y + 250.f, this->textures["ATTACKWEB_SHEET"]));
			this->spawnTimer = 0.f;
		}
	}

	for (int m = 0; m < this->attackwebs.size(); ++m)
	{
		bool attackweb_removed = false;

		this->attackwebs[m]->update(dt);

		//Attackweb Follow Player
		if (this->attackwebs[m]->GetPosition().x > this->player->GetPosition().x + 200.f)
		{
			this->attackwebs[m]->attackwebBackLeft();
		}
		if (this->attackwebs[m]->GetPosition().x < this->player->GetPosition().x + 200.f)
		{
			this->attackwebs[m]->attackwebBackRight();
		}

		//Attackweb lose if attack the monster
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CutboxgetBounds().intersects(this->attackwebs[m]->getBounds())
			&& !attackweb_removed)
		{
			this->score += this->attackwebs[m]->getPoints();

			this->attackwebs[m]->loseHp(this->player->getDamage());

			printf("+1\n");
		}
		//Attackweb Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->attackwebs[m]->getBounds()) && this->attackwebs[m]->canAttack())
		{
			this->player->loseHp(this->attackwebs[m]->getDamage());

			printf("-5\n");
		}

		//Remove if attackweb die
		if (this->attackwebs[m]->getHp() <= 0)
		{
			this->attackwebs.erase(this->attackwebs.begin() + m);
			attackweb_removed = true;
		}
	}
}

void GameState::updateUltiWebsAndCombat(const float& dt)
{
	if (this->score >= 500.f)
	{
		this->spawnTimer2 += 0.2f;
		if (this->spawnTimer2 >= this->spawnTimerMax2)
		{
			this->ultiwebs.push_back(new UltiWeb(1440.f, this->player->GetPosition().y + 250.f, this->textures["ATTACKWEB_SHEET"]));
			this->spawnTimer2 = 0.f;
		}
	}

	for (int n = 0; n < this->ultiwebs.size(); ++n)
	{
		bool ultiweb_removed = false;

		this->ultiwebs[n]->update(dt);

		//Ultiweb Follow Player
		if (this->ultiwebs[n]->GetPosition().x > this->player->GetPosition().x + 200.f)
		{
			this->ultiwebs[n]->attackwebBackLeft();
		}
		if (this->ultiwebs[n]->GetPosition().x < this->player->GetPosition().x + 200.f)
		{
			this->ultiwebs[n]->attackwebBackRight();
		}

		//Ultiweb lose if attack the ultiweb
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CutboxgetBounds().intersects(this->ultiwebs[n]->getBounds())
			&& !ultiweb_removed)
		{
			this->score += this->ultiwebs[n]->getPoints();

			this->ultiwebs[n]->loseHp(this->player->getDamage());

			printf("+1\n");
		}
		//Ultiweb Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->ultiwebs[n]->getBounds()) && this->ultiwebs[n]->canAttack())
		{
			this->player->loseHp(this->ultiwebs[n]->getDamage());

			printf("-5\n");
		}

		//Remove if Ultiweb die
		if (this->ultiwebs[n]->getHp() <= 0)
		{
			this->ultiwebs.erase(this->ultiwebs.begin() + n);
			ultiweb_removed = true;
		}
	}
}

void GameState::updateBossAndCombat(const float& dt)
{
	if (this->boss->getHp() > 0)
	{
		this->boss->updateAnimation(dt);
	}
	else //Die
	{
		this->boss->updateDieAnimation(dt);
	}

	//Boss lose if attack the boss
	if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CutboxgetBounds().intersects(this->boss->HitboxgetBounds()))
	{
		this->score += this->boss->getPoints();

		this->boss->loseHp(this->player->getDamage());

		printf("+1\n");
	}
	//Boss Player Collision
	else if (this->player->HitboxgetBounds().intersects(this->boss->HitboxgetBounds()) && this->boss->canAttack())
	{
		this->player->loseHp(this->boss->getDamage());

		printf("-5\n");
	}

	////Die animation
	//if (this->boss->getHp() <= 0)
	//{
	//	
	//}
	
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

		if(this->longweb1.getPosition().y > -550.f)
			this->updateLongWeb();
		else
			this->updateViewWeb();

		this->player->update(dt);

		this->updateCollision();

		this->updateCoconutsAndCombat(dt);
		this->updateMonstersAndCombat(dt);
		this->updateBigmonsAndCombat(dt);
		this->updateLockwebsAndCombat(dt);
		this->updateAttackWebsAndCombat(dt);
		this->updateUltiWebsAndCombat(dt);
		this->updateBossAndCombat(dt);
	 
		this->updateGUI();
	}
	else //Pause update
	{
		if (this->player->getHp() != 0)
		{
			this->pmenu->update(this->mousePosView);

			this->updatePauseMenuButtons();
		}
		else
		{
			this->gameover->update(this->mousePosView);

			this->updateGameOverButton();
		}
	}
}

void GameState::renderGUI()
{
	this->window->draw(this->scoreText);
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

	//Longweb
	target->draw(this->longweb1);
	target->draw(this->longweb2);

	//Viewweb
	target->draw(this->viewweb);

	//Player
	this->player->render(*target);

	//Boss
	/*this->boss->render(*target);*/
	
	//Coconuts
	for (auto* coconut : this->coconuts)
	{
		coconut->render(*target);
	}

	//Monsters
	for (auto* monster : this->monsters)
	{
		monster->render(*target);
	}

	//BigMons
	for (auto* bigmon : this->bigmons)
	{
		bigmon->render(*target);
	}

	//Lockwebs
	for (auto* lockweb : this->lockwebs)
	{
		lockweb->render(*target);
	}

	//Attackwebs
	for (auto* attackweb : this->attackwebs)
	{
		attackweb->render(*target);
	}

	//Ultiwebs
	for (auto* ultiweb : this->ultiwebs)
	{
		ultiweb->render(*target);
	}

	//GUI
	this->renderGUI();

	////Game Over
	//if (this->player->getHp() <= 0)
	//	this->window->draw(this->gameOverText);

	//Pause Menu
	if (this->paused) 
	{
		this->pmenu->render(*target);
	}

	//Game Over
	if (this->player->getHp() <= 0)
	{
		this->gameover->render(*target);
		this->window->draw(this->lastScoreText);
	}
}
