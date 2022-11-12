#pragma once

#include "Being.hpp"
#include "Coordinate.hpp"

class Entity : public Being
{
private:
	
public:
	bool alive;
	Coordinate<float> acceleration;
	Coordinate<float> speed;
	Entity();
	void updatePosition();
	void updatePosition(Coordinate<float> coord);
	virtual void execute();
};