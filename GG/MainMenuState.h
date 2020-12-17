#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "HowToState.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
    //View
    sf::View view;

    //Music
    sf::Music music;
    
    //Background
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    //Variables
    sf::Texture button1idleTexture;
    sf::Texture button1hoverTexture;
    sf::Texture button1activeTexture;

    sf::Texture button2idleTexture;
    sf::Texture button2hoverTexture;
    sf::Texture button2activeTexture;

    sf::Texture button3idleTexture;
    sf::Texture button3hoverTexture;
    sf::Texture button3activeTexture;

    std::map<std::string, Button*> buttons;

    //Function
    void initVariable();
    void initMusic();
    void initBackground();
    void initView();
    void initFonts();
    void initKeybinds();
    void initButton();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();

    //Functions
    void updateInput(const float& dt);
    void updateView();
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = NULL);
};
#endif
