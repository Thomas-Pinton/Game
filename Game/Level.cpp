#include "Level.hpp"

Level::Level(int playersAmount, bool loadFromSave)
	: entities(),
	colMan(),
	tileMap(NULL),
	paused(false)
{
	pGraMan = NULL;

	pGraMan = GraphicManager::getInstance();
	Being::pGraMan = GraphicManager::getInstance();

	enemyAmount = 0;
	playerAmount = playersAmount;

	if (!loadFromSave)
	{
		for (int i = 0; i < playersAmount; i++)
		{
			player = StateManager::getInstance()->getPlayer(i);
			if (player)
			{
				std::cout << "Player already exists " << std::endl;
				player->setLevel(this);
				player->setPosition({ (float)50 * (i + 1),(float)50 * (i + 1) });
				player->setAlive(true);
				players.push_back(player);
				entities.addEntity(player);
				colMan.players.push_back(player);
			}
			else
			{
				std::cout << "Creating player " << std::endl;
				createPlayer({ (float)50 * (i + 1),(float)50 * (i + 1) }, i + 1);
			}
		}
	}
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
	srand((unsigned int)time(NULL));

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
					if (id == level1)
						save("Level1");
					else
						save("Level2");
					std::cout << "Saving entities " << std::endl;
					std::cout << "Leaving level " << std::endl;
					//always go back to main menu
					Manager::StateManager::getInstance()->popUntil(1);
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

void createEntity(Entity* pE, Coordinate<int> size, Coordinate<float> position, std::string texturePath)
{
}

void Level::decreasePlayerAmount()
{
	playerAmount -= 1;
	std::cout << "Player amount " << playerAmount << std::endl;
	if (playerAmount == 0)
		StateManager::getInstance()->push((States)endLevelScreen);
}
void Level::decreaseEnemyAmount()
{
	enemyAmount -= 1;
	std::cout << "Enemy amount " << enemyAmount << std::endl;
	if (enemyAmount == 0 && id == l1)
		StateManager::getInstance()->push((States)level2);
}

void Level::createPlayer(Coordinate<float> position, int id)
{
	player = new Player(id);

	player->setSize({ 32, 32 });
	player->setPosition(position);

	player->setTexture("Main Characters/Ninja Frog/Idle (32x32).png", { 0, 0 }, { 2 * BLOCK_SIZE, 2 * BLOCK_SIZE });
	player->setLevel(this);
	players.push_back(player);

	entities.addEntity(player);
	colMan.players.push_back(player);
	Manager::StateManager::getInstance()->addPlayer(player);
}

void Level::createFlyingObstacle(Coordinate<int> position)
{
	pFlyingBlock = NULL;
	pFlyingBlock = new Obstacle;
	pFlyingBlock->setSize({ 16.0f, 16.0f });
	pFlyingBlock->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	//pFlyingBlock->rectangle.setFillColor(sf::Color(200, 0, 0));
	pFlyingBlock->setTexture("Terrain/Terrain (16x16).png", { BLOCK_SIZE * 7 , 1 * BLOCK_SIZE }, { BLOCK_SIZE,  BLOCK_SIZE });
	colMan.obstacles.push_back((Obstacle*)pFlyingBlock);
	entities.addEntity(pFlyingBlock);
}

void Level::createFlyingObstacleDifferentTexture(Coordinate<int> position)
{
	pFlyingBlock = NULL;
	pFlyingBlock = new Obstacle;
	pFlyingBlock->setSize({ 16.0f, 16.0f });
	pFlyingBlock->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	//pFlyingBlock->rectangle.setFillColor(sf::Color(200, 0, 0));
	pFlyingBlock->setTexture("Terrain/Terrain (16x16).png", { BLOCK_SIZE * 7 , 5 * BLOCK_SIZE }, { BLOCK_SIZE,  BLOCK_SIZE });
	colMan.obstacles.push_back((Obstacle*)pFlyingBlock);
	entities.addEntity(pFlyingBlock);
}

void Level::createFireObstacle(Coordinate<int> position)
{
	pFireBlock = NULL;
	pFireBlock = new Obstacles::FireBlock;
	pFireBlock->setSize({ 16.0f, 16.0f });
	pFireBlock->setPosition({ (float)(position.x * 16) + 8, (float)(position.y * 16) + 8 });
	pFireBlock->setTexture("Traps/Fire/On (16x32).png", { 0, 0 }, { BLOCK_SIZE,  BLOCK_SIZE });
	pFireBlock->setLevel(this);
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
	mushroom->setSize({ 32.0f, 32.0f });
	float speedx = (-200.0f + 40 * (rand() % 3));
	mushroom->speed = { speedx, 0.0f };
	//aleatoriza modulo e direcao da velocidade
	mushroom->setTexture("Enemies/Mushroom/Idle (32x32).png", { 0, 0 }, { BLOCK_SIZE * 2,  BLOCK_SIZE * 2 });
	entities.addEntity(mushroom);
	mushroom->setLevel(this);
	std::cout << "Mushroom " << mushroom->acceleration.y << std::endl;
}

void Level::recoverMushrooms(std::string level)
{
	std::fstream mushroomFile("../data/" + level + "/Mushroom.txt", std::ios::in);
	if (mushroomFile.is_open())
	{
		std::string line;
		while (std::getline(mushroomFile, line))
		{
			std::cout << "Line " << line << std::endl;
			mushroom = new Enemies::Mushroom(line);
			mushroom->setTexture("Enemies/Mushroom/Idle (32x32).png", { 0, 0 }, { BLOCK_SIZE * 2,  BLOCK_SIZE * 2 });
			entities.addEntity(mushroom);
			mushroom->setLevel(this);
			colMan.enemies.push_back((Enemy*)mushroom);
			if (mushroom->getAlive())
				enemyAmount++;
		}
	}
	mushroomFile.close();
}

void Level::recoverPlayers(std::string level)
{
	std::cout << "Level " << level << std::endl << std::endl;
	std::fstream playerFile("../data/" + level + "/Player.txt", std::ios::in);
	if (playerFile.is_open())
	{
		std::string line;
		while (std::getline(playerFile, line))
		{
			player = new Player(line);

			player->setTexture("Main Characters/Ninja Frog/Idle (32x32).png", { 0, 0 }, { 2 * BLOCK_SIZE, 2 * BLOCK_SIZE });

			players.push_back(player);
			player->setLevel(this);

			std::cout << "Loading player " << std::endl;
			std::cout << "alive " << player->getAlive() << std::endl;

			entities.addEntity(player);
			colMan.players.push_back(player);
			Manager::StateManager::getInstance()->addPlayer(player);
			if (player->getAlive())
				playerAmount++;
		}
	}
	playerFile.close();
}

void Level::recoverFireBlocks(std::string level)
{
	std::fstream fireBlockFile;
	if (level == "Level2")
		fireBlockFile.open("../data/Level2/FireBlock.txt", std::ios::in);
	else
		fireBlockFile.open("../data/Level1/FireBlock.txt", std::ios::in);
	//std::fstream fireBlockFile("../data/" + level + "/FireBlock.txt", std::ios::in);
	if (fireBlockFile.is_open())
	{
		std::string line;
		while (std::getline(fireBlockFile, line))
		{
			std::cout << "Line " << line << std::endl;
			pFireBlock = new Obstacles::FireBlock(line);
			pFireBlock->setTexture("Traps/Fire/On (16x32).png", { 0, 0 }, { BLOCK_SIZE,  BLOCK_SIZE });
			pFireBlock->setLevel(this);
			entities.addEntity(pFireBlock);
			colMan.obstacles.push_back((Obstacle*)pFireBlock);
		}
	}
	fireBlockFile.close();
}

void Level::loadLevel(std::string level)
{
	std::fstream levelFile("../data/" + level + "/" + level + ".txt", std::ofstream::in);
	if (levelFile.is_open())
	{
		std::string line;
		while (std::getline(levelFile, line))
		{
			std::istringstream ss(line);
			ss >> enemyAmount;
			ss >> playerAmount;
		}
	}
}

void Level::save(std::string level)
{
	if (level == "Level1")
		remove("../data/Level1/Level1");
	else
		remove("../data/Level2/Level2");

	std::ofstream levelFile("../data/" + level + "/" + level + ".txt", std::ofstream::trunc);
	if (levelFile.is_open())
	{
		levelFile << enemyAmount << " "
			<< playerAmount << " "
			<< std::endl;
		levelFile.close();
	}
}