#ifndef Game_H
#define Game_H

#include"State.h"

class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	//Initialization
	void initWindow();

public:
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Function
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();

};

#endif