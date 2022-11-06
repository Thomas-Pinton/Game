#include "Level.hpp"


Level::Level(Window* window)
	: entities(),
	colMan(),
	grafMan()
{
	grafMan.setWindow(window);
	Player* player1 = new Player;

	player1->setSize({ 100, 100 });
	player1->setPosition({ 50, 50 });

	entities.addEntity(player1);
	colMan.players.push_back(player1);
}

Level::~Level()
{
}

void Level::create(Window* window) // criando coisas que v�o estar em toda a fase
{
	Tile* tile = NULL;

	std::list<Tile*>::iterator i;

	for (int i = 0; i * 100 + 50 < window->getWIDTH() + 300; i++) // will need to work with memory managent later
	{
		tile = new Tile;
		tile->rectangle.setFillColor(sf::Color(255 / ((i % 2) + 1), 100, 150));
		tile->setSize({ 100, 100 });
		tile->setPosition({ (float)(i * 100) + 50, (float)window->getHEIGHT() / 2 + 200 });
		colMan.staticEntities.push_back((Entity*)tile);
		entities.addEntity(tile);
	}
}

void Level::execute(Window* window)
{
	
	sf::Event e;
	sf::Clock clock;
	float deltaTime;
	float tempoCriarInimigo = 0;

	srand((unsigned)time(NULL));

	Enemy* inimigo;

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
			inimigo = new Enemy;
			colMan.movingEntities.push_back(inimigo);
			inimigo->setPosition({ (float)(window->getWIDTH() + 250 + (rand() % 3)), (float)window->getHEIGHT() / 2 + 100 });
			inimigo->setSize({ 100.0f, 100.0f });
			inimigo->speed = { -250.0f + 50 * (rand() % 3), 0.0f };
			entities.addEntity(inimigo);
		}

		//executando cada entidade
		entities.executeEntities(deltaTime);

		manageColisions(window);

		grafMan.clear();

		entities.printEntities(&grafMan);

		grafMan.display();

	}
	
}
void Level::manageColisions(Window* window)
{
	colMan.checkColisions(window);
}
