#include "ColisionManager.hpp"
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
		pWindow = pW;
	}

	void ColisionManager::checkColisions()
	{
		const int WIDTH = pWindow->getWIDTH();
		const int HEIGHT = pWindow->getHEIGHT();

		std::list<Entity*>::iterator movingE;
		std::list<Entity*>::iterator staticE;
		std::list<Player*>::iterator player;

		// player com resto

		for (player = players.begin(); player != players.end(); player++)
		{
			(*player)->acceleration = { 0.0f, 1000.0 };
			for (staticE = staticEntities.begin(); staticE != staticEntities.end(); staticE++)
			{
				Coordinate<float> ajuste = checkColision(*player, *staticE);
				if (ajuste.x > 0.1 || ajuste.x < -0.1 || 
					ajuste.y > 0.1 || ajuste.y < -0.1) // houve colis�o, checando tanto para positivos como negativos
				{
					if (ajuste.y < -0.01f) // colis�o com o ch�o
					{
						(*player)->setJump(true);
						(*player)->acceleration = { 0.0f, 0.0f };
						(*player)->speed.y = 0.0;
					}
					if (ajuste.y > 0.1f && (*player)->speed.y > 0.0f)
					{
						(*player)->speed.y = 0.0f;
						// pensar em como fazer ele bater a cabeca e comecar a cair
					}
						// isso faz com que o personagem possa encostar no ch�o, cair e conseguir pular  no ar enquanto est� caindo,
					// ser� que esse comportamento � desej�vel?

					//(*k)->acceleration = { 0.0f, 0.0f };
					//(*k)->speed.y = 0.0;
					(*player)->updatePosition(ajuste);
				}
			}

			// considerando que todas as moving entities s�o inimigos
			for (movingE = movingEntities.begin(); movingE != movingEntities.end(); movingE++)
			{
				if ((*movingE)->alive) // só chegar colisão se ele estiver vivo
				{
					Coordinate<float> ajuste = checkColision(*player, *movingE);

					if (ajuste.y < -0.1f && (*player)->speed.y > 0.1f)
						// se bateu na cabe�a do inimgo ele morreu
					{
						std::cout << "Matei o inimigo" << std::endl;
						std::cout << ajuste << std::endl;

						(*player)->updatePosition(ajuste);

						//movingEntities.erase(i);
						(*movingE)->alive = false;
						(*player)->addPoints(50);
						//delete *i;

					}
					else if (ajuste.x > 0.1f || ajuste.x < -0.1f ||
						ajuste.y > 0.1f) // houve colis�o, checando tanto para positivos como negativos
					{
						std::cout << "Morri" << std::endl;
						// perdeu
						std::cout << "Closing Window" << std::endl;
						pWindow->config.close();
					}
				}
			}

		}

		// player com parede

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

		//moving com static
		///*

		for (movingE = movingEntities.begin(); movingE != movingEntities.end(); movingE++)
		{

			if ((*movingE)->alive)
			{
				for (staticE = staticEntities.begin()++; staticE != staticEntities.end(); staticE++)
				{

					Coordinate<float> ajuste = checkColision(*movingE, *staticE);

					if (ajuste.x > 0.1f || ajuste.x < -0.1f ||
						ajuste.y > 0.1f || ajuste.y < -0.1f)
					{
						std::cout << "Ajuste " << ajuste << std::endl;

						(*movingE)->updatePosition(ajuste);

						if (ajuste.y < -0.01f)
						{
							(*movingE)->acceleration.y = 0.0f;
							(*movingE)->speed.y = 0.0f;
						}
							

						// modulo da velocidade
						/*
						if ((*movingE)->speed.x * (*movingE)->speed.x < (*movingE)->speed.y * (*movingE)->speed.y)
							(*movingE)->acceleration.y = 0.0f;
						else 
							(*movingE)->speed.x *= -1;
						*/
					}
				}
			}
		}

		//*/
	}


	// checa colis�o e retorna o quanto deve ser ajustado
	Coordinate<float> ColisionManager::checkColision(Being* e1, Being* e2)
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