#pragma once

#include "Level.hpp"
#include "Mushroom.hpp"
#include "FlyingBlock.hpp"
#include "FireBlock.hpp"
#include "Mud.hpp"

class Level1 :
    public Level
{
public:
    Level1(Window* pW, GraphicManager* pGM);
    ~Level1();
    void execute();
};