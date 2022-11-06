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
	Elemento<Entidade>* pElEntidade = list.getPrimeiro();
	for (int i = 0; i < size; i++)
	{
		if (!pElEntidade->getData()->alive)
			std::cout << i << " Esta morto" << std::endl;
		if (pElEntidade->getData()->alive)
			pElEntidade->getData()->executar(deltaTime);
		pElEntidade = pElEntidade->getProximo();
	}
}
void EntitiesList::printEntities(GerenciadorGrafico* pGerGraf)
{
	Elemento<Entidade>* pE = list.getPrimeiro();
	int size = list.getSize();
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (!pE->getData()->alive)
			std::cout << i << " Esta morto" << std::endl;
		if (pE->getData()->alive)
			pE->getData()->imprimir(pGerGraf); // cada entidade se imprime
		pE = pE->getProximo();
	}
	std::cout << i << std::endl;

}

void EntitiesList::addEntity(Entidade* pE)
{
	list.addElemento(pE);
}