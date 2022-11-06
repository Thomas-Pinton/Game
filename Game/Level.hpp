#pragma once

#include <iostream>
#include "List.hpp"
#include "EntitiesList.hpp"
#include "GraphicManager.hpp"
#include "ColisionManager.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "Enemy.hpp"

class Level : public Ente
{
private:
	EntitiesList entities;
	GerenciadorColisoes gerCol;
	GerenciadorGrafico gerGraf;
public:
	Level(Janela* window);
	~Level();
	void create(Janela* window);
	virtual void executar(Janela* w);
	void gerenciarColisoes(Janela* window);
};

