#pragma once

#include "Entity.hpp"

class Personagem : public Entidade
{
protected:
	int vida;
public:
	Personagem();
	const int getVida();
	void setVida(int novaVida);
	void diminuirVida(int qtd);
	void aumentarVida(int qtd);
};
