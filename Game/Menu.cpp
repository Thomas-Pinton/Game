#include "Menu.hpp"
#include "GraphicManager.hpp"

#define SELECTED_COLOR sf::Color::Green
#define UNSELECTED_COLOR sf::Color::Blue

#define SELECTED_TEXT_COLOR sf::Color::Black
#define UNSELECTED_TEXT_COLOR sf::Color::White


// Será que eu devo ou não chamar o construtor de Being?
Menu::Menu()
	: Being()
{
	Being::pGraMan = GraphicManager::getInstance();

	option = 0;
	optionsAmount = 4;

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
	buttons[3]->setString("Leaderboard");

}

int Menu::execute()
{
	sf::Event event;
	print();

	while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) || option == 2)
	{
		while (pGraMan->getWindow()->config.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if ((event.key.code == sf::Keyboard::S ||
					event.key.code == sf::Keyboard::Down ) &&
					option < optionsAmount -1)
				{
					option++;

					buttons[option]->rectangle.setFillColor(SELECTED_COLOR);
					buttons[option-1]->rectangle.setFillColor(UNSELECTED_COLOR);

					buttons[option]->text.setFillColor(SELECTED_TEXT_COLOR);
					buttons[option - 1]->text.setFillColor(UNSELECTED_TEXT_COLOR);

					print(); // if there was an update, print it
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

					print(); // if there was an update, print it
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
					}
					else
					{
						s.pop_back();
						s.push_back('1');
					}
					buttons[option]->setString(s);
					print();
				}

			} 
		}
	}

	if (option == 2 && buttons[option]->getString().back() == '1')
		return 4;
	else if (option == 2 && buttons[option]->getString().back() == '2')
		return 5;

	return option;

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