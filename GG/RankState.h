#ifndef RANKSTATE_H
#define RANKSTATE_H

#include"State.h"
#include"MainMenuState.h"
#include "Button.h"

class RankState :
    public State
{
private:
    //View
    sf::View view;

    //Music
    sf::Music music;

    //Fade
    sf::RectangleShape fade;

    //Background
    sf::Texture backgroundTexture;
    sf::RectangleShape background;

    //Shop
    sf::Texture shopTexture;
    sf::RectangleShape shop;


    ////Variables
    //sf::Texture button1idleTexture;
    //sf::Texture button1hoverTexture;
    //sf::Texture button1activeTexture;

    //sf::Texture button2idleTexture;
    //sf::Texture button2hoverTexture;
    //sf::Texture button2activeTexture;

    sf::Texture button3idleTexture;
    sf::Texture button3hoverTexture;
    sf::Texture button3activeTexture;

    std::map<std::string, Button*> buttons;

    //Function
    void initVariable();
    void initMusic();
    void initBackground();
    void initView();
    void initKeybinds();
    void initButton();

public:
    RankState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~RankState();

    //Functions
    void updateInput(const float& dt);
    void updateView();
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = NULL);
};
#endif
