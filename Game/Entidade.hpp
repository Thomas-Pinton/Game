#pragma once

#include "Ente.hpp"
#include "Coordenada.hpp"

class Entidade : public Ente
{
private:
	Coordenada<float> velocidade;
	Coordenada<float> aceleracao;
public:
	Entidade();
	void atualizaPosicao();
};

Entidade::Entidade()
{
	velocidade.x = 0; velocidade.y = 0;
	aceleracao.x = 0; aceleracao.y = 0;
}

void Entidade::atualizaPosicao()
{
	velocidade += aceleracao;
	posicao += velocidade;
}