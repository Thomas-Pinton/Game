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
		float vel = 3.0 * 100;
		velocidade.x = 0; velocidade.y = 0; // padrão, caso nenhuma tecla esteja sendo apertada
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			velocidade.x = -vel;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			velocidade.y = vel;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			velocidade.x = vel;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			velocidade.y = -vel;
	}
};
