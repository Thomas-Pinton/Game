#include "Entity.hpp"
#include "GraphicManager.hpp"

using namespace Manager;

Being::Being()
{
	id = id_count;
	id_count++;
	// id n�o imprementado ainda
}

const int Being::getId() const {
	return id;
}