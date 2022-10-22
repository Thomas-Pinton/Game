#pragma once

#include "Coordenada.hpp"
#include "Gerenciador.hpp"
#include "Janela.hpp"

/*

Implementando o tipo de colisão padrão (comparar todos os elemento 1 a 1)

É possível, no futuro, para otimizar o jogo, 
realizar um sistema de colisões que divide o espaço e compara elementos dentro daque espaço

*/

class GerenciadorColisoes : public Gerenciador
{
public:
	GerenciadorColisoes() // :
		//staticEntities(),
		//movingEntities()
	{
	}

	// posso ter uma função genérica addEntity que tem sobrecarga de parâmetros (a depender do tipo de entidade)

	void checaColisoes(Janela* janela);
	Coordenada<float> checaColisao(Entidade* e1, Entidade* e2);
};

