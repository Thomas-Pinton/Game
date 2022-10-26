#pragma once

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Coordenada.hpp"

// Tudo aquilo que tem representa��o gr�fica
// Ex.: Personagem, blocos, menu, backgrounds, etc

class Ente
{
protected:
	static int id_count;
	int id;
	Coordenada<float> posicao;
	Coordenada<float> tamanho;
	sf::Texture texture;
public:
	sf::RectangleShape rectangle; // tempor�rio
	sf::Sprite sprite;

	Ente();

	void setTexture(std::string filePath);

	void setTamanho(Coordenada<float> t);

	void setPosicao(Coordenada<float> p);

	const Coordenada<float> getTamanho() const;

	const Coordenada<float> getPosicao() const;

	const int getId() const;

};



