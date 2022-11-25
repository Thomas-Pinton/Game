#include "Entity.hpp"
#include "GraphicManager.hpp"

using namespace Manager;

Being::Being()
{
	id = -1;
	// id n�o imprementado ainda
}

const int Being::getId() const {
	return id;
}