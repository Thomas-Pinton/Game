#include "Mushroom.hpp"
#include "GraphicManager.hpp"

namespace Enemies
{
	Mushroom::Mushroom(float chDirTime)
	{
		id = classes(mushroom);
		changeDirectionTime = chDirTime;
		timeElapsed = 0;
	}

	void Mushroom::execute()
	{
		checkIce();
		timeElapsed += pGraMan->getDeltaTime();
		if (timeElapsed > changeDirectionTime)
		{
			speed.x *= -1;
			timeElapsed -= changeDirectionTime;
		}
		updatePosition();
	}

	void Mushroom::save()
	{
		std::ofstream mushroomFile("../data/Mushroom.txt", std::ios_base::app);
		mushroomFile << alive << " "
			<< position.x << " " << position.y << " "
			<< size.x << " " << size.y << " "
			<< speed.x << " " << speed.y << " "
			<< acceleration.x << " " << acceleration.y << " "
			<< hp << " "
			<< damage << " "
			<< changeDirectionTime << " "
			<< timeElapsed << " "
			<< std::endl;
		mushroomFile.close();
	}
}
