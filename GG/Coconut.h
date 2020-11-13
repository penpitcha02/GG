#ifndef  COCONUT_H
#define COCONUT_H

#include<SFML/Graphics.hpp>

class Coconut
{
private:
	sf::CircleShape coconut;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initCoconut();
	void initVariables();

public:
	Coconut(float pos_x, float pos_y);
	virtual ~Coconut();

	//Accessor
	const sf::FloatRect getBounds() const;

	//Function
	void update();
	void render(sf::RenderTarget* target);

};
#endif // ! COCONUT_H
