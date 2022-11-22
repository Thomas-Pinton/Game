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
public:
	Level(Window* pW);
	~Level();

	void execute();
	void print();
	void manageColisions();

	void createPlayer(Coordinate<float> position, int id);
	void createFlyingObstacle(Coordinate<int> position);
	void createMudObstacle(Coordinate<int> position);
	void createFireObstacle(Coordinate<int> position);
	void createPlant(Coordinate<int> position);
	Projectile* createProjectile();
	void createMushroom(Coordinate<int> position, float changeDirectionTime = 2.5f + rand() % 2);
	void createPig(Coordinate<int> position, float changeDirectionTime = 1.5f + (rand() % 2) / 2);
	// Posso criar uma funcao create entity, que preenche os valores que voce quiser de velocidade, posicao, tamanho etc
};

