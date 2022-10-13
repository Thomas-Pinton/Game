#pragma once

#include "Ente.hpp"
#include "Coordenada.hpp"

class Entidade : public Ente
{
private:
	
public:
	Coordenada<float> velocidade;
	Coordenada<float> aceleracao;
	Entidade();
	void atualizaPosicao(float deltaTime);
};