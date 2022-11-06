#pragma once
#include "List.hpp"
#include "Entity.hpp"
#include "Coordinate.hpp"

class EntitiesList 
{
private:
	Lista<Entidade> list;
public:
	EntitiesList();
	~EntitiesList();
	void executeEntities(float deltaTime);
	void printEntities(GerenciadorGrafico* pGerGraf);
	void addEntity(Entidade* pE);
};