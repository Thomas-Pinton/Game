#pragma once
#include "List.hpp"
#include "Entity.hpp"
#include "Coordinate.hpp"

class EntitiesList 
{
private:
	Lista<Entity> list;
	int levelId;
public:
	EntitiesList();
	~EntitiesList();
	void setLevelId(int id);
	void executeEntities();
	void printEntities();
	void addEntity(Entity* pE);
	void saveEntities();
};