#include "Mud.hpp"

namespace Obstacles 
{
	Mud::Mud() :
		Obstacle()
	{
		id = classes(mud);
		slowdown = 0.2f;
	}

	Mud::Mud(std::string data) :
		Obstacle()
	{
		id = classes(mud);

		std::istringstream ss(data);

		std::string word;
		std::string entityString;
		for (int i = 0; i < 9; i++)
		{
			ss >> word;
			entityString += word + " ";
		}
		recoverEntity(entityString);

		ss >> counterForce;
		ss >> slowdown;
	}

	void Mud::execute()
	{
	}

	void Mud::affectPlayer(Player* pP)
	{
		if (pP->mudCooldown < 0.05f)
		{
			pP->movingSpeed *= slowdown;
		}
		pP->mudCooldown = 0.2f;
	}
	
	void Mud::save()
	{
		std::ofstream MudFile("../data/Level2/Mud.txt", std::ios_base::app);
		MudFile << alive << " "
			<< position.x << " " << position.y << " "
			<< size.x << " " << size.y << " "
			<< speed.x << " " << speed.y << " "
			<< acceleration.x << " " << acceleration.y << " "
			<< counterForce << " "
			<< slowdown << " "
			<< std::endl;
		MudFile.close();
	}
}