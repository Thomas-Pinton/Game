#include "EntitiesList.hpp"

EntitiesList::EntitiesList()
	: list()
{
}
EntitiesList::~EntitiesList()
{
}
void EntitiesList::executeEntities()
{
	//GraphicManager* pGM = GraphicManager::getInstance();
	//float deltaTime = pGM->getDeltaTime();
	// getting Graphic Manager info

	int size = list.getSize();
	Lista<Entity>::Element<Entity>* pElEntidade = list.getPrimeiro();

	for (int i = 0; i < size; i++)
	{
		if (pElEntidade->getData()->alive)
			pElEntidade->getData()->execute();
		pElEntidade = pElEntidade->getProximo();
	}
}
void EntitiesList::printEntities()
{
	Lista<Entity>::Element<Entity>* pE = list.getPrimeiro();
	int size = list.getSize();
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (pE->getData()->alive)
			pE->getData()->print(); // cada entidade se print
		pE = pE->getProximo();
	}

}

void EntitiesList::addEntity(Entity* pE)
{
	list.addElemento(pE);
}

void EntitiesList::saveEntities()
{
	int size = list.getSize();
	Lista<Entity>::Element<Entity>* pElEntidade = list.getPrimeiro();

	for (int i = 0; i < size; i++)
	{
		//if (pElEntidade->getData()->alive)
		pElEntidade->getData()->save();
		pElEntidade = pElEntidade->getProximo();
	}
}