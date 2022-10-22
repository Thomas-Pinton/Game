#include "Jogo.hpp"

std::list<Entidade*> Gerenciador::staticEntities;
std::list<Entidade*> Gerenciador::movingEntities;
std::list<Jogador*> Gerenciador::players;

Jogo::Jogo() :
// criar elementos do jogo
window(800, 1500),
ger(),
player1()
{
	ger.addPlayer(&player1);
	gerGraf.setJanela(&window);
	
	// criar tambem os outros gerenciadores, que ainda não foram implementados
}

void Jogo::executar()
{
	sf::Event e;
	sf::Clock clock;
	float deltaTime;

	// por enquanto está na main, mas vai ser colocado no gerenciador de colisões
	Tile* t = NULL;

	std::list <Tile*>::iterator i;

	std::list<Tile*> tiles; // temporário

	for (int i = 0; i * 100 + 50 < window.getWIDTH(); i++) // will need to work with memory managent later
	{
		t = new Tile;
		t->rectangle.setFillColor(sf::Color(255 / ((i % 2) + 1), 100, 150));
		t->setTamanho({ 100, 100 });
		t->setPosicao({ (float)(i * 100) + 50, (float)window.getHEIGHT() / 2 + 200 });
		ger.addStaticEntity((Entidade*)t);
		tiles.push_back(t);
	}

	player1.setTamanho({ 100, 100 });
	player1.setPosicao({50.0f, 50.0f});

	while (window.config.isOpen())
	{
		while (window.config.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.config.close();
		}

		
		// colocar essa parte no gerenciador gráfico
		deltaTime = (float)clock.restart().asSeconds();

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

		gerCol.checaColisoes(&window);

		std::cout << "acel.y " << player1.aceleracao.y << std::endl;

		gerGraf.imprime();

		//Tudo isso aqui vai ter que ser feito no gerenciador gráfico
	

	}
}