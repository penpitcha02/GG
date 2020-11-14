#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState :
    public State
{
private:
    //View
    sf::View view;

    //Background
    sf::Texture backgroundTexture;
    sf::RectangleShape background;

    //GUI
    sf::Font font;
    sf::Text pointText;

    //Player
    Player* player;

    //Shop
    sf::Texture shopTexture;
    sf::RectangleShape shop;

    //PlayerGUI
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;
    
    //Coconuts
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Coconut*> coconuts;

    //System
    unsigned points;

    //Function
    void initKeybinds();
    void initTexture();
    void initBackground();
    void initView();
    void initGUI();
    void initSystem();

    void initPlayers();
    void initCoconuts();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void updateInput(const float& dt);
    void updateView();
    void updateGUI();
    void updateCollision();
    void updateCoconutsAndCombat();
    void update(const float& dt);
    void renderGUI();
    void render(sf::RenderTarget* target = NULL);
};
#endif 
