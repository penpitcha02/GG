#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"

class Grandpa
{
public:
	Grandpa(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Grandpa();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return grandpa.getPosition(); }


private:
	sf::RectangleShape grandpa;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};