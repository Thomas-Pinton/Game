#include "Jogo.hpp"

std::list<Ente*> Gerenciador::staticEntities;
std::list<Entidade*> Gerenciador::movingEntities;
std::list<Jogador*> Gerenciador::players;

int Ente::id_count = 0;

Jogo::Jogo() :
// criar elementos do jogo
window(800, 1500),
ger(&window),
gerCol(),
gerMov()
{
	gerGraf.setJanela(&window);
	// criar tambem os outros gerenciadores, que ainda não foram implementados
}

void Jogo::executar()
{
	sf::Event e;
	sf::Clock clock;
	float deltaTime;
	float tempoCriarInimigo = 0;

	srand((unsigned)time(NULL));

	Inimigo* inimigo;
	std::list<Entidade*>::iterator i;

	while (window.config.isOpen()) // game loop
	{
		while (window.config.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.config.close();
		}

		
		// colocar essa parte no gerenciador de movimento
		deltaTime = (float)clock.restart().asSeconds();

		tempoCriarInimigo += deltaTime;

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

		if (tempoCriarInimigo > 3)
		{
			//ger.movingEntities.remove(inimigo);
			std::cout << "Criando inimigo" << std::endl;
			tempoCriarInimigo -= 3;
			inimigo = new Inimigo;
			inimigo->setPosicao({ (float)(window.getWIDTH() + 250 + (rand() % 3)), (float)window.getHEIGHT() / 2 + 100 });
			inimigo->setTamanho({ 100.0f, 100.0f });
			inimigo->velocidade = { -250.0f + 50 * (rand() % 3), 0.0f};
			ger.addMovingEntity(inimigo);
		}
	



		// Deve estar no gerenciador de movimento
		gerMov.atualizaPosicoes(deltaTime);
		
		gerCol.checaColisoes(&window);

		gerGraf.imprime();

		//Tudo isso aqui vai ter que ser feito no gerenciador gráfico
	

	}
}