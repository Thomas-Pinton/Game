#pragma once

#include "Ente.hpp"
#include "Coordenada.hpp"

class Entidade : public Ente
{
private:
	
public:
	Coordenada<float> aceleracao;
	Coordenada<float> velocidade;
	Entidade();
	void atualizaPosicao(float deltaTime);
	void atualizaPosicao(Coordenada<float> coord);
};