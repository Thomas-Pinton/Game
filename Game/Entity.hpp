#pragma once

#include "Being.hpp"
#include "Coordinate.hpp"
#include "Constants.hpp"

class Entity : public Being
{
protected:
	Coordinate<float> position;
	Coordinate<float> size;
	sf::Texture texture;

public:
	bool alive;

	Coordinate<float> acceleration;

	Coordinate<float> speed;

	sf::RectangleShape rectangle; // temporario
	
	sf::Sprite sprite;

	Entity();

	void setTexture(std::string filePath);

	void setSize(Coordinate<float> t);

	void setPosition(Coordinate<float> p);

	virtual void setAlive(bool status);

	void updatePosition();

	void updatePosition(Coordinate<float> coord);

	const Coordinate<float> getSize() const;

	const Coordinate<float> getPosition() const;

	const bool getAlive() const;

	virtual void print();

	virtual void execute();
};