#include "Ice.hpp"
#include "GraphicManager.hpp"

namespace Obstacles
{
	Ice::Ice() :
		Obstacle()
	{
		enemyJumpHeight = -sqrtf(2 * GRAVITY * 130);
	}
    Ice::Ice(std::string data) :
        Obstacle()
    {
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
        ss >> enemyJumpHeight;

    }
	void Ice::affectEnemy(Enemy* pE)
	{
		pE->jump += pGraMan->getDeltaTime();
        pE->setJumpHeight(enemyJumpHeight);
    }

    void Ice::save()
    {
        std::ofstream iceFile("../data/Level1/Ice.txt", std::ios_base::app);
        iceFile << alive << " "
            << position.x << " " << position.y << " "
            << size.x << " " << size.y << " "
            << speed.x << " " << speed.y << " "
            << acceleration.x << " " << acceleration.y << " "
            << counterForce << " "
            << enemyJumpHeight << " "
            << std::endl;
        iceFile.close();
    }
}
