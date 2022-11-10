#include "ColisionManager.hpp"
#include <iostream>

/*
Essa maneira de colis�o n�o � a mais efetiva.
Outra maneira de fazer as colis�es seria dividindo o espa�o em n peda�os e verificar
se os objetos dentro de cada espa�o est�o colidindo
*/

ColisionManager::ColisionManager(Window* pW)
{
	pWindow = pW;
}

void ColisionManager::checkColisions()
{
	const int WIDTH = pWindow->getWIDTH();
	const int HEIGHT = pWindow->getHEIGHT();

	std::list<Entity*>::iterator i;
	std::list<Entity*>::iterator j;
	std::list<Player*>::iterator k;

	// player com resto

	for (k = players.begin(); k != players.end(); k++)
	{
		(*k)->acceleration = { 0.0f, 1000.0 };
		for (j = staticEntities.begin(); j != staticEntities.end(); j++)
		{
			Coordinate<float> ajuste = checkColision(*k, *j);
			if (ajuste.x > 0.1 || ajuste.x < -0.1 || 
				ajuste.y > 0.1 || ajuste.y < -0.1) // houve colis�o, checando tanto para positivos como negativos
			{
				if (ajuste.y < 0.01f) // colis�o com o ch�o
					(*k)->setJump(true);
				// isso faz com que o personagem possa encostar no ch�o, cair e conseguir pular  no ar enquanto est� caindo,
				// ser� que esse comportamento � desej�vel?

				(*k)->acceleration = { 0.0f, 0.0f };
				(*k)->speed.y = 0.0;
				(*k)->updatePosition(ajuste);
			}
		}

		// considerando que todas as moving entities s�o inimigos
		for (i = movingEntities.begin(); i != movingEntities.end(); i++)
		{
			while ((*i)->alive == false)
			{
				i++;
				std::cout << "Morto" << std::endl;
			}
				
			Coordinate<float> ajuste = checkColision(*k, *i);

			if (ajuste.y < -0.1f)
				// se bateu na cabe�a do inimgo ele morreu
			{
				std::cout << "Matei o inimigo" << std::endl;
				(*k)->updatePosition(ajuste);

				//movingEntities.erase(i);
				(*i)->alive = false;

				//delete *i;

			} else if (ajuste.x > 0.1f || ajuste.x < -0.1f ||
				ajuste.y > 0.1f || ajuste.y < -0.1f) // houve colis�o, checando tanto para positivos como negativos
			{
				std::cout << "Morri" << std::endl;
				(*k)->updatePosition(ajuste); 
				// perdeu
				pWindow->config.close();
			}
		}

	}

	// player com parede

	for (k = players.begin(); k != players.end(); k++)
	{
		float tamanho = (*k)->getSize().x / 2, posicao = (*k)->getPosition().x;

		//poderia criar uma fun��o setPosition, que colocaria a posicao exata (0 e WIDTH - tamanho, respectivamente)
		if (tamanho > posicao) // se est� indo para fora pela esquerda
		{
			Coordinate<float> coord(tamanho - posicao, 0);
			(*k)->updatePosition(coord);
		}

		if (posicao + tamanho > WIDTH) // se est� indo para fora pela direita
		{
			Coordinate<float> coord(-1 * (posicao + tamanho - WIDTH), 0);
			(*k)->updatePosition(coord);
		}

	}

	//moving com static
	///*

	for (i = movingEntities.begin(); i != movingEntities.end(); i++)
	{

		while ((*i)->alive == false)
				i++;

		for (j = staticEntities.begin()++; j != staticEntities.end(); j++)
		{

			Coordinate<float> ajuste = checkColision(*i, *j);

			if (ajuste.x > 0.1f || ajuste.x < -0.1f ||
				ajuste.y > 0.1f || ajuste.y < -0.1f)
			{
				(*i)->acceleration.y = 0.0f;
				(*i)->speed.y = 0.0;
				(*i)->updatePosition(ajuste);
			}
			/* // antigo checador de colis�es

			if (somaTamanhos.x > dx && somaTamanhos.y > dy) // colidiu
			{
				if (dif_x < dif_y)
				{
					if (pos1.x > pos2.x)
					{
						Coordinate<float> coord(dif_x, 0);
						(*i)->updatePosition(coord);
					}
					else 
					{
						Coordinate<float> coord(-1 * dif_x, 0);
						(*i)->updatePosition(coord);
					}	
				}
				else
				{
					if (pos1.y > pos2.y)
					{
						Coordinate<float> coord(0, dif_y);
						(*i)->updatePosition(coord);
					}
					else
					{
						//colidiu com o ch�o, se for o player pode pular novamente
						Coordinate<float> coord(0, -1 * dif_y);
						(*i)->updatePosition(coord);
					}
				}
					
			}

			*/
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


/*
Coordinate<float> ColisionManager::checkColision(Entity* e1, Entity* e2)
{
	Coordinate<float> tam1 = e1->getSize(); Coordinate<float> pos1 = e1->getPosition();
	Coordinate<float> tam2 = e2->getSize(); Coordinate<float> pos2 = e2->getPosition();
	
	Coordinate<float> distTamanhos = (tam1 + tam2) / 2;

	float dx = pos1.x - pos2.x > 0 ? pos1.x - pos2.x : pos2.x - pos1.x;
	float dy = pos1.y - pos2.y > 0 ? pos1.y - pos2.y : pos2.y - pos1.y;
	
	// pegar dx em m�dulo, pois pode ser negativo
	if (distTamanhos.x > dx && distTamanhos.y > dy) // tem que passar tanto em x quanto em y para haver colis�o
		return true;

	return 0;
}
*/