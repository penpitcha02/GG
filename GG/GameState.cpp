#include "GameState.h"

//Initializer functions
void GameState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
	this->keybinds["ULTIMATE"] = this->supportedKeys->at("Space");
	this->keybinds["LEFTULTIMATE"] = this->supportedKeys->at("Q");
	this->keybinds["RIGHTULTIMATE"] = this->supportedKeys->at("E");
}

void GameState::initMusic()
{
	if (!this->music.openFromFile("music/T26.wav"))
		printf("LOAD MAI DAI AAAAAAA");
	this->music.play();
	this->music.setVolume(50.f);
	this->music.setLoop(true);
}

void GameState::initSFX()
{
	//Player get hit sfx
	if (!this->playergethitBuffer.loadFromFile("sfx/playergethit.wav"))
	{
		printf("LOAD PLAYER GET HIT SFX MAI DAI AAAAAAA");
	}
	this->playergethit.setBuffer(this->playergethitBuffer);

	//Ultimate sfx
	if (!this->ultimateSoundBuffer.loadFromFile("sfx/ultimatedragon.wav"))
	{
		printf("LOAD ULTIMATE SFX MAI DAI AAAAAAA");
	}
	this->ultimateSound.setBuffer(this->ultimateSoundBuffer);
	/*this->ultimate1Sound.setVolume(25.f);*/

	//Coconut sfx
	if (!this->coconutSoundBuffer.loadFromFile("sfx/coconut.wav"))
	{
		printf("LOAD COCONUT SFX MAI DAI AAAAAAA");
	}
	this->coconutSound.setBuffer(this->coconutSoundBuffer);
	//Monster sfx
	if (!this->monsterSoundBuffer.loadFromFile("sfx/monster.wav"))
	{
		printf("LOAD COCONUT SFX MAI DAI AAAAAAA");
	}
	this->monsterSound.setBuffer(this->monsterSoundBuffer);
	//Bigmon sfx
	if (!this->bigmonSoundBuffer.loadFromFile("sfx/chicken.wav"))
	{
		printf("LOAD COCONUT SFX MAI DAI AAAAAAA");
	}
	this->bigmonSound.setBuffer(this->bigmonSoundBuffer);
	this->bigmonSound.setVolume(125.f);

	//Yakult
	if (!this->yakultSoundBuffer.loadFromFile("sfx/yakult.wav"))
	{
		printf("LOAD BOSS DIE SFX MAI DAI AAAAAAA");
	}
	this->yakultSound.setBuffer(this->yakultSoundBuffer);

	//Boss die
	if (!this->bossDieSoundBuffer.loadFromFile("sfx/bossdiewater.wav"))
	{
		printf("LOAD BOSS DIE SFX MAI DAI AAAAAAA");
	}
	this->bossDieSound.setBuffer(this->bossDieSoundBuffer);
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

	//Bigdragon
	if (!this->bigdragonTexture.loadFromFile("img/Bigdragon.png"))
	{
		printf("LOAD BIG DRAGON MAI DAI AAAAAAA");
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

	//End Game
	if (!this->button3idleTexture.loadFromFile("img/menubutton/PlayButton1.png"))
		printf("LOAD BUTTON 3 IDLE MAI DAI AAAAAAA");

	if (!this->button3hoverTexture.loadFromFile("img/menubutton/PlayButtonHighlight1.png"))
		printf("LOAD BUTTON 3 HOVER MAI DAI AAAAAAA");

	if (!this->button3activeTexture.loadFromFile("img/menubutton/PlayButtonPressed1.png"))
		printf("LOAD BUTTON 3 ACTIVE MAI DAI AAAAAAA");


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
		printf("LOAD LOCK WEB MAI DAIIII");
	}

	//Attackwebs
	if (!this->textures["ATTACKWEB_SHEET"].loadFromFile("img/Attackweb.png"))
	{
		printf("LOAD ATTACK WEB MAI DAIIII");
	}

	//Ultiwebs
	if (!this->textures["ULTIWEB_SHEET"].loadFromFile("img/Ultiweb.png"))
	{
		printf("LOAD ULTI WEB MAI DAIIII");
	}

	//Ultidragons
	if (!this->textures["ULTIDRAGON_SHEET"].loadFromFile("img/Ultidragon.png"))
	{
		printf("LOAD ULTI DRAGON MAI DAIIII");
	}

	//Yakults
	if (!this->textures["YAKULT_SHEET"].loadFromFile("img/Yakult.png"))
	{
		printf("LOAD YAKULT MAI DAIIII");
	}

	//BubbleTea
	if (!this->bubbleteaTexture.loadFromFile("img/Bubbletea.png"))
	{
		printf("LOAD BUBBLE TEA MAI DAI AAAAAAA");
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

void GameState::initEndGame()
{
	this->endgame = new EndGame(*this->window);

	this->endgame->addButton("RANK_STATE", &this->button3idleTexture, &this->button3hoverTexture, &this->button3activeTexture);

	//Init  last score text 2
	this->lastScoreText2.setFont(this->font);
	this->lastScoreText2.setCharacterSize(50);
	this->lastScoreText2.setFillColor(sf::Color::White);
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

void GameState::initBigdragon()
{
	this->bigdragon.setSize(sf::Vector2f(1440.f, 810.f));
	this->bigdragon.setTexture(&this->bigdragonTexture);
}


void GameState::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("font/maaja.ttf"))
	{
		printf("LOAD FONT MAI DAI");
	}

	//Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 5.f));
	this->playerHpBar.setFillColor(sf::Color::White);
	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(20, 20, 20, 100));

	//Init boss GUI
	this->bossHpBar.setSize(sf::Vector2f(300.f, 5.f));
	this->bossHpBar.setFillColor(sf::Color::Red);
	this->bossHpBar.setScale(-1.f, 1.f);
	this->bossHpBarBack = this->bossHpBar;
	this->bossHpBarBack.setFillColor(sf::Color(20, 20, 20, 100));

	//Init score text
	this->scoreText.setFont(this->font);
	this->scoreText.setCharacterSize(50);
	this->scoreText.setFillColor(sf::Color::White);

	//Init ultimate text
	this->ultiText.setFont(this->font);
	this->ultiText.setCharacterSize(50);
	this->ultiText.setFillColor(sf::Color::White);
}

