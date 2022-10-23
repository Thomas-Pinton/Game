#pragma once

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Coordenada.hpp"

// Tudo aquilo que tem representação gráfica
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
	sf::RectangleShape rectangle; // temporário
	sf::Sprite sprite;

	Ente()
		: //sprite(),
		rectangle() //temporário
	{
		id = id_count;
		id_count++;
		// id não imprementado ainda
	}

	void setTexture(std::string filePath)
	{
		if (!texture.loadFromFile(filePath))
		{
			std::cout << "Erro ao carregar imagem" << std::endl;
			return;
		}
		sprite.setTexture(texture);
	}

	void setTamanho(Coordenada<float> t) {
		tamanho = t;
		rectangle.setSize(sf::Vector2f(t.x, t.y));
		rectangle.setOrigin(sf::Vector2f(t.x / 2, t.y / 2));
		// mudar para sprite
	}

	void setPosicao(Coordenada<float> p)
	{
		posicao = p;
		rectangle.setPosition(sf::Vector2f(p.x, p.y));
		// mudar para sprite
	}

	const Coordenada<float> getTamanho() const {
		return tamanho;
	}

	const Coordenada<float> getPosicao() const {
		return posicao;
	}
	
	const int getId() const {
		return id;
	}
};



