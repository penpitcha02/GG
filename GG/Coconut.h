#ifndef  COCONUT_H
#define COCONUT_H

#include<SFML/Graphics.hpp>

class Coconut
{
private:
	sf::CircleShape coconut;
	sf::Texture coconutTexture;

	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;
	
	void initVariables();
	void initCoconut();

public:
	Coconut(float pos_x, float pos_y);
	virtual ~Coconut();

	//Accessor
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Function
	void update();
	void render(sf::RenderTarget* target);

};
#endif // ! COCONUT_H
