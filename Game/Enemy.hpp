#pragma once

#include "Character.hpp"

class Enemy :
    public Character
{
private:
    int damage;
public:
    Enemy();
    const int getDamage() const;
    void setDamage(int d);
};

