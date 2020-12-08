#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "RankState.h"
#include "PauseMenu.h"
#include "GameOver.h"
#include "EndGame.h"

class GameState :
    public State
{
private:
    //View
    sf::View view;

    //Music
    sf::Music music;

    //SFX
    sf::SoundBuffer playergethitBuffer;
    sf::Sound playergethit;
    sf::SoundBuffer ultimateSoundBuffer;
    sf::Sound ultimateSound;

    sf::SoundBuffer coconutSoundBuffer;
    sf::Sound coconutSound;
    sf::SoundBuffer monsterSoundBuffer;
    sf::Sound monsterSound;
    sf::SoundBuffer bigmonSoundBuffer;
    sf::Sound bigmonSound;

    sf::SoundBuffer bossDieSoundBuffer;
    sf::Sound bossDieSound;
    
    //Pause Menu
    PauseMenu* pmenu;
    //Pause Menu Button
    sf::Texture button1idleTexture;
    sf::Texture button1hoverTexture;
    sf::Texture button1activeTexture;

    //Game Over
    GameOver* gameover;
    sf::Text lastScoreText;
    //Game Over Button
    sf::Texture button2idleTexture;
    sf::Texture button2hoverTexture;
    sf::Texture button2activeTexture;

    //End Game
    EndGame* endgame;
    sf::Text lastScoreText2;
    //Game Over Button
    sf::Texture button3idleTexture;
    sf::Texture button3hoverTexture;
    sf::Texture button3activeTexture;

    //Background
    sf::Texture backgroundTexture;
    sf::RectangleShape background;

    //Web
    sf::Texture longweb1Texture;
    sf::RectangleShape longweb1;
    sf::Texture longweb2Texture;
    sf::RectangleShape longweb2;
    sf::Texture viewwebTexture;
    sf::RectangleShape viewweb;

    //Bigdragon
    sf::Texture bigdragonTexture;
    sf::RectangleShape bigdragon;

    //GUI
    sf::Font font;
    sf::Text scoreText;
    sf::Text ultiText;

    //Player
    Player* player;

    //PlayerGUI
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    //Boss
    Boss* boss;

    //BossGUI
    sf::RectangleShape bossHpBar;
    sf::RectangleShape bossHpBarBack;
    
    //Coconuts
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Coconut*> coconuts;

    //Monsters
    float spawnTimer2;
    float spawnTimerMax2;
    std::vector<Monster*> monsters;

    //Bigmons
    float spawnTimer3;
    float spawnTimerMax3;
    std::vector<BigMons*> bigmons;

    //LockWebs
    float spawnTimer4;
    float spawnTimerMax4;
    std::vector<LockWeb*> lockwebs;

    //Attackwebs
    std::vector<AttackWeb*> attackwebs;

    //Ultiwebs
    std::vector<UltiWeb*> ultiwebs;

    //Ultidragons
    std::vector<UltiDragon*> ultidragons;

    //Yakult
    std::vector<Yakult*> yakults;

    //BubbleTea
    sf::Texture bubbleteaTexture;
    sf::RectangleShape bubbletea;

    //System
    unsigned score; 
    unsigned lastscore;
    unsigned ultimate;
    bool cantMove;
    bool canUlti;
    bool leftUlti;
    bool rightUlti;
   
    //Function
    void initKeybinds();
    void initMusic();
    void initSFX();
    void initTexture();
    void initPauseMenu();
    void initGameOver();
    void initEndGame();

    void initBackground();
    void initView();
    void initWeb();
    void initBigdragon();

    void initGUI();
    void initSystem();

    void initPlayer();
    void initBoss();

    void initCoconuts();
    void initMonsters();
    void initBigmons();
    void initLockwebs();

    void initBubbleTea();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void updateInput(const float& dt);
    void updatePlayerInput(const float& dt);
    void updatePauseMenuButtons();
    void updateGameOverButton();
    void updateEndGameButton();

    void updateView();
    void updateLongWeb();
    void updateViewWeb();
    void updateBigdragon();
    
    void updateGUI();
    void updateCollision();

    void updateCoconutsAndCombat(const float& dt);
    void updateMonstersAndCombat(const float& dt);
    void updateBigmonsAndCombat(const float& dt);
    void updateLockwebsAndCombat(const float& dt);
    void updateAttackWebsAndCombat(const float& dt);
    void updateUltiWebsAndCombat(const float& dt);

    void updateUltimate();
    void updateUltiDragonsAndCombat(const float& dt);

    void updateYakults(const float& dt);

    void updateBossAndCombat(const float& dt);
    void updateBubbleTea();

    void update(const float& dt);
    void renderGUI();
    void render(sf::RenderTarget* target = NULL);
};

#endif 
