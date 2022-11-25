#include "FireBlock.hpp"

namespace Obstacles
{
    FireBlock::FireBlock()
    {
        id = classes(fireBlock);
        damage = 1;
    }
    void FireBlock::affectPlayer(Player* pP)
    {
        std::cout << "Jogador Morreu" << std::endl;
        pP->decreaseHp(damage);
    }

    void FireBlock::save()
    {
        std::ofstream FireBlockFile("../data/FireBlock.txt", std::ios_base::app);
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
