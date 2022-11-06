#pragma once
#include "lista.hpp"
#include "Entidade.hpp"
#include "Coordenada.hpp"

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