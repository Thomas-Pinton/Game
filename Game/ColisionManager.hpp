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

class ColisionManager
{
public:
	std::list<Entity*> staticEntities;
	std::list<Player*> players;
	std::list<Entity*> movingEntities;
public:
	ColisionManager();

	// posso ter uma fun��o gen�rica addEntity que tem sobrecarga de par�metros (a depender do tipo de entidade)

	void checkColisions(Window* janela);
	Coordinate<float> checkColision(Being* e1, Being* e2);
};

