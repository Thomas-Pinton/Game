#pragma once

#include "Personagem.hpp"

class Jogador : public Personagem
{
public:
	Jogador() : Personagem() 
	{
		posicao.x = 750.0;
		posicao.x = 400.0;
		// Posicão inicial
	}
	void checkKeys()
	{
		velocidade.x = 0; velocidade.y = 0; // padrão, caso nenhuma tecla esteja sendo apertada
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			velocidade.x = -0.2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			velocidade.y = 0.2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			velocidade.x = 0.2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			velocidade.y = -0.2;
	}
};
