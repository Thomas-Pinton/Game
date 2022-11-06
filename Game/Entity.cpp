#include "Entity.hpp"
#include <iostream>

Entidade::Entidade()
	: Ente(),
	alive(true)
{
	velocidade.x = 0; velocidade.y = 0;
	aceleracao.x = 0; aceleracao.y = 0;
}

void Entidade::atualizaPosicao(float deltaTime)
{
	velocidade += aceleracao * deltaTime;
	posicao += velocidade * deltaTime;
	rectangle.setPosition(sf::Vector2f(posicao.x, posicao.y));
	//sprite.setPosition(sf::Vector2f(posicao.x, posicao.y));
}

void Entidade::atualizaPosicao(Coordenada<float> coord)
{
	posicao += coord;
	rectangle.setPosition(sf::Vector2f(posicao.x, posicao.y));
	//sprite.setPosition(sf::Vector2f(posicao.x, posicao.y));
}

void Entidade::executar(float deltaTime)
{
	if (id > 19)
		std::cout << "Pos" << posicao << std::endl;
	atualizaPosicao(deltaTime);
}