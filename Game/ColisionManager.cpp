#include "ColisionManager.hpp"
#include <iostream>

/*
Essa maneira de colis�o n�o � a mais efetiva.
Outra maneira de fazer as colis�es seria dividindo o espa�o em n peda�os e verificar
se os objetos dentro de cada espa�o est�o colidindo
*/

GerenciadorColisoes::GerenciadorColisoes()
{
}

void GerenciadorColisoes::checaColisoes(Janela* window)
{
	const int WIDTH = window->getWIDTH();
	const int HEIGHT = window->getHEIGHT();

	std::list<Entidade*>::iterator i;
	std::list<Entidade*>::iterator j;
	std::list<Jogador*>::iterator k;

	// player com resto

	for (k = players.begin(); k != players.end(); k++)
	{
		(*k)->aceleracao = { 0.0f, 1000.0 };
		for (j = staticEntities.begin(); j != staticEntities.end(); j++)
		{
			Coordenada<float> ajuste = checaColisao(*k, *j);
			if (ajuste.x > 0.1 || ajuste.x < -0.1 || 
				ajuste.y > 0.1 || ajuste.y < -0.1) // houve colis�o, checando tanto para positivos como negativos
			{
				if (ajuste.y < 0.01f) // colis�o com o ch�o
					(*k)->setPular(true);
				// isso faz com que o personagem possa encostar no ch�o, cair e conseguir pular  no ar enquanto est� caindo,
				// ser� que esse comportamento � desej�vel?

				(*k)->aceleracao = { 0.0f, 0.0f };
				(*k)->velocidade.y = 0.0;
				(*k)->atualizaPosicao(ajuste);
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
				
			Coordenada<float> ajuste = checaColisao(*k, *i);

			if (ajuste.y < -0.1f)
				// se bateu na cabe�a do inimgo ele morreu
			{
				std::cout << "Matei o inimigo" << std::endl;
				(*k)->atualizaPosicao(ajuste);

				//movingEntities.erase(i);
				(*i)->alive = false;

				//delete *i;

			} else if (ajuste.x > 0.1f || ajuste.x < -0.1f ||
				ajuste.y > 0.1f || ajuste.y < -0.1f) // houve colis�o, checando tanto para positivos como negativos
			{
				std::cout << "Morri" << std::endl;
				(*k)->atualizaPosicao(ajuste); 
				// perdeu
				window->config.close();
			}
		}

	}

	// player com parede

	for (k = players.begin(); k != players.end(); k++)
	{
		float tamanho = (*k)->getTamanho().x / 2, posicao = (*k)->getPosicao().x;

		//poderia criar uma fun��o setPosicao, que colocaria a posicao exata (0 e WIDTH - tamanho, respectivamente)
		if (tamanho > posicao) // se est� indo para fora pela esquerda
		{
			Coordenada<float> coord(tamanho - posicao, 0);
			(*k)->atualizaPosicao(coord);
		}

		if (posicao + tamanho > WIDTH) // se est� indo para fora pela direita
		{
			Coordenada<float> coord(-1 * (posicao + tamanho - WIDTH), 0);
			(*k)->atualizaPosicao(coord);
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

			Coordenada<float> ajuste = checaColisao(*i, *j);

			if (ajuste.x > 0.1f || ajuste.x < -0.1f ||
				ajuste.y > 0.1f || ajuste.y < -0.1f)
			{
				(*i)->aceleracao.y = 0.0f;
				(*i)->velocidade.y = 0.0;
				(*i)->atualizaPosicao(ajuste);
			}
			/* // antigo checador de colis�es

			if (somaTamanhos.x > dx && somaTamanhos.y > dy) // colidiu
			{
				if (dif_x < dif_y)
				{
					if (pos1.x > pos2.x)
					{
						Coordenada<float> coord(dif_x, 0);
						(*i)->atualizaPosicao(coord);
					}
					else 
					{
						Coordenada<float> coord(-1 * dif_x, 0);
						(*i)->atualizaPosicao(coord);
					}	
				}
				else
				{
					if (pos1.y > pos2.y)
					{
						Coordenada<float> coord(0, dif_y);
						(*i)->atualizaPosicao(coord);
					}
					else
					{
						//colidiu com o ch�o, se for o player pode pular novamente
						Coordenada<float> coord(0, -1 * dif_y);
						(*i)->atualizaPosicao(coord);
					}
				}
					
			}

			*/
		}
	}

	//*/
}


// checa colis�o e retorna o quanto deve ser ajustado
Coordenada<float> GerenciadorColisoes::checaColisao(Ente* e1, Ente* e2)
{
	Coordenada<float> tam1 = (e1)->getTamanho(); Coordenada<float> pos1 = (e1)->getPosicao();
	Coordenada<float> tam2 = (e2)->getTamanho(); Coordenada<float> pos2 = (e2)->getPosicao();

	Coordenada<float> somaTamanhos = (tam1 + tam2) / 2; //soma da metade dos dois tamanhos

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
Coordenada<float> GerenciadorColisoes::checaColisao(Entidade* e1, Entidade* e2)
{
	Coordenada<float> tam1 = e1->getTamanho(); Coordenada<float> pos1 = e1->getPosicao();
	Coordenada<float> tam2 = e2->getTamanho(); Coordenada<float> pos2 = e2->getPosicao();
	
	Coordenada<float> distTamanhos = (tam1 + tam2) / 2;

	float dx = pos1.x - pos2.x > 0 ? pos1.x - pos2.x : pos2.x - pos1.x;
	float dy = pos1.y - pos2.y > 0 ? pos1.y - pos2.y : pos2.y - pos1.y;
	
	// pegar dx em m�dulo, pois pode ser negativo
	if (distTamanhos.x > dx && distTamanhos.y > dy) // tem que passar tanto em x quanto em y para haver colis�o
		return true;

	return 0;
}
*/