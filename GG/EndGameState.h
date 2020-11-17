#ifndef ENDGAMESTATE_H
#define ENDGAME_H

#include "GameState.h"
#include "Button.h"

class EndGame :
    public State
{
private:
    //View
    sf::View view;

    //Background
    sf::Texture backgroundTexture;
    sf::RectangleShape background;

    //Variables
    sf::Texture button1idleTexture;
    sf::Texture button1hoverTexture;
    sf::Texture button1activeTexture;

    /*sf::Texture button2idleTexture;
    sf::Texture button2hoverTexture;
    sf::Texture button2activeTexture;

    sf::Texture button3idleTexture;
    sf::Texture button3hoverTexture;
    sf::Texture button3activeTexture;*/

    std::map<std::string, Button*> buttons;

    //Function
    void initVariable();
    void initBackground();
    void initView();
    void initKeybinds();
    void initButton();

public:
    EndGame(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~EndGame();

    //Functions
    void updateInput(const float& dt);
    void updateView();
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = NULL);
};
#endif
