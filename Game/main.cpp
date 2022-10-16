#include <iostream>
#include <list>

#include "Principal.hpp"

/*

// Problemas //

 - Função checa colisoes (parte entre entidades moveis)

// To Do's //

 - Wall colision

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

	/*
	player1.setTexture("../Assets/Main Characters/Pink Man/Idle (32x32).png");

	player1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	// scale
	player1.sprite.setScale(sf::Vector2f(4.f, 4.f)); // absolute scale factor

	player1.sprite.setOrigin(sf::Vector2f(16.f, 16.f)); // setting the origin to center

	Coordenada<float> coord(32.0, 32.0);
	player1.setTamanho(coord);

	*/
	
	player1.setTamanho({100, 100});
	player1.setPosicao({ 0.0f, 0.0f });
	//player1.aceleracao.y = -10;

	GerenciadorColisoes gerCol;

	Tile* t = NULL;

	std::list<Tile*> tiles; // temporário

	for (int i = 0; i * 100 + 50 < WIDTH; i++) // will need to work with memory managent later
	{
		t = new Tile;
		t->rectangle.setFillColor(sf::Color(255 / ((i % 2) + 1), 100, 150));
		t->setTamanho({100, 100});
		t->setPosicao({ (float)(i * 100) + 50, (float) HEIGHT / 2 + 200 });
		gerCol.addStaticEntity((Entidade*)t);
		tiles.push_back(t);
	}
	
	

	/*

	Tile tile1;
	Tile tile2;
	Tile tile3;
	Tile tile4;

	Tile tiles[4] = { tile1, tile2, tile3, tile4 };

	for (int i = 0; i < 4; i++) {
		float largura = 44, altura = 58.6;
		tiles[i].setTexture("../Assets/Terrain/Terrain (16x16).png");
		tiles[i].sprite.setScale(sf::Vector2f(4.f, 4.f));
		tiles[i].sprite.setTextureRect(sf::IntRect(largura * 2, 0, largura, altura));
		tiles[i].sprite.setOrigin(sf::Vector2f(largura / 2, altura / 2));
		tiles[i].sprite.setPosition(sf::Vector2f(WIDTH / 2 + (i * largura), HEIGHT / 2));
		
		gerCol.addStaticEntity((Entidade*)&tiles[i]);
	}

	*/

	gerCol.addPlayer(&player1);


	// old animation system
	int position = 0;
	const int ammount_images = 11;
	int switch_time = 100;
	int total_time = 0;


	sf::Clock clock;
	float deltaTime;

	std::list<Tile*>::iterator i;

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

		gerCol.checaColisoes(WIDTH, HEIGHT);
		
		std::cout << "acel.y " << player1.aceleracao.y << std::endl;

		// Clear screen
		window.clear();
		// Draw the sprite
		//window.draw(player1.sprite);
		window.draw(player1.rectangle);
		for (i = tiles.begin(); i != tiles.end(); i++) {
			window.draw((*i)->rectangle);
		}
		// Update the window
		window.display();

		

	}

	return 0;
}