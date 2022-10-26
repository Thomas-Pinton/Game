#pragma once

#include "Personagem.hpp"
#include "math.h"

class Jogador : public Personagem
{
private:
	bool podePular;
public:
	Jogador();

	void checkKeys();

	void setPular(bool p);

};