void GameState::initSystem()
{
	this->score = 0;

	this->lastscore = this->score;

	this->cantMove = false;

	this->canUlti = false;

	this->leftUlti = false;

	this->rightUlti = false;
}


void GameState::initPlayer()
{
	this->player = new Player(0, 340, this->textures["PLAYER_SHEET"]); 
}

void GameState::initBoss()
{
	this->boss = new Boss(4000, 340, this->textures["BOSS_SHEET"]);
}


void GameState::initCoconuts()
{
	this->spawnTimerMax = 100.f;
	this->spawnTimer = this->spawnTimerMax;
}

void GameState::initMonsters()
{
	this->spawnTimerMax2 = 100.f;
	this->spawnTimer2 = this->spawnTimerMax2;
}

void GameState::initBigmons()
{
	this->spawnTimerMax3 = 300.f;
	this->spawnTimer3 = this->spawnTimerMax3;
}

void GameState::initLockwebs()
{
	this->spawnTimerMax4 = 100.f;
	this->spawnTimer4 = this->spawnTimerMax3;
}


void GameState::initBubbleTea()
{
	this->bubbletea.setSize(sf::Vector2f(159.f, 233.f));
	this->bubbletea.setTexture(&this->bubbleteaTexture);
	this->bubbletea.setPosition(1500.f, -233.f);
}


//Constructors / Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initMusic();
	this->initSFX();
	this->initTexture();
	this->initPauseMenu();
	this->initGameOver();
	this->initEndGame();

	this->initBackground();
	this->initView();
	this->initWeb();
	this->initBigdragon();

	this->initGUI();
	this->initSystem();

	this->initPlayer();
	this->initBoss();
	this->initCoconuts();
	this->initMonsters();
	this->initBigmons();
	this->initLockwebs();
	this->initBubbleTea();
}

