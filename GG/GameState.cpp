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
	if (!this->button1idleTexture.loadFromFile("img/menubutton/QuitButton1.png"))
		printf("LOAD BUTTON 1 IDLE MAI DAI AAAAAAA");

	if (!this->button1hoverTexture.loadFromFile("img/menubutton/QuitButtonHighlight1.png"))
		printf("LOAD BUTTON 1 HOVER MAI DAI AAAAAAA");

	if (!this->button1activeTexture.loadFromFile("img/menubutton/QuitButtonPressed1.png"))
		printf("LOAD BUTTON 1 ACTIVE MAI DAI AAAAAAA");

	//Game Over
	if (!this->button2idleTexture.loadFromFile("img/menubutton/QuitButton1.png"))
		printf("LOAD BUTTON 2 IDLE MAI DAI AAAAAAA");

	if (!this->button2hoverTexture.loadFromFile("img/menubutton/QuitButtonHighlight1.png"))
		printf("LOAD BUTTON 2 HOVER MAI DAI AAAAAAA");

	if (!this->button2activeTexture.loadFromFile("img/menubutton/QuitButtonPressed1.png"))
		printf("LOAD BUTTON 2 ACTIVE MAI DAI AAAAAAA");

	//End Game
	if (!this->button3idleTexture.loadFromFile("img/menubutton/QuitButton1.png"))
		printf("LOAD BUTTON 3 IDLE MAI DAI AAAAAAA");

	if (!this->button3hoverTexture.loadFromFile("img/menubutton/QuitButtonHighlight1.png"))
		printf("LOAD BUTTON 3 HOVER MAI DAI AAAAAAA");

	if (!this->button3activeTexture.loadFromFile("img/menubutton/QuitButtonPressed1.png"))
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
	this->lastScoreText.setCharacterSize(100);
	this->lastScoreText.setFillColor(sf::Color::White);
}

void GameState::initEndGame()
{
	this->endgame = new EndGame(*this->window);

	this->endgame->addButton("RANK_STATE", &this->button3idleTexture, &this->button3hoverTexture, &this->button3activeTexture);

	//Init  last score text 2
	this->lastScoreText2.setFont(this->font);
	this->lastScoreText2.setCharacterSize(100);
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
	this->spawnTimer4 = this->spawnTimerMax4;
}

void GameState::initYakults()
{
	this->spawnTimerMax5 = 100.f;
	this->spawnTimer5 = this->spawnTimerMax5;
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

	this->initYakults();

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
		this->states->push(new MainMenuState(this->window, this->supportedKeys, this->states));
		this->endState();
	}
}

void GameState::updateGameOverButton()
{
	//Last score
	this->lastScoreText.setPosition(this->view.getCenter().x - this->lastScoreText.getGlobalBounds().width/2, 300.f);

	std::stringstream ss;
	ss << "Your Score : " << this->score;

	this->lastScoreText.setString(ss.str());

	this->gameover->textSetPosition(this->view.getCenter().x - 300.f, this->view.getCenter().y - 300.f);

	this->gameover->buttonSetPosition("RANK_STATE", this->view.getCenter().x - 86.25, this->view.getCenter().y + 200.f);

	if (this->gameover->isButtonPressed("RANK_STATE"))
	{
		this->music.stop();
		this->states->push(new RankState(this->window, this->supportedKeys, this->states));
		this->endState();
	}
}

