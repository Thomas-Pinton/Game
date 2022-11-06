#pragma once

#include <iostream>
#include "lista.hpp"
#include "EntitiesList.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
#include "Jogador.hpp"
#include "Tile.hpp"
#include "Inimigo.hpp"

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

