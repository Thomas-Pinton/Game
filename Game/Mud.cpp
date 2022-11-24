#include "Mud.hpp"

namespace Obstacles 
{
	Mud::Mud() :
		Obstacle()
	{
		id = classes(mud);
		slowdown = 0.2f;
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
		std::ofstream MudFile("../data/Mud.txt", std::ios_base::app);
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