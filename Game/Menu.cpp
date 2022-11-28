#include "Menu.hpp"
#include "GraphicManager.hpp"

#define SELECTED_COLOR sf::Color::Green
#define UNSELECTED_COLOR sf::Color::Blue

#define SELECTED_TEXT_COLOR sf::Color::Black
#define UNSELECTED_TEXT_COLOR sf::Color::White


Menu::Menu()
	: Being()
{
	Being::pGraMan = GraphicManager::getInstance();

	option = 0;
	optionsAmount = 5;
	playersAmount = 1;
	loadFromSave = false;

	Button* pB = NULL;

	for (int i = 0; i < optionsAmount; i++)
	{
		pB = new Button("../Assets/GUI_Essential_Free_v1.1/Font/TTF/m5x7.ttf", "Button " + std::to_string(i), 35);
		pB->setPosition({ 1200 / 2, 100 + 100.0f * i});
		//pB->text.setPosition({ 500.0f, 100 + 100.0f * i });
		pB->setSize({ 400, 50 });
		pB->rectangle.setFillColor(UNSELECTED_COLOR);
		if (i == option)
		{
			pB->rectangle.setFillColor(SELECTED_COLOR);
			pB->text.setFillColor(SELECTED_TEXT_COLOR);
		}
			
		buttons.push_back(pB);
		//pB->setString("Button " + i);
	}
	
	buttons[0]->setString("Play level 1");
	buttons[1]->setString("Play level 2");
	buttons[2]->setString("Number of Players: 1");
	buttons[3]->setString("Load from save: false");
	buttons[4]->setString("Leaderboard");

}

Menu::~Menu()
{
	int buttonsSize = buttons.size();
	for (int i = 0; i < buttonsSize; i++)
		delete buttons[i];
}

void Menu::execute()
{
	print();

	while (pGraMan->getWindow()->config.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if ((event.key.code == sf::Keyboard::S ||
				event.key.code == sf::Keyboard::Down) &&
				option < optionsAmount - 1)
			{
				option++;

				buttons[option]->rectangle.setFillColor(SELECTED_COLOR);
				buttons[option - 1]->rectangle.setFillColor(UNSELECTED_COLOR);

				buttons[option]->text.setFillColor(SELECTED_TEXT_COLOR);
				buttons[option - 1]->text.setFillColor(UNSELECTED_TEXT_COLOR);

			}
			else if ((event.key.code == sf::Keyboard::W ||
				event.key.code == sf::Keyboard::Up) &&
				option > 0)
			{
				option--;
				buttons[option]->rectangle.setFillColor(SELECTED_COLOR);
				buttons[option + 1]->rectangle.setFillColor(UNSELECTED_COLOR);

				buttons[option]->text.setFillColor(SELECTED_TEXT_COLOR);
				buttons[option + 1]->text.setFillColor(UNSELECTED_TEXT_COLOR);

			}
			else if (event.key.code == sf::Keyboard::Enter &&
				option == 2) // caso queira trocar o numero de jogadores
			{
				std::cout << "Entrando aqui " << std::endl;
				std::string s = buttons[option]->getString();
				if (buttons[option]->getString().back() == '1')
				{
					s.pop_back();
					s.push_back('2');
					playersAmount = 2;
				}
				else
				{
					s.pop_back();
					s.push_back('1');
					playersAmount = 1;
				}
				buttons[option]->setString(s);
			}
			else if (event.key.code == sf::Keyboard::Enter &&
				option == 3) // caso queira trocar a opcao de salvamento
			{
				std::cout << "Entrando aqui " << std::endl;
				std::string s = buttons[option]->getString();
				if (loadFromSave == false)
				{
					for (int j = 0; j < 5; j++)
						s.pop_back();
					s += "true";
				}
				else
				{
					for (int j = 0; j < 4; j++)
						s.pop_back();
					s += "false";
				}
				loadFromSave = !loadFromSave;
				buttons[option]->setString(s);
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				Manager::StateManager* pSM = StateManager::getInstance();

				pSM->setPlayersAmount(playersAmount);

				pSM->setLoadFromSave(loadFromSave);

				Manager::StateManager::getInstance()->push((States)option);
			}

		}
	}
	

}

void Menu::print()
{
	pGraMan->clear();
	for (int i = 0; i < optionsAmount; i++)
	{
		//std::cout << "i " << i << std::endl;
		//std::cout << "Id" << buttons[i]->getId() << std::endl;
		buttons[i]->print();
	}
	pGraMan->display();
}