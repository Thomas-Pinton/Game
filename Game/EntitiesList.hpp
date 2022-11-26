#pragma once
#include "List.hpp"
#include "Entity.hpp"
#include "Coordinate.hpp"

class EntitiesList 
{
private:
	Lista<Entity> list;
public:
	EntitiesList();
	~EntitiesList();
	void executeEntities();
	void printEntities();
	void addEntity(Entity* pE);
	void saveEntities();
};