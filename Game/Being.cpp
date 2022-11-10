#include "Entity.hpp"
#include "GraphicManager.hpp"

Being::Being()
	: //sprite(),
	rectangle() //tempor�rio
{
	id = id_count;
	id_count++;
	// id n�o imprementado ainda
}

void Being::setTexture(std::string filePath)
{
	if (!texture.loadFromFile(filePath))
	{
		std::cout << "Erro ao carregar imagem" << std::endl;
		return;
	}
	sprite.setTexture(texture);
}

void Being::setSize(Coordinate<float> t) {
	size = t;
	rectangle.setSize(sf::Vector2f(t.x, t.y));
	rectangle.setOrigin(sf::Vector2f(t.x / 2, t.y / 2));
	// mudar para sprite
}

void Being::setPosition(Coordinate<float> p)
{
	position = p;
	rectangle.setPosition(sf::Vector2f(p.x, p.y));
	// mudar para sprite
}

void Being::print(GraphicManager* pGerenciadorGrafico)
{
	pGerenciadorGrafico->printBeing(this);
}

const Coordinate<float> Being::getSize() const {
	return size;
}

const Coordinate<float> Being::getPosition() const {
	return position;
}

const int Being::getId() const {
	return id;
}