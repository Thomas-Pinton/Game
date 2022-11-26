#include "Ice.hpp"
#include "GraphicManager.hpp"

namespace Obstacles
{
	Ice::Ice() :
		Obstacle()
	{
		enemySpeedBoost = 1.5f;	
	}
	void Ice::affectEnemy(Enemy* pE)
	{
		pE->jump += pGraMan->getDeltaTime();
	}
}
