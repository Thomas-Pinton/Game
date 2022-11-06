#pragma once

#include "SFML/Graphics.hpp"
#include "Coordenada.hpp"
#include "Janela.hpp"
#include "Level.hpp"

#include <iostream>

class Jogo
{
private:
	Janela window;
	Level level1;
public:
	Jogo();
	void executar();
};
