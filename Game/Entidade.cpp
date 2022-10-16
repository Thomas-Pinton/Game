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
	std::cout << "Velocidade antes: " << velocidade.y << std::endl;
	velocidade += aceleracao * deltaTime;
	std::cout << "Velocidade depois: " << velocidade.y << std::endl;
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