GameState::~GameState()
{
	delete this->pmenu;

	delete this->gameover;

	delete this->endgame;

	delete this->player;

	delete this->boss;

	for (auto* i : this->coconuts)
	{
		delete i;
	}

	for (auto* i : this->monsters)
	{
		delete i;
	}

	for (auto* i : this->bigmons)
	{
		delete i;
	}

	for (auto* i : this->lockwebs)
	{
		delete i;
	}

	for (auto* i : this->attackwebs)
	{
		delete i;
	}

	for (auto* i : this->ultiwebs)
	{
		delete i;
	}

	for (auto* i : this->ultidragons)
	{
		delete i;
	}

	for (auto* i : this->yakults)
	{
		delete i;
	}
}

//Functions
void GameState::updateInput(const float& dt)
{
	if (this->player->getHp() != 0 && this->boss->getHp() != 0 && !this->player->HitboxgetBounds().intersects(this->bubbletea.getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime())
		{
			if (!this->paused)
				this->pauseState();
			else
			{
				this->unpauseState();
			}
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
		this->music.stop();
		this->endState();
		this->states->push(new MainMenuState(this->window, this->supportedKeys, this->states));
	}
}

void GameState::updateGameOverButton()
{
	this->music.stop();

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
		this->endState();
		this->states->push(new RankState(this->window, this->supportedKeys, this->states));
	}
}

void GameState::updateEndGameButton()
{
	//Last score 2
	this->lastScoreText2.setPosition(this->view.getCenter().x - this->lastScoreText2.getGlobalBounds().width, 400.f);

	std::stringstream ss;
	ss << "Your Score : " << this->lastscore;

	this->lastScoreText2.setString(ss.str());

	this->endgame->setPosition(this->view.getCenter().x - 720.f, this->view.getCenter().y - 405.f);

	this->endgame->buttonSetPosition("RANK_STATE", this->view.getCenter().x + 300, this->view.getCenter().y + 300.f);

	if (this->endgame->isButtonPressed("RANK_STATE"))
	{
		this->states->push(new RankState(this->window, this->supportedKeys, this->states));
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
	if (this->view.getCenter().x > 3600.f)
	{
		this->view.setCenter(3600.f, this->window->getSize().y / 2.f);
	}
}

void GameState::updateLongWeb()
{
	if (this->score >= 300)
	{
		this->longweb1.move(0.f, -10.f);
		this->longweb2.move(0.f, 10.f);
	}
}

void GameState::updateViewWeb()
{
	this->viewweb.setPosition(this->view.getCenter().x - 720.f, 0.f);	
}

void GameState::updateBigdragon()
{
	this->bigdragon.setPosition(this->view.getCenter().x - 720.f, 0.f);
}


void GameState::updateGUI()
{
	//Score
	this->scoreText.setPosition(this->view.getCenter().x - 250.f, 10.f);

	std::stringstream sc;
	sc << "Score : " << this->score;

	this->scoreText.setString(sc.str());

	//Ultimate
	this->ultiText.setPosition(this->view.getCenter().x + 150.f, 10.f);

	std::stringstream ul;
	ul << "Ultimate : " << this->ultimate;

	this->ultiText.setString(ul.str());

	//Player Hp Bar
	this->playerHpBar.setPosition(this->view.getCenter().x - 710, 10.f);
	this->playerHpBarBack.setPosition(this->playerHpBar.getPosition());

	float playerHpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * playerHpPercent, this->playerHpBar.getSize().y));

	//Boss Hp Bar
	this->bossHpBar.setPosition(this->view.getCenter().x + 710, 10.f);
	this->bossHpBarBack.setPosition(this->bossHpBar.getPosition());

	float bossHpPercent = static_cast<float>(this->boss->getHp()) / this->boss->getHpMax();
	this->bossHpBar.setSize(sf::Vector2f(300.f * bossHpPercent, this->bossHpBar.getSize().y));
}


