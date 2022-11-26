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
    int playersAmount;
    std::vector<Button*> buttons;
    sf::Event event;
public:
    Menu();
    void execute();
    void print();
};

