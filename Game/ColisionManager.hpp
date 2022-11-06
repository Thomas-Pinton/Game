#pragma once

#include <iostream>
#include <list>
#include "Coordinate.hpp"
#include "Window.hpp"
#include "Player.hpp"


/*

Implementando o tipo de colis�o padr�o (comparar todos os elemento 1 a 1)

� poss�vel, no futuro, para otimizar o jogo, 
realizar um sistema de colis�es que divide o espa�o e compara elementos dentro daque espa�o

*/

class GerenciadorColisoes
{
public:
	std::list<Entidade*> staticEntities;
	std::list<Jogador*> players;
	std::list<Entidade*> movingEntities;
public:
	GerenciadorColisoes();

	// posso ter uma fun��o gen�rica addEntity que tem sobrecarga de par�metros (a depender do tipo de entidade)

	void checaColisoes(Janela* janela);
	Coordenada<float> checaColisao(Ente* e1, Ente* e2);
};

