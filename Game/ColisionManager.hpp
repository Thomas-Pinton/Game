#pragma once

#include <iostream>
#include <list>
#include "Coordinate.hpp"
#include "Window.hpp"
#include "GraphicManager.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"


/*

Implementando o tipo de colis�o padr�o (comparar todos os elemento 1 a 1)

� poss�vel, no futuro, para otimizar o jogo, 
realizar um sistema de colis�es que divide o espa�o e compara elementos dentro daque espa�o

*/

namespace Manager
{
	class ColisionManager
	{
	public:
		std::list<Obstacle*> obstacles;
		std::list<Player*> players;
		std::list<Enemy*> enemies;
		std::list<Projectile*> projectiles;
	public:
		ColisionManager();

		// posso ter uma fun��o gen�rica addEntity que tem sobrecarga de par�metros (a depender do tipo de entidade)

		void checkColisions();
		void checkColisionsPlayerEnemy();
		void checkColisionsPlayerObstacles();
		void checkColisionsPlayerProjectiles();
		void checkColisionsEnemyObstacles();
		void checkColisionsProjectilesObstacles();
		void checkColisionsPlayerWall();
		void checkColisionsEnemyWall();

		Coordinate<float> checkColision(Entity* e1, Entity* e2);
	};
}



