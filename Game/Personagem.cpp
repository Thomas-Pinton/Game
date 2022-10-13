#include "Personagem.hpp"

Personagem::Personagem()
	: Entidade()
{
	vida = 100;
}

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