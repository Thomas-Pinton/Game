#include "ColisionManager.hpp"
#include "Constants.hpp"
#include <iostream>

/*
Essa maneira de colis�o n�o � a mais efetiva.
Outra maneira de fazer as colis�es seria dividindo o espa�o em n peda�os e verificar
se os objetos dentro de cada espa�o est�o colidindo
*/

namespace Manager
{

	ColisionManager::ColisionManager(Window* pW)
	{
		if (pW == NULL)
		{
			std::cout << "Error while opening window" << std::endl;
			exit(1);
		}
		pWindow = pW;
	}

	void ColisionManager::checkColisions()
	{
		checkColisionsPlayerEnemy();
		checkColisionsPlayerObstacles();
		checkColisionsPlayerProjectiles();
		checkColisionsEnemyObstacles();
		checkColisionsPlayerWall();
		checkColisionsEnemyObstacles();
		checkColisionsProjectilesObstacles();
	}


	void ColisionManager::checkColisionsPlayerEnemy()
	{
		std::list<Enemy*>::iterator enemy;
		std::list<Player*>::iterator player;

		for (player = players.begin(); player != players.end(); player++)
		{
			if ((*player)->alive)
			{
				for (enemy = enemies.begin(); enemy != enemies.end(); enemy++)
				{
					if ((*enemy)->alive) // só chegar colisão se ele estiver vivo
					{
						Coordinate<float> ajuste = checkColision(*player, *enemy);

						if (ajuste.y < -0.01f && (*player)->speed.y > 0.1f)
							// se bateu na cabe�a do inimgo ele morreu
						{
							std::cout << "Dei dano" << std::endl;
							std::cout << ajuste << std::endl;

							(*player)->updatePosition(ajuste);

							(*enemy)->decreaseHp(1);
							(*player)->addPoints(50);

							//(*player)->speed.y = -sqrtf(2 * GRAVITY * 70); (*player)->setJump(false);
							(*player)->executeJump(-sqrtf(2 * GRAVITY * 70));
							//jogador pula cada vez que bate na cabeca de um inimigo

							std::cout << "Pontuacao: " << (*player)->getPoints() << std::endl;

						}
						else if (ajuste.x > 0.01f || ajuste.x < -0.01f ||
							ajuste.y > 0.01f) // houve colis�o, checando tanto para positivos como negativos
						{
							std::cout << "Morri" << std::endl;
							// perdeu
							std::cout << "Damage " << (*enemy)->getDamage() << std::endl;
							(*player)->decreaseHp((*enemy)->getDamage());
							// diminuir hp pelo dano que o inimigo causa
							return;
						}
					}
				}
			}
		}
	}

	void ColisionManager::checkColisionsPlayerObstacles()
	{
		std::list<Obstacle*>::iterator obstacle;
		std::list<Player*>::iterator player;

		for (player = players.begin(); player != players.end(); player++)
		{
			(*player)->acceleration = { 0.0f, GRAVITY };
			// if not colliding, these are the base values
			// if is coliding, then the values will be changed

			for (obstacle = obstacles.begin(); obstacle != obstacles.end(); obstacle++)
			{
				Coordinate<float> ajuste = checkColision(*player, *obstacle);

				if (ajuste.x > 0.001 || ajuste.x < -0.001 ||
					ajuste.y > 0.001 || ajuste.y < -0.001) // houve colis�o, checando tanto para positivos como negativos
				{
					if (ajuste.y > 0.001 || ajuste.y < -0.001)
						(*player)->speed.y = 0.0f;
					if (ajuste.y < -0.001f) // colis�o com o ch�o
					{
						(*player)->setJump(true);
						(*player)->acceleration = { 0.0f, 0.0f };
						(*obstacle)->affectPlayer(*player);
					}

					// isso faz com que o personagem possa encostar no ch�o, cair e conseguir pular  no ar enquanto est� caindo,
				// ser� que esse comportamento � desej�vel?

				//(*k)->acceleration = { 0.0f, 0.0f };
				//(*k)->speed.y = 0.0;
					(*player)->updatePosition(ajuste);
				}
			}

			// considerando que todas as moving entities s�o inimigos

		}
	}

	void ColisionManager::checkColisionsPlayerProjectiles()
	{
		std::list<Projectile*>::iterator projectile;
		std::list<Player*>::iterator player;

		for (player = players.begin(); player != players.end(); player++)
		{
			(*player)->acceleration = { 0.0f, GRAVITY };
			// if not colliding, these are the base values
			// if is coliding, then the values will be changed

			for (projectile = projectiles.begin(); projectile != projectiles.end(); projectile++)
			{
				if ((*projectile)->alive) // só chegar colisão se ele estiver vivo
				{
					Coordinate<float> ajuste = checkColision(*player, *projectile);

					if (ajuste.x > 0.1 || ajuste.x < -0.1 ||
						ajuste.y > 0.1 || ajuste.y < -0.1)
					{
						std::cout << "Morri" << std::endl;
						std::cout << "Coliding with projectile " << std::endl;
						// perdeu
						(*player)->decreaseHp((*projectile)->getDamage());
						return;
					}

				}
			}

		}
	}

