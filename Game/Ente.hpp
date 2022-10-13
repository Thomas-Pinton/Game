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
	int id;
	Coordenada<float> posicao;
	Coordenada<float> tamanho;
	sf::Texture texture;
public:
	sf::Sprite sprite;
	Ente()
		: texture(),
		sprite()
	{
		id = -1;
		// id n�o imprementado ainda
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
	
};



