#pragma once

#include "SFML/Graphics.hpp"
#include "Coordenada.hpp"
#include "Jogador.hpp"
#include "GerenciadorColisoes.hpp"
#include "Tile.hpp"
#include "Janela.hpp"
#include <iostream>

class Jogo
{
private:
	Janela window;
	GerenciadorColisoes gerCol;
	Jogador player1;
public:
	Jogo();
	void executar();
};
