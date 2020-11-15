#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"

class GameState :
    public State
{
private:
    //Pause Menu
    PauseMenu* pmenu;

    //View
    sf::View view;

    //Pause Menu
    sf::Texture button1idleTexture;
    sf::Texture button1hoverTexture;
    sf::Texture button1activeTexture;

    //Background
    sf::Texture backgroundTexture;
    sf::RectangleShape background;

    //GUI
    sf::Font font;
    sf::Text pointText;
    sf::Text gameOverText;

    //Player
    Player* player;

    //PlayerGUI
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    //BigmonsGUI
    /*sf::RectangleShape bigmonsHpBar;
    sf::RectangleShape bigmonsHpBarBack;*/
    
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


    //System
    unsigned points;

    //Function
    void initKeybinds();
    void initTexture();
    void initPauseMenu();
    void initBackground();
    void initView();
    void initGUI();
    void initSystem();

    void initPlayers();
    void initCoconuts();
    void initMonsters();
    void initBigmons();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void updateInput(const float& dt);
    void updatePlayerInput(const float& dt);
    void updatePauseMenuButtons();

    void updateView();
    void updateGUI();

    void updateCollision();
    void updateCoconutsAndCombat(const float& dt);
    void updateMonstersAndCombat(const float& dt);
    void updateBigmonsAndCombat(const float& dt);

    void update(const float& dt);
    void renderGUI();
    void render(sf::RenderTarget* target = NULL);
};
#endif 
