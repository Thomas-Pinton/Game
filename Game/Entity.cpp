#include "Entity.hpp"
#include "GraphicManager.hpp"
#include "Level.hpp"
#include <iostream>

using namespace Manager;

Entity::Entity()
	: Being(),
	alive(true)
{
	speed.x = 0; speed.y = 0;
	acceleration.x = 0; acceleration.y = GRAVITY;
	// All entities suffer from gravity effect
	pLevel = NULL;
	//temporario
	//rectangle.setOutlineColor(sf::Color::Red);
	//rectangle.setOutlineThickness(1);
}

Entity::~Entity()
{
}


void Entity::setTexture(std::string filePath, Coordinate<int> start, Coordinate<int> size)
{
	texture = pGraMan->loadTexture(filePath);
	rectangle.setTexture(texture);
	rectangle.setTextureRect(sf::IntRect(start.x, start.y, size.x, size.y));
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

void Entity::setAlive(const bool status)
{
	alive = status;
}

const Coordinate<float> Entity::getSize() const {
	return size;
}

const Coordinate<float> Entity::getPosition() const {
	return position;
}

const bool Entity::getAlive() const {
	return alive;
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

void Entity::save()
{
}
void Entity::recoverEntity(std::string data)
{
	std::istringstream ss(data);

	std::string word;

	Coordinate<float> c;

	ss >> alive;
	ss >> c.x; ss >> c.y;
	setPosition(c);
	ss >> c.x; ss >> c.y;
	setSize(c);
	ss >> speed.x; ss >> speed.y;
	ss >> acceleration.x; ss >> acceleration.y;
}

void Entity::setLevel(Level* pL)
{
	pLevel = pL;
}