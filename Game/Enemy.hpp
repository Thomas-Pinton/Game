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
    virtual ~Enemy();
    const int getDamage() const;
    void setDamage(int d);
    void setHp(int newHp);
    void decreaseHp(int qtd);
    void checkIce();
};

