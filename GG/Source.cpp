#include <SFML/Graphics.hpp>
#include"Grandpa.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	
	//Animation Time
	float deltaTime = 0.0f;
	sf::Clock clock;

	//Grandpa
	sf::Texture grandpaTexture;
	if (!grandpaTexture.loadFromFile("img/2.png"))
		printf("Load Mai Dai");

	Grandpa grandpa(&grandpaTexture, sf::Vector2u(6, 3), 0.3f, 500.0f);

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Update
		grandpa.Update(deltaTime);

		//Render
		window.clear();
	
		grandpa.Draw(window);

		window.display();
	}
	return 0;
}