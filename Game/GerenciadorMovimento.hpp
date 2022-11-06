#pragma once

#include "SFML/Graphics.hpp"

class GerenciadorMovimento 
{
private:
	sf::Clock clock;
	float deltaTime;
public:
	GerenciadorMovimento();
	void atualizaPosicoes(float deltaTime);
};