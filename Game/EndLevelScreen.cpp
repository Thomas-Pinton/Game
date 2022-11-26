#include "EndLevelScreen.hpp"
#include "GraphicManager.hpp"

EndLevelScreen::EndLevelScreen(int pAmount, int* p) :
	playerSelected(0),
	playersAmount(pAmount),
	pontuation (p)
{
	font = pGraMan->loadFont("../Assets/GUI_Essential_Free_v1.1/Font/TTF/m5x7.ttf");

	screenMessage.setString("Input name from player 1");
	screenMessage.setPosition(GraphicManager::getInstance()->getWindow()->getWIDTH() / 2 - 100, GraphicManager::getInstance()->getWindow()->getHEIGHT() / 2 - 200);
	screenMessage.setFont(*font);

	sf::Text* text = NULL;
	for (int i = 0; i < playersAmount; i++)
	{
		text = new sf::Text;
		text->setPosition(GraphicManager::getInstance()->getWindow()->getWIDTH() / 2 - 100, GraphicManager::getInstance()->getWindow()->getHEIGHT() / 2);
		text->setFont(*font);
		playersInput.push_back(text);
	}
	
}

EndLevelScreen::~EndLevelScreen()
{
	for (std::vector<sf::Text*>::iterator it = playersInput.begin(); it != playersInput.end(); it++)
		delete (*it);
}

void EndLevelScreen::execute()
{
	while (pGraMan->getWindow()->config.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) // se eh uma letra normal
			{
				name += event.key.code + 'a';
				playersInput[playerSelected]->setString(name);
			}
			else if (event.key.code == sf::Keyboard::BackSpace && name.size() > 0)
			{
				name.pop_back();
				playersInput[playerSelected]->setString(name);
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				if (name.size() == 0)
					return;
				// nao gravar se o nome nao for digitado

				writeData();

				if (playerSelected+1 == playersAmount)
				{
					std::cout << "Going back " << std::endl;
					delete pontuation;
					std::cout << "2 " << std::endl;
					//while (StateManager::getInstance()->getStackSize() > 1)
					std::cout << "Size " << StateManager::getInstance()->getStackSize() << std::endl;
					Manager::StateManager::getInstance()->popUntil(1);
					// sair da tela, voltar para o menu principal
					return;
				}
				playerSelected++;

				name.clear();

				updateString();
			}
		}
	}
	print();
}

void EndLevelScreen::print() 
{
	pGraMan->clear();
	pGraMan->printText(&screenMessage);
	pGraMan->printText(playersInput[playerSelected]);
	pGraMan->display();
}

void EndLevelScreen::writeData()
{
	std::ofstream leaderboardFile("../data/leaderboard.txt", std::ios_base::app);

	leaderboardFile << name << std::endl;
	leaderboardFile << pontuation[playerSelected] << std::endl;

	leaderboardFile.close();
}

void EndLevelScreen::updateString()
{
	std::string str = screenMessage.getString();
	str.pop_back();
	str.push_back((char) '0' + playerSelected + 1);
	screenMessage.setString(str);
}
