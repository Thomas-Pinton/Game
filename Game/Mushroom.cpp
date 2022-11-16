#include "Mushroom.hpp"
#include "GraphicManager.hpp"

Mushroom::Mushroom(float chDirTime = 5)
{
	changeDirectionTime = chDirTime;
	timeElapsed = 0;
}

void Mushroom::execute()
{

	timeElapsed += pGraMan->getDeltaTime();
	if (timeElapsed > changeDirectionTime)
	{
		speed.x *= -1;
		timeElapsed -= changeDirectionTime;
	}
	updatePosition();
}