void GameState::updateCollision()
{
	//Left Collision
	if (this->player->GetPosition().x < -100.f)
	{
		this->player->setPosition(-100.f, this->player->GetPosition().y);
	}
	//Right Collision
	else if (this->score < 300)
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
	if (this->score < 300.f)
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


		////Left Collision
		//if (this->coconuts[i]->GetPosition().x < 0.f)
		//{
		//	this->coconuts[i]->setPosition(0.f, this->coconuts[i]->GetPosition().y);
		//}
		////Right Collision
		//else if (this->coconuts[i]->GetPosition().x + this->coconuts[i]->getBounds().width >= 1440.f)
		//{
		//	this->coconuts[i]->setPosition(1440.f - this->coconuts[i]->getBounds().width, this->coconuts[i]->GetPosition().y);
		//}
		////Top Collision
		//if (this->coconuts[i]->GetPosition().y < 0.f)
		//{
		//	this->coconuts[i]->setPosition(this->coconuts[i]->GetPosition().x, 0.f);
		//}
		////Bottom Collision
		//else if (this->coconuts[i]->GetPosition().y + this->coconuts[i]->getBounds().height >= 810.f)
		//{
		//	this->coconuts[i]->setPosition(this->coconuts[i]->GetPosition().x, 810.f - this->coconuts[i]->getBounds().height);
		//}

		//Remove if chop the coconut
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(this->coconuts[i]->getBounds())
			&& !coconut_removed)
		{
			this->score += this->coconuts[i]->getPoints();
			this->ultimate += 1;
			this->coconutSound.play();

			this->coconuts.erase(this->coconuts.begin() + i);
			coconut_removed = true;
		}
		//Coconuts Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->coconuts[i]->getBounds()) && !coconut_removed)
		{
			this->player->loseHp(this->coconuts[i]->getDamage());
			this->playergethit.play();

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
	if (this->score < 300.f && this->boss->getHp() != 0)
	{
		this->spawnTimer2 += 0.4f;
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

		//Monster lose hp if ultimate
		for (size_t a = 0; a < this->ultidragons.size() && !monster_removed; a++)
		{
			if (this->ultidragons[a]->canAttack() && this->ultidragons[a]->getBounds().intersects(this->monsters[j]->getBounds()))
			{
				this->monsters[j]->loseHp(this->ultidragons[a]->getDamage());
				printf("NACK");
			}
		}
		//Monster lose hp if attack the monster
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(this->monsters[j]->getBounds()) 
			&& !monster_removed)
		{
			this->monsters[j]->loseHp(this->player->getDamage());
		}
		//Monster Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->monsters[j]->getBounds()) && this->monsters[j]->canAttack())
		{
			this->player->loseHp(this->monsters[j]->getDamage());
			this->playergethit.play();
		}

		//Remove if monster die
		if (this->monsters[j]->getHp() <= 0)
		{
			this->score += this->monsters[j]->getPoints();
			this->monsterSound.play();
			this->ultimate += 5;

			this->monsters.erase(this->monsters.begin() + j);
			monster_removed = true;
		}

		//Remove if boss die
		if (this->boss->getHp() <= 0)
		{
			this->monsters.erase(this->monsters.begin() + j);
			monster_removed = true;
		}
	}
}

void GameState::updateBigmonsAndCombat(const float& dt)
{
	if (this->score >= 300.f && this->boss->getHp() != 0)
	{
		this->spawnTimer3 += 0.1f;
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

		//Bigmon lose hp if ultimate
		for (size_t b = 0; b < this->ultidragons.size() && !bigmons_removed; b++)
		{
			if (this->ultidragons[b]->canAttack() && this->ultidragons[b]->getBounds().intersects(this->bigmons[k]->getBounds()))
			{
				this->bigmons[k]->loseHp(this->ultidragons[b]->getDamage());
				printf("NACKKY");
			}
		}
		//Bigmon lose hp if attack the bigmons
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(this->bigmons[k]->getBounds())
			&& !bigmons_removed )
		{
			this->bigmons[k]->loseHp(this->player->getDamage());
		}
		//Bigmons Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->bigmons[k]->getBounds()) && this->bigmons[k]->canAttack())
		{
			this->player->loseHp(this->bigmons[k]->getDamage());
			this->playergethit.play();
		}

		//Remove if bigmon die
		if (this->bigmons[k]->getHp() <= 0)
		{
			this->score += this->bigmons[k]->getPoints();
			this->bigmonSound.play();
			this->ultimate += 50;

			this->bigmons.erase(this->bigmons.begin() + k);
			bigmons_removed = true;
		}

		//Remove if boss die
		if (this->boss->getHp() <= 0)
		{
			this->bigmons.erase(this->bigmons.begin() + k);
			bigmons_removed = true;
		}
	}
}

