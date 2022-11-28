#pragma once

#include "Being.hpp"
#include "Coordinate.hpp"
#include "Constants.hpp"
#include <sstream>

class Level;

class Entity : public Being
{
protected:
	Coordinate<float> position;
	Coordinate<float> size;
	sf::Texture* texture;
	Level* pLevel;

public:
	bool alive;

	Coordinate<float> acceleration;

	Coordinate<float> speed;

	sf::RectangleShape rectangle;
	
	Entity();

	~Entity();

	void setTexture(std::string filePath, Coordinate<int> start = {0, 0}, Coordinate<int> size = { 0, 0 });

	void setSize(Coordinate<float> t);

	void setPosition(Coordinate<float> p);

	virtual void setAlive(const bool status);

	void updatePosition();

	void updatePosition(Coordinate<float> coord);

	const Coordinate<float> getSize() const;

	const Coordinate<float> getPosition() const;

	const bool getAlive() const;

	virtual void print();

	virtual void execute();

	virtual void save();

	void recoverEntity(std::string data);

	void setLevel(Level* pL);
};