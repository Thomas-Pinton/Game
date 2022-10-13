#pragma once

#include "Personagem.hpp"

class Jogador : public Personagem
{
public:
	Jogador() : Personagem() {}
	void checkKeys()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			velocidade.x = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			velocidade.y = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			velocidade.x = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			velocidade.y = -1;
	}
};
