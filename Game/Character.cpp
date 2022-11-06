#include "Character.hpp"

Personagem::Personagem()
	: Entidade()
{
	vida = 100;
	// Todo personagem, por padrão, sofre efeito da gravidade
	aceleracao.y = 1000;
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