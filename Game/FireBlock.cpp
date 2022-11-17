#include "FireBlock.hpp"

namespace Obstacles
{
    FireBlock::FireBlock()
    {
        damage = 1;
    }
    void FireBlock::affectPlayer(Player* pP)
    {
        std::cout << "Jogador Morreu" << std::endl;
        pP->decreaseHp(damage);
    }
}
