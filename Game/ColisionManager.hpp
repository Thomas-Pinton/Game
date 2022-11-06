#pragma once

#include <iostream>
#include <list>
#include "Coordinate.hpp"
#include "Window.hpp"
#include "Player.hpp"


/*

Implementando o tipo de colisão padrão (comparar todos os elemento 1 a 1)

É possível, no futuro, para otimizar o jogo, 
realizar um sistema de colisões que divide o espaço e compara elementos dentro daque espaço

*/

class GerenciadorColisoes
{
public:
	std::list<Entidade*> staticEntities;
	std::list<Jogador*> players;
	std::list<Entidade*> movingEntities;
public:
	GerenciadorColisoes();

	// posso ter uma função genérica addEntity que tem sobrecarga de parâmetros (a depender do tipo de entidade)

	void checaColisoes(Janela* janela);
	Coordenada<float> checaColisao(Ente* e1, Ente* e2);
};

