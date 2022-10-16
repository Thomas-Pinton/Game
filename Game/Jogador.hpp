#pragma once

#include "Personagem.hpp"
#include "math.h"

class Jogador : public Personagem
{
private:
	bool podePular;
public:
	Jogador() : Personagem() 
	{
		posicao.x = 0.0;
		posicao.y = 0.0;
		podePular = false;
		// Posic�o inicial
	}
	void checkKeys()
	{
		float vel = 3.0 * 100;

		velocidade.x = 0; // padr�o, caso nenhuma tecla esteja sendo apertada

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			velocidade.x = -vel;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || 
			sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			velocidade.y = vel;
		// Para baixo n�o faz nada (por enquanto)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			velocidade.x = vel;
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) && podePular)
			velocidade.y = -sqrtf(2 * 750 * 200); podePular = false;
			// 2 * gravidade * altura do pulo
	}
	void setPular(bool p)
	{
		podePular = p;
	}
};
