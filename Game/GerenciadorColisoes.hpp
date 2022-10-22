#pragma once

#include "Coordenada.hpp"
#include "Gerenciador.hpp"
#include "Janela.hpp"

/*

Implementando o tipo de colis�o padr�o (comparar todos os elemento 1 a 1)

� poss�vel, no futuro, para otimizar o jogo, 
realizar um sistema de colis�es que divide o espa�o e compara elementos dentro daque espa�o

*/

class GerenciadorColisoes : public Gerenciador
{
public:
	GerenciadorColisoes() // :
		//staticEntities(),
		//movingEntities()
	{
	}

	// posso ter uma fun��o gen�rica addEntity que tem sobrecarga de par�metros (a depender do tipo de entidade)

	void checaColisoes(Janela* janela);
	Coordenada<float> checaColisao(Entidade* e1, Entidade* e2);
};

