#include "Button.hpp"
#include "GraphicManager.hpp"

Button::Button()
{
}

Button::Button(std::string fontFilePath = "../Assets/GUI_Essential_Free_v1.1/Font/TTF/Toriko.ttf", std::string string = "Empty Button", int characterSize = 24) :
	Being(),
	text()
{
	isSelected = false;
	setFont(fontFilePath);
	text.setString(string);
	text.setCharacterSize(characterSize);
}

Button::~Button()
{
	delete text.getFont();
}

void Button::setFont(std::string filePath)
{
	sf::Font* pF = new sf::Font;

	if (!pF->loadFromFile(filePath))
	{
		std::cout << "Error loading font" << std::endl;
		delete pF;
		return;
	}

	if (text.getFont())
		delete text.getFont();
	text.setFont(*pF);
}

void Button::setPosition(Coordinate<float> p)
{
	position = p;
	rectangle.setPosition(sf::Vector2f(p.x, p.y));
	text.setPosition(sf::Vector2f( p.x - text.getCharacterSize() * ((float)text.getString().getSize() / 4.0f), p.y - ((float)text.getCharacterSize() / 2.0f )));
	// mudar para sprite
}

void Button::print()
{
	pGraMan->printBeing(this);
	pGraMan->printText(&text);
}

void Button::setString(std::string string) 
{
	text.setString(string);
}