#pragma once

#include "Being.hpp"

class Button :
    public Being
{
private:
    bool isSelected;
    //sf::Text text;
public:
    Button();
    Button(std::string fontFilePath, std::string string, int characterSize);
    ~Button();
    sf::Text text;
    void print();
    void setFont(std::string filePath);
    void setPosition(Coordinate<float> p);
    void setString(std::string string);
};