	void ColisionManager::checkColisionsEnemyObstacles()
	{
		std::list<Enemy*>::iterator enemy;
		std::list<Obstacle*>::iterator obstacle;
		for (enemy = enemies.begin(); enemy != enemies.end(); enemy++)
		{

			if ((*enemy)->alive)
			{
				(*enemy)->acceleration.y = GRAVITY;
				for (obstacle = obstacles.begin()++; obstacle != obstacles.end(); obstacle++)
				{

					Coordinate<float> ajuste = checkColision(*enemy, *obstacle);

					if (ajuste.x > 0.01f || ajuste.x < -0.01f ||
						ajuste.y > 0.01f || ajuste.y < -0.01f)
					{
						(*enemy)->updatePosition(ajuste);

						(*obstacle)->affectEnemy(*enemy);

						if (ajuste.y < -0.01f)
						{
							(*enemy)->acceleration.y = 0.0f;
							(*enemy)->speed.y = 0.0f;
						}

					}
				}
			}
		}
	}

	void ColisionManager::checkColisionsProjectilesObstacles()
	{
		std::list<Projectile*>::iterator projectile;
		std::list<Obstacle*>::iterator obstacle;
		for (projectile = projectiles.begin(); projectile != projectiles.end(); projectile++)
		{

			if ((*projectile)->alive)
			{
				(*projectile)->acceleration.y = GRAVITY;
				for (obstacle = obstacles.begin()++; obstacle != obstacles.end(); obstacle++)
				{

					Coordinate<float> ajuste = checkColision(*projectile, *obstacle);

					if (ajuste.x > 0.1f || ajuste.x < -0.01f ||
						ajuste.y > 0.001f || ajuste.y < -0.01f)
					{

						(*projectile)->updatePosition(ajuste);

						if (ajuste.y < -0.01f)
						{
							(*projectile)->acceleration.y = 0.0f;
							(*projectile)->speed.y = 0.0f;
						}

						//(*projectile)->setAlive(false);
					}
				}
			}
		}
	}

	void ColisionManager::checkColisionsPlayerWall()
	{
		const int WIDTH = pWindow->getWIDTH();
		std::list<Player*>::iterator player;

		for (player = players.begin(); player != players.end(); player++)
		{
			float tamanho = (*player)->getSize().x / 2, posicao = (*player)->getPosition().x;

			//poderia criar uma fun��o setPosition, que colocaria a posicao exata (0 e WIDTH - tamanho, respectivamente)
			if (tamanho > posicao) // se est� indo para fora pela esquerda
			{
				Coordinate<float> coord(tamanho - posicao, 0);
				(*player)->updatePosition(coord);
			}

			if (posicao + tamanho > WIDTH) // se est� indo para fora pela direita
			{
				Coordinate<float> coord(-1 * (posicao + tamanho - WIDTH), 0);
				(*player)->updatePosition(coord);
			}

		}
	}

	// checa colis�o e retorna o quanto deve ser ajustado
	Coordinate<float> ColisionManager::checkColision(Entity* e1, Entity* e2)
	{
		Coordinate<float> tam1 = (e1)->getSize(); Coordinate<float> pos1 = (e1)->getPosition();
		Coordinate<float> tam2 = (e2)->getSize(); Coordinate<float> pos2 = (e2)->getPosition();

		Coordinate<float> somaTamanhos = (tam1 + tam2) / 2; //soma da metade dos dois tamanhos

		float dx = pos1.x - pos2.x > 0 ? pos1.x - pos2.x : pos2.x - pos1.x;
		float dy = pos1.y - pos2.y > 0 ? pos1.y - pos2.y : pos2.y - pos1.y;

		// pegar dx e dy em m�dulo, pois pode ser negativo
		float dif_x = somaTamanhos.x - dx, dif_y = somaTamanhos.y - dy;
		if (somaTamanhos.x > dx && somaTamanhos.y > dy) // colidiu
		{
			if (dif_x < dif_y)
			{
				if (pos1.x > pos2.x)
				{
					return { dif_x, 0.0f };
				}
				else
				{
					return { -1 * dif_x, 0.0f };
				}
			}
			else
			{
				if (pos1.y > pos2.y)
				{
					return { 0, dif_y };
				}
				else
				{
					return { 0, -1* dif_y };
				}
			}
		}
		return { 0.0f, 0.0f };
	}

}