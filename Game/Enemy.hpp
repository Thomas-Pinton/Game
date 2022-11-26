#pragma once

#include "Character.hpp"

class Enemy :
    public Character
{
protected:
    int damage;
public:
    float jump;
    Enemy();
    const int getDamage() const;
    void setDamage(int d);
    void checkIce();
};

