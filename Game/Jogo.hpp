#pragma once

#include "SFML/Graphics.hpp"
#include "Coordenada.hpp"
#include "Jogador.hpp"
#include "GerenciadorColisoes.hpp"
#include "GerenciadorGrafico.hpp"
#include "Tile.hpp"
#include "Janela.hpp"

#include <iostream>

class Jogo
{
private:
	Janela window;
	Gerenciador ger;
	GerenciadorColisoes gerCol;
	GerenciadorGrafico gerGraf;
	Jogador player1;
public:
	Jogo();
	void executar();
};
