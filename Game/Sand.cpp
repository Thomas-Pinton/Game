#include "Sand.hpp"

namespace Obstacles
{
    Sand::Sand()
    {
        jumpHeightDecrease = 0.2f;
    }
    void Sand::execute()
    {
    }
    void Sand::affectPlayer(Player* pP)
    {
        std::cout << "Affecting player with mud " << pP->sandCooldown << std::endl;
        if (pP->sandCooldown < 0.05f)
        {
            pP->jumpHeight *= jumpHeightDecrease;
            pP->setWalk(false);
        }
        pP->sandCooldown = 0.2f;
    }
    //void save();

}