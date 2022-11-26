#include "Level.hpp"

Level::Level(Window* pW)
	: entities(),
	colMan(pW),
	tileMap(NULL)
{
	pGraMan = NULL;

	pGraMan = GraphicManager::getInstance();
	Being::pGraMan = GraphicManager::getInstance();

	/*
	ifstream playerFile("../data/Player.txt");
	if (!playerFile)
		std::cout << "Error opening player file" << std::endl;

	Player* pPlayer = NULL;
	float values;
	while (!playerFile.eof())
	{
		playerFile >> values;
		pPlayer = new Player()
	}
	*/
	createPlayer({ 50, 50 }, 1);
	createPlayer({ 100, 100 }, 2);
	
}

Level::~Level()
{
}

void Level::loadFromSave()
{
	loadFireBlock();
}

void Level::loadFireBlock()
{
	std::ifstream fireBlockFile("../data/FireBlock.txt");
	if (fireBlockFile.is_open())
	{
		std::string line;

	}
}

void Level::print()
{
	pGraMan->clear();

	entities.printEntities();

	pGraMan->display();

	pGraMan->updateDeltaTime();
}

void Level::manageColisions()
{
	colMan.checkColisions();
}

void Level::execute()
{
	sf::Event e;

	bool paused = false;

	srand((unsigned)time(NULL));

	while (pGraMan->getWindow()->config.isOpen()) // game loop
	{
		while (pGraMan->getWindow()->config.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				pGraMan->getWindow()->config.close();
			if (e.type == sf::Event::KeyPressed)
			{
				// pausing and returning logic
				if (e.key.code == sf::Keyboard::Escape)
				{
					if (!paused)
						paused = true;
					else
					{
						entities.saveEntities();
						std::cout << "Saving entities " << std::endl;
						return;
					}
						
				}
				if (e.key.code == sf::Keyboard::Enter && paused)
					paused = false;
					
			}
		}
		if (!paused)
		{
			entities.executeEntities();

			colMan.checkColisions();

			print();
		}
		else
		{
			pGraMan->updateDeltaTime();
			// even if it's paused, update delta time
		}
	}
}

void Level::createPlayer(Coordinate<float> position, int id)
{
	player = new Player(id);

	player->setSize({ 32, 32 });
	player->setPosition(position);

	player->setTexture("Main Characters/Ninja Frog/Idle (32x32).png", { 0, 0 }, { 2 * BLOCK_SIZE, 2 * BLOCK_SIZE });

	players.push_back(player);

	entities.addEntity(player);
	colMan.players.push_back(player);
}

void Level::createFlyingObstacle(Coordinate<int> position)
{
	pFlyingBlock = NULL;
	pFlyingBlock = new Obstacles::FlyingBlock;
	pFlyingBlock->setSize({ 16.0, 16.0 });
	pFlyingBlock->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	//pFlyingBlock->rectangle.setFillColor(sf::Color(200, 0, 0));
	pFlyingBlock->setTexture("Terrain/Terrain (16x16).png", { BLOCK_SIZE * 7 , 1 * BLOCK_SIZE}, { BLOCK_SIZE,  BLOCK_SIZE });
	colMan.obstacles.push_back((Obstacle*)pFlyingBlock);
	entities.addEntity(pFlyingBlock);
}

void Level::createMudObstacle(Coordinate<int> position)
{
	pMud = NULL;
	pMud = new Obstacles::Mud;
	pMud->setSize({ 16.0, 16.0 });
	pMud->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	pMud->setTexture("Traps/Sand Mud Ice/Sand Mud Ice (16x6).png", { BLOCK_SIZE * 5 , BLOCK_SIZE * 0}, { BLOCK_SIZE,  BLOCK_SIZE });
	colMan.obstacles.push_back((Obstacle*)pMud);
	entities.addEntity(pMud);
}

void Level::createFireObstacle(Coordinate<int> position)
{
	pFireBlock = NULL;
	pFireBlock = new Obstacles::FireBlock;
	pFireBlock->setSize({ 16.0, 16.0 });
	pFireBlock->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	pFireBlock->rectangle.setFillColor(sf::Color::Yellow);
	pFireBlock->setTexture("Traps/Fire/On (16x32).png", { 0, 0 }, { BLOCK_SIZE,  BLOCK_SIZE });
	colMan.obstacles.push_back((Obstacle*)pFireBlock);
	entities.addEntity(pFireBlock);
}

void Level::createMushroom(Coordinate<int> position, float changeDirectionTime)
{
	std::cout << "Creating Mushroom " << std::endl;
	std::cout << "Position " << position << std::endl;
	mushroom = NULL;
	mushroom = new Enemies::Mushroom(changeDirectionTime);
	if (mushroom == NULL)
	{
		std::cout << "Error when trying to create mushroom" << std::endl; 
		return;
	}
	colMan.enemies.push_back((Enemy*)mushroom);
	mushroom->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	mushroom->setSize({ 32.0, 32.0 });
	float speedx = (-200.0f + 40 * (rand() % 3));
	mushroom->speed = { speedx, 0.0f };
	//aleatoriza modulo e direcao da velocidade
	mushroom->setTexture("Enemies/Mushroom/Idle (32x32).png", { 0, 0 }, { BLOCK_SIZE*2,  BLOCK_SIZE*2 });
	entities.addEntity(mushroom);
	std::cout << "Mushroom " << mushroom->acceleration.y << std::endl;
}