#ifndef HITBOXCOMPONENT_H
#define HITBOXCOMPONENT_H

#include<iostream>
#include<ctime>
#include<cstdlib>

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

class HitboxComponent
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	float offsetX;
	float offsetY;

	
public:
	HitboxComponent(sf::Sprite& sprite, 
		float offset_x, float offset_y, 
		float width, float height);
	virtual ~HitboxComponent();

	//Accessors
	void setScale(int x, int y);

	//Functions
	const sf::FloatRect getBounds() const;
	
	void update();
	void render(sf::RenderTarget& target);
};

#endif

