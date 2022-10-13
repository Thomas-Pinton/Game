#pragma once
#include "SFML/Graphics.hpp"
#include "Coordenada.hpp"

// Tudo aquilo que tem representa��o gr�fica
// Ex.: Personagem, blocos, menu, backgrounds, etc

class Ente
{
protected:
	int id;
	Coordenada<float> posicao;
	Coordenada<float> tamanho;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Ente();
};