void GameState::updateLockwebsAndCombat(const float& dt)
{
	if (this->score >= 300.f && this->boss->getHp() != 0)
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
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(this->lockwebs[l]->getBounds())
			&& !lockwebs_removed && this->cantMove)
		{
			this->lockwebs[l]->loseHp(this->player->getDamage());
		}
		//Lockweb Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->lockwebs[l]->getBounds()))
		{
			this->cantMove = true;
		}

		//Remove if lockweb die
		if (this->lockwebs[l]->getHp() <= 0)
		{
			this->score += this->lockwebs[l]->getPoints();
			this->ultimate += 2;

			this->lockwebs.erase(this->lockwebs.begin() + l);
			lockwebs_removed = true;
			this->cantMove = false;
		}

		////Remove if boss die
		//if (this->boss->getHp() <= 0)
		//{
		//	this->lockwebs.erase(this->lockwebs.begin() + l);
		//	lockwebs_removed = true;
		//}
	}
}

void GameState::updateAttackWebsAndCombat(const float& dt)
{
	if (this->score >= 300.f && this->boss->getHp() > 20 && this->boss->getHp() != 0)
	{
		this->spawnTimer += 0.2f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->attackwebs.push_back(new AttackWeb(this->boss->GetPosition().x, this->player->GetPosition().y + 250.f, this->textures["ATTACKWEB_SHEET"]));
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
		if (this->attackwebs[m]->GetPosition().y > this->player->GetPosition().y + 200.f)
		{
			this->attackwebs[m]->attackwebBackUp();
		}
		if (this->attackwebs[m]->GetPosition().y < this->player->GetPosition().y + 200.f)
		{
			this->attackwebs[m]->attackwebBackDown();
		}

		//Attackweb lose hp if ultimate
		for (size_t c = 0; c < this->ultidragons.size() && !attackweb_removed; c++)
		{
			if (this->ultidragons[c]->canAttack() && this->ultidragons[c]->getBounds().intersects(this->attackwebs[m]->getBounds()))
			{
				this->attackwebs[m]->loseHp(this->ultidragons[c]->getDamage());
				printf("NACKZA");
			}
		}
		//Attackweb lose if attack the monster
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(this->attackwebs[m]->getBounds()) 
			&& !attackweb_removed)
		{
			this->attackwebs[m]->loseHp(this->player->getDamage());
		}
		//Attackweb Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->attackwebs[m]->getBounds()) && this->attackwebs[m]->canAttack())
		{
			this->player->loseHp(this->attackwebs[m]->getDamage());
			this->playergethit.play();
		}

		//Remove if attackweb die
		if (this->attackwebs[m]->getHp() <= 0)
		{
			this->score += this->attackwebs[m]->getPoints();
			this->ultimate += 5;

			this->attackwebs.erase(this->attackwebs.begin() + m);
			attackweb_removed = true;
		}

		//Remove if boss die
		if (this->boss->getHp() <= 0)
		{
			this->attackwebs.erase(this->attackwebs.begin() + m);
			attackweb_removed = true;
		}
	}
}

