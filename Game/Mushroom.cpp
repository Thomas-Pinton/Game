#include "Mushroom.hpp"
#include "GraphicManager.hpp"
#include "Level.hpp"
#include <sstream>

namespace Enemies
{
	Mushroom::Mushroom(float chDirTime) :
		Enemy()
	{
		id = classes(mushroom);
		changeDirectionTime = chDirTime;
		timeElapsed = 0;
	}

	Mushroom::Mushroom(std::string data) :
		Enemy()
	{
		id = classes(mushroom);
		std::cout << "Recovering Mushroom " << std::endl;

		std::istringstream ss(data);
		
		std::string word;
		std::string entityString;
		for (int i = 0; i < 9; i++)
		{
			ss >> word;
			entityString += word + " ";
		}
		recoverEntity(entityString);

		ss >> hp;
		ss >> damage;
		ss >> changeDirectionTime;
		ss >> timeElapsed;

		std::cout << "Hp " << hp << "damage " << damage << "time elapsed " << timeElapsed << std::endl;

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
		std::cout << "Saving mushroom " << pLevel->getId() << std::endl;
		std::ofstream mushroomFile("../data/Level" + std::to_string(pLevel->getId()) + "/Mushroom.txt", std::ios_base::app);
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
