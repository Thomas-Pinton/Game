#include "Obstacle.hpp"
#include "Constants.hpp"

Obstacle::Obstacle()
{
	counterForce = -1000.0f;
}

void Obstacle::affectPlayer(Player* pP)
{
}

void Obstacle::execute()
{
	acceleration.y = GRAVITY - counterForce;
	// posso fazer isso tambem no gerenciador de colisoes
}