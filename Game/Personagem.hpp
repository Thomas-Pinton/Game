#pragma once

#include "Entidade.hpp"

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

const int Personagem::getVida()
{
	return vida;
}

void Personagem::setVida(int novaVida)
{
	vida = novaVida;
}

void Personagem::diminuirVida(int qtd)
{
	vida -= qtd;
}

void Personagem::aumentarVida(int qtd)
{
	vida += qtd;
}
