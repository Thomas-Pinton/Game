#include <iostream>

#include "Principal.hpp"

/*

// Problemas //


// To Do's //

 - Set textures and sprites to player1 object

*/

int main() 
{
	const int HEIGHT = 800, WIDTH = 1500;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Test");
	sf::Event e;

	/*
	Texture - Image
	Sprite - Image with a form (rectangle, usually)
	*/

	// Load a sprite to display

	// sprite and texture in player class
	Jogador player1; 
	player1.setTexture("../Assets/Main Characters/Pink Man/Idle (32x32).png");

	player1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	player1.sprite.setOrigin(sf::Vector2f(16.f, 16.f)); // setting the origin to center

	// scale
	player1.sprite.setScale(sf::Vector2f(4.f, 4.f)); // absolute scale factor

	int position = 0;
	const int ammount_images = 11;
	int switch_time = 100;
	int total_time = 0;


	sf::Clock clock;
	float deltaTime;

	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		deltaTime = (float) clock.restart().asSeconds();

		if (deltaTime > 0.15f)
			deltaTime = 0.15f;
		
		/*
		total_time++;

		if (total_time == switch_time)
		{
			if (position == ammount_images - 1)
				position = 0;

			player1.sprite.setTextureRect(sf::IntRect(32 * position, 0, 32, 32)); // Player animation
			position++;

			total_time = 0;

		}
		*/
		player1.checkKeys();
		player1.atualizaPosicao(deltaTime);

		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(player1.sprite);
		// Update the window
		window.display();

		

	}

	return 0;
}