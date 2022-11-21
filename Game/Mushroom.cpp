#include "Mushroom.hpp"
#include "GraphicManager.hpp"

namespace Enemies
{
	Mushroom::Mushroom(float chDirTime)
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
}
