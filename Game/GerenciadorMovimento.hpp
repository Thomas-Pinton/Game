#pragma once

#include "Gerenciador.hpp"

class GerenciadorMovimento : public Gerenciador {
private:
	sf::Clock clock;
	float deltaTime;
public:
	GerenciadorMovimento();
	void atualizaPosicoes(float deltaTime);
};