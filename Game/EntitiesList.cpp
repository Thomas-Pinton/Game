#include "EntitiesList.hpp"

EntitiesList::EntitiesList()
	: list()
{
}
EntitiesList::~EntitiesList()
{
}
void EntitiesList::executeEntities(float deltaTime)
{
	int size = list.getSize();
	Element<Entity>* pElEntidade = list.getPrimeiro();
	for (int i = 0; i < size; i++)
	{
		if (!pElEntidade->getData()->alive)
			std::cout << i << " Esta morto" << std::endl;
		if (pElEntidade->getData()->alive)
			pElEntidade->getData()->execute(deltaTime);
		pElEntidade = pElEntidade->getProximo();
	}
}
void EntitiesList::printEntities()
{
	Element<Entity>* pE = list.getPrimeiro();
	int size = list.getSize();
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (!pE->getData()->alive)
			std::cout << i << " Esta morto" << std::endl;
		if (pE->getData()->alive)
			pE->getData()->print(); // cada entidade se print
		pE = pE->getProximo();
	}

}

void EntitiesList::addEntity(Entity* pE)
{
	list.addElemento(pE);
}