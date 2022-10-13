#include "Entidade.hpp"

Entidade::Entidade()
	: Ente()
{
	velocidade.x = 0; velocidade.y = 0;
	aceleracao.x = 0; aceleracao.y = 0;
}

void Entidade::atualizaPosicao()
{
	velocidade += aceleracao;
	posicao += velocidade;
}