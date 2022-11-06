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
	void executeEntities(float deltaTime);
	void printEntities(GraphicManager* pGerGraf);
	void addEntity(Entity* pE);
};