void GameState::updateUltiWebsAndCombat(const float& dt)
{
	if (this->score >= 300.f && this->boss->getHp() <= 20 && this->boss->getHp() != 0)
	{
		this->spawnTimer2 += 0.2f;
		if (this->spawnTimer2 >= this->spawnTimerMax2)
		{
			this->ultiwebs.push_back(new UltiWeb(this->boss->GetPosition().x, this->player->GetPosition().y + 250.f, this->textures["ULTIWEB_SHEET"]));
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
			this->ultiwebs[n]->ultiwebBackLeft();
		}
		if (this->ultiwebs[n]->GetPosition().x < this->player->GetPosition().x + 200.f)
		{
			this->ultiwebs[n]->ultiwebBackRight();
		}
		if (this->ultiwebs[n]->GetPosition().y > this->player->GetPosition().y + 200.f)
		{
			this->ultiwebs[n]->ultiwebBackUp();
		}
		if (this->ultiwebs[n]->GetPosition().y < this->player->GetPosition().y + 200.f)
		{
			this->ultiwebs[n]->ultiwebBackDown();
		}

		//Ultiweb lose hp if ultimate
		for (size_t d = 0; d < this->ultidragons.size() && !ultiweb_removed; d++)
		{
			if (this->ultidragons[d]->canAttack() && this->ultidragons[d]->getBounds().intersects(this->ultiwebs[n]->getBounds()))
			{
				this->ultiwebs[n]->loseHp(this->ultidragons[d]->getDamage());
				printf("NACKZUZA");
			}
		}
		//Ultiweb lose if attack the ultiweb
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(this->ultiwebs[n]->getBounds())
			&& !ultiweb_removed)
		{
			this->ultiwebs[n]->loseHp(this->player->getDamage());
		}
		//Ultiweb Player Collision
		else if (this->player->HitboxgetBounds().intersects(this->ultiwebs[n]->getBounds()) && this->ultiwebs[n]->canAttack())
		{
			this->player->loseHp(this->ultiwebs[n]->getDamage());
			this->playergethit.play();
		}

		//Remove if Ultiweb die
		if (this->ultiwebs[n]->getHp() <= 0)
		{
			this->score += this->ultiwebs[n]->getPoints();
			this->ultimate += 10;

			this->ultiwebs.erase(this->ultiwebs.begin() + n);
			ultiweb_removed = true;
		}

		//Remove if boss die
		if (this->boss->getHp() <= 0)
		{
			this->ultiwebs.erase(this->ultiwebs.begin() + n);
			ultiweb_removed = true;
		}
	}
}


void GameState::updateUltimate()
{
	if (this->ultimate >= 100)
	{
		this->ultimate = 100;
		this->canUlti = true;
		if (leftUlti || rightUlti)
		{
			this->ultimateSound.play();
			this->ultimate = 0;
			this->canUlti = false;
		}
	}
}

