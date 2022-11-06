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
	virtual void executar(float deltaTime);
	void setPular(bool p);

};
