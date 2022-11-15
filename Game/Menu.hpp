#pragma once

#include "Button.hpp"

#include <iostream>
#include <vector>

class Menu :
    public Being
{
private:
    int option;
    int optionsAmount;
    std::vector<Button*> buttons;
public:
    Menu();
    int execute();
    void print();
};

