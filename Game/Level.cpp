#include "Level.hpp"

Level::Level(Window* pW)
	: entities(),
	colMan(pW),
	tileMap(NULL)
{
	pGraMan = NULL;

	pGraMan = GraphicManager::getInstance();
	Being::pGraMan = GraphicManager::getInstance();

	Player* player1 = new Player;

	player1->setSize({ 32, 32 });
	player1->setPosition({ 50, 50 });

	pP = player1;

	entities.addEntity(player1);
	colMan.players.push_back(player1);
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

	srand((unsigned)time(NULL));

	while (pGraMan->getWindow()->config.isOpen()) // game loop
	{
		while (pGraMan->getWindow()->config.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				pGraMan->getWindow()->config.close();
		}

		entities.executeEntities();

		colMan.checkColisions();

		print();

	}
}

void Level::createFlyingObstacle(Coordinate<int> position)
{
	Obstacles::FlyingBlock* pFlyingBlock = NULL;
	pFlyingBlock = new Obstacles::FlyingBlock;
	pFlyingBlock->setSize({ 16.0, 16.0 });
	pFlyingBlock->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	pFlyingBlock->rectangle.setFillColor(sf::Color(200, 0, 0));
	colMan.obstacles.push_back((Obstacle*)pFlyingBlock);
	entities.addEntity(pFlyingBlock);
}
void Level::createMudObstacle(Coordinate<int> position)
{
	Obstacles::Mud* pMud = NULL;
	pMud = new Obstacles::Mud;
	pMud->setSize({ 16.0, 16.0 });
	pMud->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	pMud->rectangle.setFillColor(sf::Color::Cyan);
	colMan.obstacles.push_back((Obstacle*)pMud);
	entities.addEntity(pMud);
}
void Level::createFireObstacle(Coordinate<int> position)
{
	Obstacles::FireBlock* pFireBlock = NULL;
	pFireBlock = new Obstacles::FireBlock;
	pFireBlock->setSize({ 16.0, 16.0 });
	pFireBlock->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	pFireBlock->rectangle.setFillColor(sf::Color::Yellow);
	colMan.obstacles.push_back((Obstacle*)pFireBlock);
	entities.addEntity(pFireBlock);
}

void Level::createPlant(Coordinate<int> position)
{
	Enemies::Plant* pPlant = NULL;
	pPlant = new Enemies::Plant;
	if (pPlant == NULL)
	{
		std::cout << "Erro ao criar planta" << std::endl; 
		return;
	}
	pPlant->setSize({ 16.0, 16.0 });
	pPlant->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	pPlant->rectangle.setFillColor(sf::Color::Yellow);
	colMan.enemies.push_back((Enemy*)pPlant);
	entities.addEntity(pPlant);
	pPlant->pPlayer = pP;

	std::cout << "pPlant " << pPlant->acceleration.y << std::endl;

	for (int i = 0; i < 3; i++)
	{
		pPlant->addProjectile(createProjectile());
	}
	pPlant->lastProjectileShooted = pPlant->projectiles.begin();
	std::cout << "Plant created " << std::endl;
}
Projectile* Level::createProjectile()
{
	Projectile* pProj;
	pProj = new Projectile;
	pProj->setSize({ 8, 8 });
	pProj->rectangle.setFillColor(sf::Color::Magenta);
	entities.addEntity(pProj);
	colMan.projectiles.push_back((Projectile*)pProj);
	return pProj;
}
void Level::createMushroom(Coordinate<int> position, float changeDirectionTime)
{
	Enemies::Mushroom* mushroom = NULL;
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

void Level::createPig(Coordinate<int> position, float changeDirectionTime)
{
	Enemies::Pig* pPig = NULL;
	pPig = new Enemies::Pig(changeDirectionTime);
	if (pPig == NULL)
	{
		std::cout << "Error when trying to create Pig" << std::endl;
		return;
	}
	pPig->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	pPig->setSize({ 32.0, 32.0 });
	pPig->speed = { (-200.0f + 20 * (rand() % 3)), 0.0f };
	//aleatoriza modulo e direcao da velocidade
	pPig->rectangle.setFillColor(sf::Color::White);
	entities.addEntity(pPig);
	colMan.enemies.push_back(pPig);
}