#include "Leaderboard.hpp"
#include "GraphicManager.hpp"

Leaderboard::Leaderboard()
	: Being()
{
	loadData();
}

Leaderboard::~Leaderboard() 
{
	for (std::list<sf::Text*>::iterator it = pontuations.begin(); it != pontuations.end(); it++)
		delete (*it);
}

void Leaderboard::loadData()
{
	std::ifstream leaderboardData("../data/Leaderboard.txt");

	sf::Font* font = NULL;
	font = pGraMan->loadFont("../Assets/GUI_Essential_Free_v1.1/Font/TTF/m5x7.ttf");

	if (leaderboardData.is_open())
	{
		std::string name;
		std::string pontuation;
		sf::Text* text = NULL;

		text = new sf::Text;

		text->setString("Top 10 scores");
		text->setFont(*font);
		text->setPosition({ (float)pGraMan->getWindow()->getWIDTH() / 2 - 200, 50.0f });
		text->setFillColor(sf::Color::Red);
		pontuations.push_back(text);

		int amount = 0;

		while (getline(leaderboardData, name) && getline(leaderboardData, pontuation) && amount < 10)
		{
			text = new sf::Text;
			text->setString(name + ": " + pontuation);
			text->setFont(*font);
			text->setPosition({ (float)pGraMan->getWindow()->getWIDTH() / 2 - 200, 100.0f + (amount * 50.0f)});
			pontuations.push_back(text);
			amount++;
		}
	}

	leaderboardData.close();
}

void Leaderboard::execute()
{
	while (pGraMan->getWindow()->config.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				StateManager::getInstance()->pop();
				return;
			}
		}
	}
	print();
}

void Leaderboard::print()
{
	pGraMan->clear();
	for (std::list<sf::Text*>::iterator it = pontuations.begin(); it != pontuations.end(); it++)
		pGraMan->printText(*it);
	pGraMan->display();
}