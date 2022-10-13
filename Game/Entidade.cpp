#include "Entidade.hpp"
#include <iostream>

Entidade::Entidade()
	: Ente()
{
	velocidade.x = 0; velocidade.y = 0;
	aceleracao.x = 0; aceleracao.y = 0;
}

void Entidade::atualizaPosicao(float deltaTime)
{
	velocidade += aceleracao * deltaTime;
	posicao += velocidade * deltaTime;
	sprite.setPosition(sf::Vector2f(posicao.x, posicao.y));
}