void GameState::updateEndGameButton()
{
	//Last score 2
	this->lastScoreText2.setPosition(this->view.getCenter().x - this->lastScoreText2.getGlobalBounds().width/2, 550.f);

	std::stringstream ss;
	ss << "Your Score : " << this->score;

	this->lastScoreText2.setString(ss.str());

	this->endgame->setPosition(this->view.getCenter().x - 620.f, this->view.getCenter().y - 355.f);

	this->endgame->buttonSetPosition("RANK_STATE", this->view.getCenter().x + 400, this->view.getCenter().y + 250.f);

	if (this->endgame->isButtonPressed("RANK_STATE"))
	{
		this->music.stop();
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
		this->spawnTimer += 0.5f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->coconuts.push_back(new Coconut(rand() % this->window->getSize().x, -100.f, this->textures["COCONUTS_SHEET"]));
			this->spawnTimer = 0.f;
		}
	}

	//for (int i = 0; i < this->coconuts.size(); ++i)
	//{
	//	bool coconut_removed = false;

	//	this->coconuts[i]->update(dt);

	//	//Coconuts Follow Player
	//	if (this->coconuts[i]->GetPosition().x > this->player->GetPosition().x + 200.f)
	//	{
	//		this->coconuts[i]->coconutBackLeft();
	//	}
	//	if (this->coconuts[i]->GetPosition().x < this->player->GetPosition().x + 200.f)
	//	{
	//		this->coconuts[i]->coconutBackRight();
	//	}
	//	if (this->coconuts[i]->GetPosition().y > this->player->GetPosition().y)
	//	{
	//		this->coconuts[i]->coconutBackUp();
	//	}
	//	if (this->coconuts[i]->GetPosition().y < this->player->GetPosition().y)
	//	{
	//		this->coconuts[i]->coconutBackDown();
	//	}


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

		////Remove if chop the coconut
		//if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(this->coconuts[i]->getBounds())
		//	&& !coconut_removed)
		//{
		//	this->score += this->coconuts[i]->getPoints();
		//	this->ultimate += 1;
		//	this->coconutSound.play();

		//	this->coconuts.erase(this->coconuts.begin() + i);
		//	coconut_removed = true;
		//}
		////Coconuts Player Collision
		//else if (this->player->HitboxgetBounds().intersects(this->coconuts[i]->getBounds()) && !coconut_removed)
		//{
		//	this->player->loseHp(this->coconuts[i]->getDamage());
		//	this->playergethit.play();

		//	this->coconuts.erase(this->coconuts.begin() + i);
		//	coconut_removed = true;
		//	
		//}

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
	/*}*/
	unsigned counter = 0;
	for (auto* coconut : this->coconuts)
	{
		coconut->update(dt);

		//Coconuts Follow Player
		if (coconut->GetPosition().x > this->player->GetPosition().x + 200.f)
		{
			coconut->coconutBackLeft();
		}
		if (coconut->GetPosition().x < this->player->GetPosition().x + 200.f)
		{
			coconut->coconutBackRight();
		}
		if (coconut->GetPosition().y > this->player->GetPosition().y)
		{
			coconut->coconutBackUp();
		}
		if (coconut->GetPosition().y < this->player->GetPosition().y)
		{
			coconut->coconutBackDown();
		}

		//Remove if chop the coconut
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(coconut->getBounds()))
		{
			this->score += coconut->getPoints();
			this->ultimate += 1;
			this->coconutSound.play();

			delete this->coconuts.at(counter);
			this->coconuts.erase(this->coconuts.begin() + counter);
			--counter;
		}
		//Coconuts Player Collision
		else if (this->player->HitboxgetBounds().intersects(coconut->getBounds()))
		{
			this->player->loseHp(coconut->getDamage());
			this->playergethit.play();

			delete this->coconuts.at(counter);
			this->coconuts.erase(this->coconuts.begin() + counter);
			--counter;
		}

		++counter;
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

	unsigned counter = 0;
	for (auto* monster : this->monsters)
	{
		monster->update(dt);

		//Monster Follow Player
		if (monster->GetPosition().x > this->player->GetPosition().x + 200.f)
		{
			monster->monsterBackLeft();
		}
		if (monster->GetPosition().x < this->player->GetPosition().x + 200.f)
		{
			monster->monsterBackRight();
		}
		if (monster->GetPosition().y > this->player->GetPosition().y + 150.f)
		{
			monster->monsterBackUp();
		}
		if (monster->GetPosition().y < this->player->GetPosition().y + 150.f)
		{
			monster->monsterBackDown();
		}

		//Monster lose hp if attack the monster
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(monster->getBounds()))
		{
			monster->loseHp(this->player->getDamage());
		}
		//Monster Player Collision
		else if (this->player->HitboxgetBounds().intersects(monster->getBounds()) && monster->canAttack())
		{
			this->player->loseHp(monster->getDamage());
			this->playergethit.play();
		}

		//Remove if monster die
		if (monster->getHp() <= 0)
		{
			this->score += monster->getPoints();
			this->ultimate += 10;
			this->monsterSound.play();

			delete this->monsters.at(counter);
			this->monsters.erase(this->monsters.begin() + counter);
			--counter;
		}
		//Remove if boss die
		if (this->boss->getHp() <= 0)
		{
			delete this->monsters.at(counter);
			this->monsters.erase(this->monsters.begin() + counter);
			--counter;
		}

		++counter;
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

	unsigned counter = 0;
	for (auto* bigmon : this->bigmons)
	{
		bigmon->update(dt);

		//Bigmon Follow Player
		if (bigmon->GetPosition().x > this->player->GetPosition().x + 200.f)
		{
			bigmon->bigmonsBackLeft();
		}
		if (bigmon->GetPosition().x < this->player->GetPosition().x + 200.f)
		{
			bigmon->bigmonsBackRight();
		}
		if (bigmon->GetPosition().y > this->player->GetPosition().y + 150.f)
		{
			bigmon->bigmonsBackUp();
		}
		if (bigmon->GetPosition().y < this->player->GetPosition().y + 150.f)
		{
			bigmon->bigmonsBackDown();
		}

		//Bigmon lose hp if attack the monster
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(bigmon->getBounds()))
		{
			bigmon->loseHp(this->player->getDamage());
		}
		//Bigmon Player Collision
		else if (this->player->HitboxgetBounds().intersects(bigmon->getBounds()) && bigmon->canAttack())
		{
			this->player->loseHp(bigmon->getDamage());
			this->playergethit.play();
		}

		//Remove if Bigmon die
		if (bigmon->getHp() <= 0)
		{
			this->score += bigmon->getPoints();
			this->ultimate += 50;
			this->bigmonSound.play();

			delete this->bigmons.at(counter);
			this->bigmons.erase(this->bigmons.begin() + counter);
			--counter;
		}
		//Remove if boss die
		if (this->boss->getHp() <= 0)
		{
			delete this->bigmons.at(counter);
			this->bigmons.erase(this->bigmons.begin() + counter);
			--counter;
		}

		++counter;
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
	if (this->score >= 300.f && this->boss->getHp() > 200 && this->boss->getHp() != 0)
	{
		this->spawnTimer += 0.5f;
		if (this->spawnTimer >= this->spawnTimerMax)
		{
			this->attackwebs.push_back(new AttackWeb(this->boss->GetPosition().x, this->player->GetPosition().y + 250.f, this->textures["ATTACKWEB_SHEET"]));
			this->spawnTimer = 0.f;
		}
	}

	unsigned counter = 0;
	for (auto* attackweb : this->attackwebs)
	{
		attackweb->update(dt);

		//Attackweb Follow Player
		if (attackweb->GetPosition().x > this->player->GetPosition().x + 150.f)
		{
			attackweb->attackwebBackLeft();
		}
		if (attackweb->GetPosition().x < this->player->GetPosition().x + 150.f)
		{
			attackweb->attackwebBackRight();
		}
		if (attackweb->GetPosition().y > this->player->GetPosition().y + 150.f)
		{
			attackweb->attackwebBackUp();
		}
		if (attackweb->GetPosition().y < this->player->GetPosition().y + 150.f)
		{
			attackweb->attackwebBackDown();
		}

		//Attackweb lose hp if attack the monster
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(attackweb->getBounds()))
		{
			attackweb->loseHp(this->player->getDamage());
		}
		//Attackweb Player Collision
		else if (this->player->HitboxgetBounds().intersects(attackweb->getBounds()) && attackweb->canAttack())
		{
			this->player->loseHp(attackweb->getDamage());
			this->playergethit.play();
		}

		//Remove if Attackweb die
		if (attackweb->getHp() <= 0)
		{
			this->score += attackweb->getPoints();
			this->ultimate += 5;
			/*this->bigmonSound.play();*/

			delete this->attackwebs.at(counter);
			this->attackwebs.erase(this->attackwebs.begin() + counter);
			--counter;
		}
		//Remove if boss die
		if (this->boss->getHp() <= 0)
		{
			delete this->attackwebs.at(counter);
			this->attackwebs.erase(this->attackwebs.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void GameState::updateUltiWebsAndCombat(const float& dt)
{
	if (this->score >= 300 && this->boss->getHp() <= 200 && this->boss->getHp() != 0)
	{
		this->spawnTimer2 += 0.5f;
		if (this->spawnTimer2 >= this->spawnTimerMax2)
		{
			this->ultiwebs.push_back(new UltiWeb(this->boss->GetPosition().x, this->player->GetPosition().y + 250.f, this->textures["ULTIWEB_SHEET"]));
			this->spawnTimer2 = 0.f;
		}
	}

	unsigned counter = 0;
	for (auto* ultiweb : this->ultiwebs)
	{
		ultiweb->update(dt);

		//Ultiweb Follow Player
		if (ultiweb->GetPosition().x > this->player->GetPosition().x + 150.f)
		{
			ultiweb->ultiwebBackLeft();
		}
		if (ultiweb->GetPosition().x < this->player->GetPosition().x + 150.f)
		{
			ultiweb->ultiwebBackRight();
		}
		if (ultiweb->GetPosition().y > this->player->GetPosition().y + 150.f)
		{
			ultiweb->ultiwebBackUp();
		}
		if (ultiweb->GetPosition().y < this->player->GetPosition().y + 150.f)
		{
			ultiweb->ultiwebBackDown();
		}

		//Ultiweb lose hp if attack the monster
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(ultiweb->getBounds()))
		{
			ultiweb->loseHp(this->player->getDamage());
		}
		//Ultiweb Player Collision
		else if (this->player->HitboxgetBounds().intersects(ultiweb->getBounds()) && ultiweb->canAttack())
		{
			this->player->loseHp(ultiweb->getDamage());
			this->playergethit.play();
		}

		//Remove if Ultiweb die
		if (ultiweb->getHp() <= 0)
		{
			this->score += ultiweb->getPoints();
			this->ultimate += 10;
			/*this->bigmonSound.play();*/

			delete this->ultiwebs.at(counter);
			this->ultiwebs.erase(this->ultiwebs.begin() + counter);
			--counter;
		}
		//Remove if boss die
		if (this->boss->getHp() <= 0)
		{
			delete this->ultiwebs.at(counter);
			this->ultiwebs.erase(this->ultiwebs.begin() + counter);
			--counter;
		}

		++counter;
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
			this->ultimate = 0;
			this->canUlti = false;
		}
	}
}

