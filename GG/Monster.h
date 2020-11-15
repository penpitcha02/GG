#ifndef  MONSTER_H
#define MONSTER_H

#include<SFML/Graphics.hpp>

class Monster
{
private:
	sf::CircleShape monster;
	sf::Texture monsterTexture;

	//Variables
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	//Initializer functions
	void initVariables();
	void initMonster();

public:
	Monster(float pos_x, float pos_y);
	virtual ~Monster();

	//Accessor
	const sf::FloatRect getBounds() const;
	sf::Vector2f GetPosition() { return monster.getPosition(); }
	const int& getPoints() const;
	const int& getDamage() const;

	//Function
	void monsterBackLeft();
	void monsterBackRight();
	void monsterBackUp();
	void monsterBackDown();
	void render(sf::RenderTarget* target);

};
#endif // ! COCONUT_H
