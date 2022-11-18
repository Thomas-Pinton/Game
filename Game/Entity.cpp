#include "Entity.hpp"
#include "GraphicManager.hpp"
#include <iostream>

using namespace Manager;

Entity::Entity()
	: Being(),
	alive(true)
{
	speed.x = 0; speed.y = 0;
	acceleration.x = 0; acceleration.y = GRAVITY;
}


void Entity::setTexture(std::string filePath)
{
	if (!texture.loadFromFile(filePath))
	{
		std::cout << "Erro ao carregar imagem" << std::endl;
		return;
	}
	sprite.setTexture(texture);
}

void Entity::setSize(Coordinate<float> t) {
	size = t;
	rectangle.setSize(sf::Vector2f(t.x, t.y));
	rectangle.setOrigin(sf::Vector2f(t.x / 2, t.y / 2));
	// mudar para sprite
}

void Entity::setPosition(Coordinate<float> p)
{
	position = p;
	rectangle.setPosition(sf::Vector2f(p.x, p.y));
	// mudar para sprite
}

const Coordinate<float> Entity::getSize() const {
	return size;
}

const Coordinate<float> Entity::getPosition() const {
	return position;
}

void Entity::updatePosition()
{
	float deltaTime = pGraMan->getDeltaTime();
	speed += acceleration * deltaTime;
	position += speed * deltaTime;
	rectangle.setPosition(sf::Vector2f(position.x, position.y));
	//sprite.setPosition(sf::Vector2f(posicao.x, posicao.y));
}

void Entity::updatePosition(Coordinate<float> coord)
{
	position += coord;
	rectangle.setPosition(sf::Vector2f(position.x, position.y));
	//sprite.setPosition(sf::Vector2f(posicao.x, posicao.y));
}

void Entity::print()
{
	pGraMan->printEntity(this);
}

void Entity::execute()
{
	updatePosition();
}