void GameState::updateUltiDragons(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("LEFTULTIMATE"))) && this->getKeytime() && this->canUlti)
	{
		this->ultidragons.push_back(new UltiDragon(this->player->GetPosition().x + 1200.f, this->player->GetPosition().y - 400.f, this->textures["ULTIDRAGON_SHEET"]));
		this->ultimateSound.play();
		this->leftUlti = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("RIGHTULTIMATE"))) && this->getKeytime() && this->canUlti)
	{
		this->ultidragons.push_back(new UltiDragon(this->player->GetPosition().x - 800.f, this->player->GetPosition().y - 400.f, this->textures["ULTIDRAGON_SHEET"]));
		this->ultimateSound.play();
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
		if (this->leftUlti && ultidragon->getBounds().left < -1000.f)
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

void GameState::updateUltiDragonsAndCombat(const float& dt)
{
	/*if (this->score >= 300)
	{*/
		for (size_t a = 0; a < this->ultidragons.size(); a++)
		{
			//Coconut
			for (size_t i = 0; i < this->coconuts.size(); ++i)
			{
				bool coconut_removed = false;
				if (this->ultidragons[a]->getBounds().intersects(this->coconuts[i]->getBounds()) && !coconut_removed)
				{
					this->score += coconuts[i]->getPoints();
					this->coconutSound.play();

					delete this->coconuts[i];
					coconuts.erase(this->coconuts.begin() + i);
					
					printf("Nack\n");
				}
			}
			//Monster
			for (size_t j = 0; j < this->monsters.size(); ++j)
			{
				bool monster_removed = false;
				if (this->ultidragons[a]->getBounds().intersects(this->monsters[j]->getBounds()) && !monster_removed)
				{
					this->score += monsters[j]->getPoints();
					this->monsterSound.play();

					delete this-> monsters[j];
					monsters.erase(this->monsters.begin() + j);

					printf("Snack\n");
				}
			}
			//Bigmon
			for (size_t k = 0; k < this->bigmons.size(); ++k)
			{
				if (this->ultidragons[a]->canAttack() && this->ultidragons[a]->getBounds().intersects(this->bigmons[k]->getBounds()))
				{
					this->bigmons[k]->loseHp(this->ultidragons[a]->getDamage());
					printf("Nackky\n");
				}
			}
			//Attackweb
			for (size_t l = 0; l < this->attackwebs.size(); ++l)
			{
				if (this->ultidragons[a]->canAttack() && this->ultidragons[a]->getBounds().intersects(this->attackwebs[l]->getBounds()))
				{
					this->attackwebs[l]->loseHp(this->ultidragons[a]->getDamage());
					printf("Nackzass\n");
				}
			}
			//Ultiweb
			for (size_t m = 0; m < this->ultiwebs.size(); ++m)
			{
				if (this->ultidragons[a]->canAttack() && this->ultidragons[a]->getBounds().intersects(this->ultiwebs[m]->getBounds()))
				{
					this->ultiwebs[m]->loseHp(this->ultidragons[a]->getDamage());
					printf("Nackzuza\n");
				}
			}

			if (this->score >= 300)
			{
				if (this->ultidragons[a]->canAttack() && this->ultidragons[a]->getBounds().intersects(this->boss->getBounds()))
				{
					this->boss->loseHp(this->ultidragons[a]->getDamage());
					printf("NACKlnwza\n");
				}
			}
		}
	/*}*/
}


void GameState::updateYakults(const float& dt)
{
	if (this->score >= 300 && this->boss->getHp() != 0)
	{
		this->spawnTimer5 += 0.1f;
		if (this->spawnTimer5 >= this->spawnTimerMax5)
		{
			this->yakults.push_back(new Yakult(rand() % this->window->getSize().x*3, this->player->GetPosition().y + 100,
				this->textures["YAKULT_SHEET"]));
			this->spawnTimer5 = 0.f;
		}
	}

	for (int p = 0; p < this->yakults.size(); ++p)
	{
		bool yakult_removed = false;

		this->yakults[p]->update(dt);

		//Yakults Player Collision
		if (this->player->HitboxgetBounds().intersects(this->yakults[p]->getBounds()) && !yakult_removed)
		{
			this->player->gainHp(this->yakults[p]->getHeal());
			this->yakultSound.play();

			this->yakults.erase(this->yakults.begin() + p);
			yakult_removed = true;
		}
	}
}


void GameState::updateBossAndCombat(const float& dt)
{
	if (this->score >= 300.f)
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

		////Monster lose hp if ultimate
		//for (size_t e = 0; e < this->ultidragons.size(); e++)
		//{
		//	if (this->ultidragons[e]->canAttack() && this->ultidragons[e]->getBounds().intersects(this->boss->getBounds()))
		//	{
		//		this->boss->loseHp(this->ultidragons[e]->getDamage());
		//		printf("NACKlnwza\n");
		//	}
		//}
		//Boss lose if attack the boss
		if (this->player->isAttacking() && this->player->CutboxgetBounds().intersects(this->boss->HitboxgetBounds()))
		{
			this->boss->loseHp(this->player->getDamage());
		}
		//Boss Player Collision
		if (this->player->HitboxgetBounds().intersects(this->boss->HitboxgetBounds()) && this->boss->canAttack())
		{
			this->player->loseHp(this->boss->getDamage());
			this->playergethit.play();
		}

		if (this->boss->getHp() == 0)
		{
			/*this->score += this->boss->getPoints();*/
		}
	}
}

void GameState::updateBubbleTea()
{
	if (this->boss->getHp() <= 0)
	{
		this->bubbletea.move(0.f, 5.f);

		//Bottom Collision
		if (this->bubbletea.getPosition().y + this->bubbletea.getGlobalBounds().height >= 500.f)
		{
			this->bubbletea.setPosition(this->bubbletea.getPosition().x, 500.f - this->bubbletea.getGlobalBounds().height);
		}
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateKeytime(dt);
	this->updateInput(dt);
	this->music.setLoop(true);

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
		this->updateUltiDragonsAndCombat(dt);

		this->updateYakults(dt);

		this->updateBossAndCombat(dt);
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