void GameState::updateUltiDragons(const float& dt)
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("ULTIMATE"))) && this->getKeytime() && this->canUlti)
	{
		this->ultimate1Sound.play();
		this->ultimate2Sound.play();
		if (this->mousePosView.x < this->player->GetPosition().x)
		{
			this->ultidragons.push_back(new UltiDragon(this->player->GetPosition().x + 1200.f, this->player->GetPosition().y - 500.f, this->textures["ULTIDRAGON_SHEET"]));
			this->leftUlti = true;
		}
		else if (this->mousePosView.x > this->player->GetPosition().x)
		{
			this->ultidragons.push_back(new UltiDragon(this->player->GetPosition().x - 800.f, this->player->GetPosition().y - 500.f, this->textures["ULTIDRAGON_SHEET"]));
			this->rightUlti = true;
		}
	}*/

	//for (int o = 0; o < this->ultidragons.size(); ++o)
	//{
	//	bool ultidragon_removed = false;

	//	this->ultidragons[o]->update(dt);

	//	if (this->leftUlti)
	//	{
	//		this->ultidragons[o]->SetScale(-1.f, 1);
	//		this->ultidragons[o]->leftHitbox();
	//		this->ultidragons[o]->moveLeft();
	//	}
	//	else if (this->rightUlti)
	//	{
	//		this->ultidragons[o]->rightHitbox();
	//		this->ultidragons[o]->moveRight();
	//	}

	//	//Ultidragon Boss Collision
	//	if (this->boss->HitboxgetBounds().intersects(this->ultidragons[o]->getBounds()) && this->ultidragons[o]->canAttack())
	//	{
	//		this->boss->loseHp(this->ultidragons[o]->getDamage());
	//	}

	//	//Remove ultidragon at the bottom of the screen
	//	if (!ultidragon_removed)
	//	{
	//		if (this->rightUlti && this->ultidragons[o]->getBounds().left > this->window->getSize().x*3)
	//		{
	//			this->ultidragons.erase(this->ultidragons.begin() + o);

	//			this->rightUlti = false;

	//			ultidragon_removed = true;
	//		}

	//		if (this->leftUlti && this->ultidragons[o]->getBounds().left < -1000.f)
	//		{
	//			this->ultidragons.erase(this->ultidragons.begin() + o);

	//			this->leftUlti = false;

	//			ultidragon_removed = true;
	//		}
	//	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("LEFTULTIMATE"))) && this->getKeytime() && this->canUlti)
	{
		this->ultidragons.push_back(new UltiDragon(this->player->GetPosition().x + 1200.f, this->player->GetPosition().y - 400.f, this->textures["ULTIDRAGON_SHEET"]));
		this->leftUlti = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("RIGHTULTIMATE"))) && this->getKeytime() && this->canUlti)
	{
		this->ultidragons.push_back(new UltiDragon(this->player->GetPosition().x - 800.f, this->player->GetPosition().y - 400.f, this->textures["ULTIDRAGON_SHEET"]));
		this->rightUlti = true;
	}

	unsigned counter = 0;
	for (auto* ultidragon : this->ultidragons)
	{
		ultidragon->update(dt);

		if (this->leftUlti)
		{
			ultidragon->SetScale(-1.f, 1);
			ultidragon->leftHitbox();
			ultidragon->moveLeft();
		}
		else if (this->rightUlti)
		{
			ultidragon->rightHitbox();
			ultidragon->moveRight();
		}

		//Remove ultidragon
		if (this->rightUlti && ultidragon->getBounds().left > this->window->getSize().x * 3)
			{
				delete this->ultidragons.at(counter);
				this->ultidragons.erase(this->ultidragons.begin() + counter);
				--counter;

				this->rightUlti = false;
			}
			//Remove ultidragon
			if (this->leftUlti && ultidragon->getBounds().left < 500.f)
			{
				delete this->ultidragons.at(counter);
				this->ultidragons.erase(this->ultidragons.begin() + counter);
				--counter;

				this->leftUlti = false;
			}

			++counter;
		}

		////Remove if boss die
		//if (this->boss->getHp() <= 0)
		//{
		//	this->ultiwebs.erase(this->ultiwebs.begin() + n);
		//	ultiweb_removed = true;
		//}
//	}
}


//void GameState::updateYakults(const float& dt)
//{
//	if (this->score >= 100.f)
//	{
//		if (this->boss->getHp() == 80.f)
//		{
//			this->yakults.push_back(new Yakult(4000.f, 340.f, this->textures["YAKULT_SHEET"]));
//		}
//		else if (this->boss->getHp() == 60.f)
//		{
//			this->yakults.push_back(new Yakult(860.f, 250.f, this->textures["YAKULT_SHEET"]));
//		}
//		else if (this->boss->getHp() == 40.f)
//		{
//			this->yakults.push_back(new Yakult(3000.f, 400.f, this->textures["YAKULT_SHEET"]));
//		}
//		else if (this->boss->getHp() == 20.f)
//		{
//			this->yakults.push_back(new Yakult(100.f, 300.f, this->textures["YAKULT_SHEET"]));
//		}
//	}
//
//	for (int p = 0; p < this->yakults.size(); ++p)
//	{
//		bool yakult_removed = false;
//
//		this->yakults[p]->update(dt);
//
//		//Yakults Player Collision
//		if (this->player->HitboxgetBounds().intersects(this->yakults[p]->getBounds()) && !yakult_removed)
//		{
//			this->player->gainHp(this->yakults[p]->getHeal());
//			this->yakultSound.play();
//
//			this->yakults.erase(this->yakults.begin() + p);
//			yakult_removed = true;
//
//		}
//	}
//}


