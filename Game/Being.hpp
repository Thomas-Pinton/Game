#pragma once

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Coordinate.hpp"

namespace Manager {
	class GraphicManager;
}


// Tudo aquilo que tem representa��o gr�fica
// Ex.: Character, blocos, menu, backgrounds, etc

using namespace Manager;

class Being
{
protected:
	static int id_count;
	int id;
	Coordinate<float> position;
	Coordinate<float> size;
	sf::Texture texture;
public:
	static Manager::GraphicManager* pGraMan;
	sf::RectangleShape rectangle; // tempor�rio
	sf::Sprite sprite;

	Being();

	void setTexture(std::string filePath);

	void setSize(Coordinate<float> t);

	void setPosition(Coordinate<float> p);

	virtual void print();

	const Coordinate<float> getSize() const;

	const Coordinate<float> getPosition() const;

	const int getId() const;



};



