#ifndef NAMESTATE_H
#define NAMESTATE_H

#include"State.h"
#include"GameState.h"

class NameState :
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

    //Font
    sf::Font font;

    //Function
    void initVariable();
    void initMusic();
    void initBackground();
    void initView();
    void initTextBox();
    void initKeybinds();

public:
    NameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~NameState();

    //Functions
    void updateInput(const float& dt);
    void updateView();
    void updateTextBox();
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};
#endif

