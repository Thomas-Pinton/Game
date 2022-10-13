#include <iostream>

#include "SFML/Graphics.hpp"
#include "Coordenada.hpp"

/*

// Problemas //

	- Construtor Coordenada não funcionando (vazio e "preenchido")
	- Erro classe coordenada

*/

int main() 
{
	const int HEIGHT = 800, WIDTH = 1500;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Test");
	sf::Event e;

	///*
	Coordenada<int> pos1;
	pos1.x = 2, pos1.y = 3;
	std::cout << pos1.x << pos1.y << std::endl;

	Coordenada<int> pos2;
	pos2.x = 3, pos2.y = 4;
	Coordenada<int> pos3;
	//*/
	std::cout << pos1.x << pos1.y << std::endl;

	pos3 = pos1 + pos2;

	std::cout << pos3.x << pos3.y << std::endl;

	/*
	Texture - Image
	Sprite - Image with a form (rectangle, usually)
	*/

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("../Assets/Main Characters/Ninja Frog/Idle (32x32).png"))
		return EXIT_FAILURE;

	sf::Sprite sprite(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	sprite.setOrigin(sf::Vector2f(16.f, 16.f)); // setting the origin to center

	// position
	sprite.setPosition(sf::Vector2f(750.0f, 400.0f)); // absolute position

	// scale
	sprite.setScale(sf::Vector2f(4.f, 4.f)); // absolute scale factor

	int position = 0;
	const int ammount_images = 11;
	int switch_time = 100;
	int total_time = 0;

	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
		///*

		total_time++;

		if (total_time == switch_time)
		{
			if (position == ammount_images - 1)
				position = 0;

			sprite.setTextureRect(sf::IntRect(32 * position, 0, 32, 32)); // Player animation
			position++;

			total_time = 0;

		}


		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(sprite);
		// Update the window
		window.display();

		//*/

	}

	return 0;
}