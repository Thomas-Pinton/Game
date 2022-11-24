#include "Level.hpp"

Level::Level(Window* pW)
	: entities(),
	colMan(pW),
	tileMap(NULL)
{
	pGraMan = NULL;

	pGraMan = GraphicManager::getInstance();
	Being::pGraMan = GraphicManager::getInstance();

	createPlayer({ 50, 50 }, 1);
	createPlayer({ 100, 100 }, 2);
	
}

Level::~Level()
{
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

	}
}

void Level::loadSave(std::string filePath)
{

}

void Level::createPlayer(Coordinate<float> position, int id)
{
	player = new Player(id);

	player->setSize({ 32, 32 });
	player->setPosition(position);

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
	pFlyingBlock->rectangle.setFillColor(sf::Color(200, 0, 0));
	colMan.obstacles.push_back((Obstacle*)pFlyingBlock);
	entities.addEntity(pFlyingBlock);
}
void Level::createMudObstacle(Coordinate<int> position)
{
	pMud = NULL;
	pMud = new Obstacles::Mud;
	pMud->setSize({ 16.0, 16.0 });
	pMud->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	pMud->rectangle.setFillColor(sf::Color::Cyan);
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
	colMan.obstacles.push_back((Obstacle*)pFireBlock);
	entities.addEntity(pFireBlock);
}


void Level::createMushroom(Coordinate<int> position, float changeDirectionTime)
{
	mushroom = NULL;
	mushroom = new Enemies::Mushroom(changeDirectionTime);
	if (mushroom == NULL)
	{
		std::cout << "Error when trying to create mushroom" << std::endl; 
		return;
	}
	colMan.enemies.push_back((Enemy*)mushroom);
	mushroom->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	mushroom->setSize({ 16.0, 16.0 });
	mushroom->speed = { (-200.0f + 40 * (rand() % 3)), 0.0f };
	//aleatoriza modulo e direcao da velocidade
	mushroom->rectangle.setFillColor(sf::Color(0, 200, 0));
	entities.addEntity(mushroom);
	std::cout << "Mushroom " << mushroom->acceleration.y << std::endl;
}
