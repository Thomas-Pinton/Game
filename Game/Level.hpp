#pragma once

#include <iostream>
#include "List.hpp"
#include "EntitiesList.hpp"
#include "GraphicManager.hpp"
#include "ColisionManager.hpp"
#include "Player.hpp"
#include "Plant.hpp"
#include "Mushroom.hpp"
#include "FlyingBlock.hpp"
#include "FireBlock.hpp"
#include "Mud.hpp"
#include "Pig.hpp"
#include <list>
#include <fstream>
#include "Constants.hpp"
// Os inimigos e osbtasculos estao sendo incluidos no nivel pois eles serao usados na maioria das fases

using namespace Manager;


class Level : public Being
{
protected:
	EntitiesList entities;
	ColisionManager colMan;
	Manager::GraphicManager* pGraMan;
	int* tileMap;
	std::list<Player*> players;

	sf::Event e;
	bool paused;

	int enemyAmount;
	int playerAmount;

	Player* player;
	Obstacles::FlyingBlock* pFlyingBlock;
	Obstacles::Mud* pMud;
	Obstacles::FireBlock* pFireBlock;
	Enemies::Mushroom* mushroom;
public:
	Level(int playersAmount, bool loadFromSave);
	~Level();

	void execute();
	void print();
	void manageColisions();

	void decreasePlayerAmount();
	void decreaseEnemyAmount();

	void createEntity(Entity* pE, Coordinate<int> size, Coordinate<float> position, std::string texturePath);
	void createPlayer(Coordinate<float> position, int id);
	void createFlyingObstacle(Coordinate<int> position);
	void createFireObstacle(Coordinate<int> position);
	void createFlyingObstacleDifferentTexture(Coordinate<int> position);
	void createMushroom(Coordinate<int> position, float changeDirectionTime = 2.5f + rand() % 2);
	// Posso criar uma funcao create entity, que preenche os valores que voce quiser de velocidade, posicao, tamanho etc

	void recoverMushrooms(std::string level);
	void recoverPlayers(std::string level);
	void recoverFireBlocks(std::string level);

	void loadLevel(std::string level);
	void save(std::string level);
};

