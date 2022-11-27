#include "EntitiesList.hpp"

EntitiesList::EntitiesList()
	: list()
{
}
EntitiesList::~EntitiesList()
{
}

void EntitiesList::setLevelId(int id)
{
	levelId = id;
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
	if (levelId == 1)
	{
		remove("../data/Level1/Player.txt");
		remove("../data/Level1/Mushroom.txt");
		remove("../data/Level1/Plant.txt");
		remove("../data/Level1/FireBlock.txt");
		remove("../data/Level1/Ice.txt");
		remove("../data/Level1/Projectile.txt");
	}
	else
	{
		remove("../data/Level2/Player.txt");
		remove("../data/Level2/Mushroom.txt");
		remove("../data/Level2/Pig.txt");
		remove("../data/Level2/FireBlock.txt");
		remove("../data/Level2/Mud.txt");
	}	

	std::cout << "Terminei de remover " << std::endl;

	int size = list.getSize();
	Lista<Entity>::Element<Entity>* pElEntidade = list.getPrimeiro();

	std::cout << "list size " << size << std::endl;

	for (int i = 0; i < size; i++)
	{
		//if (pElEntidade->getData()->alive)
		std::cout << "Tentando salvar o primeiro " << std::endl;
		pElEntidade->getData()->save();
		std::cout << "Terminando de salvar o primeiro " << std::endl;
		pElEntidade = pElEntidade->getProximo();
	}
}