#include "Entity.hpp"
#include <iostream>

Entity::Entity()
	: Being(),
	alive(true)
{
	speed.x = 0; speed.y = 0;
	acceleration.x = 0; acceleration.y = 0;
}

void Entity::updatePosition(float deltaTime)
{
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

void Entity::execute(float deltaTime)
{
	if (id > 19)
		std::cout << "Pos" << position << std::endl;
	updatePosition(deltaTime);
}