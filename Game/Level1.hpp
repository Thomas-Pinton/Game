#pragma once

#include "Level.hpp"

class Level1 :
    public Level
{
public:
    Level1(Window* pW, GraphicManager* pGM);
    ~Level1();
    void execute();
};