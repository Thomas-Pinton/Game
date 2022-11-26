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
	// limpando todos os arquivos
	remove("../data/Player.txt");
	remove("../data/Mushroom.txt");
	remove("../data/Pig.txt");
	remove("../data/Plant.txt");
	remove("../data/FlyingBlock.txt");
	remove("../data/FireBlock.txt");
	remove("../data/Mud.txt");
	remove("../data/Projectile.txt");

	int size = list.getSize();
	Lista<Entity>::Element<Entity>* pElEntidade = list.getPrimeiro();

	for (int i = 0; i < size; i++)
	{
		//if (pElEntidade->getData()->alive)
		pElEntidade->getData()->save();
		pElEntidade = pElEntidade->getProximo();
	}
}