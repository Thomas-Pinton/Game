#include "FireBlock.hpp"
#include "Level.hpp"

namespace Obstacles
{
    FireBlock::FireBlock() :
        Obstacle()
    {
        id = classes(fireBlock);
        damage = 1;
    }

    FireBlock::FireBlock(std::string data) :
        Obstacle()
    {
        id = classes(fireBlock);

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
        ss >> damage;
    }

    void FireBlock::affectPlayer(Player* pP)
    {
        std::cout << "Jogador Morreu" << std::endl;
        pP->decreaseHp(damage);
    }

    void FireBlock::save()
    {
        std::ofstream FireBlockFile;
        if (pLevel->getId() == 1)
            FireBlockFile.open("../data/Level1/FireBlock.txt", std::ios_base::app);
        else
            FireBlockFile.open("../data/Level2/FireBlock.txt", std::ios_base::app);
        FireBlockFile << alive << " "
            << position.x << " " << position.y << " "
            << size.x << " " << size.y << " "
            << speed.x << " " << speed.y << " "
            << acceleration.x << " " << acceleration.y << " "
            << counterForce << " "
            << damage << " "
            << std::endl;
        FireBlockFile.close();
    }
}