void GameState::updateBossAndCombat(const float& dt)
{
	
	this->boss->update(dt);

	if (this->boss->getHp() > 600 && this->boss->getHp() <= 800)
	{
		this->boss->setPosition(860, 250);
	}
	if (this->boss->getHp() > 400 && this->boss->getHp() <= 600)
	{
		this->boss->setPosition(3000, 400);
	}
	if (this->boss->getHp() > 200 && this->boss->getHp() <= 400)
	{
		this->boss->setPosition(100, 300);
	}
	if (this->boss->getHp() <= 200)
	{
		this->boss->setPosition(1500, 250);
	}

	//Monster lose hp if ultimate
	for (size_t e = 0; e < this->ultidragons.size() ; e++)
	{
		if (this->ultidragons[e]->canAttack() && this->ultidragons[e]->getBounds().intersects(this->boss->getBounds()))
		{
			this->boss->loseHp(this->ultidragons[e]->getDamage());
			printf("NACKlnwza");
		}
	}
	//Boss lose if attack the boss
	if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(this->boss->HitboxgetBounds()))
	{
		this->boss->loseHp(this->player->getDamage());
	}
	//Boss Player Collision
	else if(this->boss->getHp() > 0)
	{
		if (this->player->HitboxgetBounds().intersects(this->boss->HitboxgetBounds()) && this->boss->canAttack())
		{
			this->player->loseHp(this->boss->getDamage());
			this->playergethit.play();
		}
	}

	if (this->boss->getHp() == 0)
	{
		/*this->score += this->boss->getPoints();*/
		this->bossDieSound.play();
		this->music.stop();
	}
}

void GameState::updateBubbleTea()
{
	this->bubbletea.move(0.f, 5.f);

	//Bottom Collision
	if (this->bubbletea.getPosition().y + this->bubbletea.getGlobalBounds().height >= 500.f)
	{
	this->bubbletea.setPosition(this->bubbletea.getPosition().x, 500.f - this->bubbletea.getGlobalBounds().height);
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateKeytime(dt);
	this->updateInput(dt);
	
	if (!this->paused && this->player->getHp() != 0 && !this->player->HitboxgetBounds().intersects(this->bubbletea.getGlobalBounds())) //Unpause update
	{
		this->updatePlayerInput(dt);

		this->updateView();

		if(this->longweb1.getPosition().y > -550.f)
			this->updateLongWeb();
		else
			this->updateViewWeb();
		
		this->updateBigdragon();

		this->player->update(dt);

		this->updateCollision();

		this->updateCoconutsAndCombat(dt);
		this->updateMonstersAndCombat(dt);
		this->updateBigmonsAndCombat(dt);
		this->updateLockwebsAndCombat(dt);
		this->updateAttackWebsAndCombat(dt);
		this->updateUltiWebsAndCombat(dt);

		this->updateUltimate();
		this->updateUltiDragons(dt);

		/*this->updateYakults(dt);*/

		this->updateBossAndCombat(dt);
		if (this->boss->getHp() <= 0)
			this->updateBubbleTea();

		this->updateGUI();
	}
	else //Pause update
	{
		if (this->player->getHp() != 0 && this->boss->getHp() != 0)
		{
			this->pmenu->update(this->mousePosView);

			this->updatePauseMenuButtons();
		}
		else if(this->player->getHp() == 0)
		{
			this->gameover->update(this->mousePosView);

			this->updateGameOverButton();
		}
		else if (this->player->HitboxgetBounds().intersects(this->bubbletea.getGlobalBounds()))
		{
			this->endgame->update(this->mousePosView);

			this->updateEndGameButton();
		}
	}
}


void GameState::renderGUI()
{
	this->window->draw(this->scoreText);
	this->window->draw(this->ultiText);

	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);

	if (this->score >= 300.f)
	{
		this->window->draw(this->bossHpBarBack);
		this->window->draw(this->bossHpBar);
	}
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

	//Bigdragon
	if (this->canUlti)
	{
		target->draw(this->bigdragon);
	}

	//Boss
	this->boss->render(*target);

	//Player
	this->player->render(*target);
	
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

	//Ultidragon
	for (auto* ultidragon : this->ultidragons)
	{
		ultidragon->render(*target);
	}

	//Yakult
	for (auto* yakult : this->yakults)
	{
		yakult->render(*target);
	}

	//BubbleTea
	target->draw(this->bubbletea);

	//GUI
	this->renderGUI();

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

	//End Game
	if (this->player->HitboxgetBounds().intersects(this->bubbletea.getGlobalBounds()))
	{
		this->endgame->render(*target);
		this->window->draw(this->lastScoreText2);
	}
}
