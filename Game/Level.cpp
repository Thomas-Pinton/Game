#include "Level.hpp"


Level::Level(Janela* window)
	: entities(),
	gerCol(),
	gerGraf()
{
	gerGraf.setJanela(window);
	Jogador* player1 = new Jogador;

	player1->setTamanho({ 100, 100 });
	player1->setPosicao({ 50, 50 });

	entities.addEntity(player1);
	gerCol.players.push_back(player1);
}

Level::~Level()
{
}

void Level::create(Janela* window) // criando coisas que vão estar em toda a fase
{
	Tile* t = NULL;

	std::list<Tile*>::iterator i;

	for (int i = 0; i * 100 + 50 < window->getWIDTH() + 300; i++) // will need to work with memory managent later
	{
		t = new Tile;
		t->rectangle.setFillColor(sf::Color(255 / ((i % 2) + 1), 100, 150));
		t->setTamanho({ 100, 100 });
		t->setPosicao({ (float)(i * 100) + 50, (float)window->getHEIGHT() / 2 + 200 });
		gerCol.staticEntities.push_back((Entidade*)t);
		entities.addEntity(t);
	}
}

void Level::executar(Janela* window)
{
	
	sf::Event e;
	sf::Clock clock;
	float deltaTime;
	float tempoCriarInimigo = 0;

	srand((unsigned)time(NULL));

	Inimigo* inimigo;

	create(window);

	while (window->config.isOpen()) // game loop
	{
		while (window->config.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window->config.close();
		}


		// colocar essa parte no gerenciador de movimento
		deltaTime = (float)clock.restart().asSeconds();

		tempoCriarInimigo += deltaTime;

		if (deltaTime > 0.15f)
			deltaTime = 0.15f;


		if (tempoCriarInimigo > 3)
		{
			//ger.movingEntities.remove(inimigo);
			std::cout << "Criando inimigo" << std::endl;
			tempoCriarInimigo -= 3;
			inimigo = new Inimigo;
			gerCol.movingEntities.push_back(inimigo);
			inimigo->setPosicao({ (float)(window->getWIDTH() + 250 + (rand() % 3)), (float)window->getHEIGHT() / 2 + 100 });
			inimigo->setTamanho({ 100.0f, 100.0f });
			inimigo->velocidade = { -250.0f + 50 * (rand() % 3), 0.0f };
			entities.addEntity(inimigo);
		}

		//executando cada entidade
		entities.executeEntities(deltaTime);

		gerenciarColisoes(window);

		gerGraf.clear();

		entities.printEntities(&gerGraf);

		gerGraf.display();

	}
	
}
void Level::gerenciarColisoes(Janela* window)
{
	gerCol.checaColisoes(window);
}
