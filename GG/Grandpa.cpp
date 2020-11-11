//#include "Grandpa.h"
//
//Grandpa::Grandpa(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
//	animation(texture, imageCount, switchTime)
//{
//	this->speed = speed;
//	row = 0;
//	faceRight = true;
//	attack = false;
//
//	grandpa.setSize(sf::Vector2f(475.f, 475.f));
//	grandpa.setPosition(0.0f, 0.0f);
//	grandpa.setTexture(texture);
//}
//
//Grandpa::~Grandpa()
//{
//}
//
//void Grandpa::Update(float deltaTime)
//{
//	sf::Vector2f movement(0.0f, 0.0f);
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//		movement.x -= speed * deltaTime;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//		movement.x += speed * deltaTime;
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
//	{
//		attack = true;
//	}
//	else {
//		attack = false;
//		if (movement.x == 0.0f)
//		{
//			row = 0;
//		}
//		else
//		{
//			row = 1;
//
//			if (movement.x > 0.0f)
//			{
//				faceRight = true;
//				grandpa.setOrigin(0.f, 0.f);
//			}
//			else
//			{
//				faceRight = false;
//				grandpa.setOrigin(20.f, 0.f);
//			}
//		}
//	}
//
//	animation.Update(row, deltaTime, faceRight, attack);
//	grandpa.setTextureRect(animation.uvRect);
//	grandpa.move(movement);
//
//	//Collision screen
//	//Left collossion
//	if (grandpa.getPosition().x < 0.f)
//		grandpa.setPosition(0.f, grandpa.getPosition().y);
//	//Right collosion
//	if (grandpa.getPosition().x + grandpa.getGlobalBounds().width > 4100.0f)
//		grandpa.setPosition(4100.0f - grandpa.getGlobalBounds().width, grandpa.getPosition().y);
//
//}
//
//
//void Grandpa::Draw(sf::RenderWindow& window)
//{
//	window.draw(grandpa);
//}