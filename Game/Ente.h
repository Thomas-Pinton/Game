#pragma once
#include "SFML/Graphics.hpp"

// Tudo aquilo que tem representa��o gr�fica
// Ex.: Personagem, blocos, menu, backgrounds, etc

class Ente
{
private:
	int id;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Ente();
};

