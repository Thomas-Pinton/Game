#pragma once

#include "Entity.hpp"

class Button :
    public Entity
{
private:
    bool isSelected;
    //sf::Text text;
public:
    sf::Text text;

    Button();
    Button(std::string fontFilePath, std::string string, int characterSize);
    ~Button();

    
    void print();

    void setFont(std::string filePath);
    void setPosition(Coordinate<float> p);
    void setString(std::string string);

    std::string getString();
};

