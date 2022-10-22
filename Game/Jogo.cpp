#include "Jogo.hpp"

std::list<Ente*> Gerenciador::staticEntities;
std::list<Entidade*> Gerenciador::movingEntities;
std::list<Jogador*> Gerenciador::players;

Jogo::Jogo() :
// criar elementos do jogo
window(800, 1500),
ger(&window),
gerCol()
{
	gerGraf.setJanela(&window);
	// criar tambem os outros gerenciadores, que ainda não foram implementados
}

void Jogo::executar()
{
	sf::Event e;
	sf::Clock clock;
	float deltaTime;

	// por enquanto está na main, mas vai ser colocado no gerenciador de colisões

	while (window.config.isOpen()) // game loop
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

		// Deve estar no gerenciador de movimento
		ger.players.front()->checkKeys();
		ger.players.front()->atualizaPosicao(deltaTime);

		gerCol.checaColisoes(&window);

		std::cout << "acel.y " << ger.players.front()->aceleracao.y << std::endl;

		gerGraf.imprime();

		//Tudo isso aqui vai ter que ser feito no gerenciador gráfico
	

	}
}