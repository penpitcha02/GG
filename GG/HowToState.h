#ifndef HOWTOSTATE_H
#define HOWTOSTATE_H

#include"State.h"
#include"MainMenuState.h"

class HowToState :
    public State
{
private:
    //View
    sf::View view;

    //Background
    sf::Texture backgroundTexture;
    sf::RectangleShape background;

    //Escape
    sf::Text escape;
    sf::Font font;

    //Function
    void initVariable();
    void initBackground();
    void initView();
    void initKeybinds();

public:
    HowToState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~HowToState();

    //Functions
    void updateInput(const float& dt);
    void updateView();
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};
#endif

