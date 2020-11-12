#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState :
    public State
{
private:
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Texture shopTexture;
    sf::RectangleShape shop;

    Player* player;

    //Function
    void initKeybinds();
    void initTexture();
    void initBackground();

    void initPlayers();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};
#endif 
