#include "Entity.hpp"
#include "GraphicManager.hpp"

using namespace Manager;

Being::Being()
{
	id = -1;
}

Being::~Being()
{
}

const int Being::getId() const {
	return id;
}