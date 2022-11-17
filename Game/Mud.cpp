#include "Mud.hpp"

namespace Obstacles 
{
	Mud::Mud()
	{
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

		//itchio 2d plataform sprite

		std::cout << "Moving speed " << pP->movingSpeed << std::endl;
	}
}