#pragma once

#include "Being.hpp"
#include <map>

class EndLevelScreen :
    public Being
{
private:
    sf::Event event;

    std::string name;
    sf::Text screenMessage;
    sf::Text errorMessage;
    std::vector<sf::Text*> playersInput;
    sf::Font* font;


    int playerSelected;
    int playersAmount;
    int* pontuation;

public:
    EndLevelScreen(int* p, int pAmount);
    ~EndLevelScreen();

    void execute();
    void print();

    void updateString();
    void writeData();
};

