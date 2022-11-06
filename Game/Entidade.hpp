#pragma once

#include "Ente.hpp"
#include "Coordenada.hpp"

class Entidade : public Ente
{
private:
	
public:
	bool alive;
	Coordenada<float> aceleracao;
	Coordenada<float> velocidade;
	Entidade();
	void atualizaPosicao(float deltaTime);
	void atualizaPosicao(Coordenada<float> coord);
	virtual void executar(float deltaTime);
};