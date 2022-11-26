#pragma once

#include "Being.hpp"

class EndLevelScreen :
    public Being
{
private:
    sf::Event event;
    std::string name;
    sf::Text screenMessage;
    std::vector<sf::Text*> playersInput;
    int playerSelected;
    int playersAmount;
    int* pontuation;
    sf::Font* font;
public:
    EndLevelScreen(int playersAmount, int* p);
    ~EndLevelScreen();

    void execute();
    void print();

    void updateString();
    void writeData();
};

