#pragma once

#include <iostream>
#include <list>
#include "Jogador.hpp"
#include "Tile.hpp"
#include "Janela.hpp"

class Gerenciador
{
protected:
	static std::list<Ente*> staticEntities;
	
	
public:
	// momentâneo
	static std::list<Jogador*> players;
	static std::list<Entidade*> movingEntities;
	Gerenciador()
	{
	}
	Gerenciador(Janela* window) 
	{
		// criar entes
		Jogador* player1 = new Jogador();

		player1->setTamanho({ 100, 100 });
		player1->setPosicao({ 50.0f, 50.0f });

		addPlayer(player1);

		Tile* t = NULL;

		std::list<Tile*>::iterator i;

		std::list<Tile*> tiles; // temporário

		for (int i = 0; i * 100 + 50 < window->getWIDTH() + 300; i++) // will need to work with memory managent later
		{
			t = new Tile;
			t->rectangle.setFillColor(sf::Color(255 / ((i % 2) + 1), 100, 150));
			t->setTamanho({ 100, 100 });
			t->setPosicao({ (float)(i * 100) + 50, (float)window->getHEIGHT() / 2 + 200 });
			addStaticEntity((Entidade*) t);
			tiles.push_back(t);
		}

	}
	void addStaticEntity(Ente* pE) {
		staticEntities.push_back(pE);
	}
	void addMovingEntity(Entidade* pE) {
		movingEntities.push_back(pE);
	}
	void addPlayer(Jogador* pP) {
		players.push_back(pP);
	}
};
