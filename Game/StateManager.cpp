#include "StateManager.hpp"
#include "Menu.hpp"
#include "EndLevelScreen.hpp"
#include "Level1.hpp"
#include "Level2.hpp"
#include "Leaderboard.hpp"
#include "Player.hpp"

namespace Manager
{
	StateManager::StateManager() :
		stateStack(),
		players(2, NULL),
		loadFromSave(false)
	{
	}

	StateManager::~StateManager()
	{
		int playersSize = players.size();
		for (int i = 0; i < playersSize; i++)
			delete players[i];
	}
	StateManager* StateManager::getInstance()
	{
		if (instance == NULL)
			instance = new StateManager();
		return instance;
	}

	void StateManager::push(Being* state)
	{
		stateStack.push(state);
	}
	
	void StateManager::push(States state)
	{
		switch (state)
		{
		case menu:
			push(new Menu);
			break;
		case level1:
			push(new Level1(playersAmount, loadFromSave));
			break;
		case level2:
			push(new Level2(playersAmount, loadFromSave));
			break;
		case leaderboard:
			push(new Leaderboard());
			break;
		case endLevelScreen:
			std::cout << "Trying to create end level screen " << std::endl;
			std::cout << "Players amount " << playersAmount << std::endl;
			int* points = new int[playersAmount];
			for (int i = 0; i < playersAmount; i++)
			{
				if (players[i] == NULL)
				{
					std::cout << "Null " << std::endl; 
					break;
				}
				points[i] = players[i]->getPoints();
				std::cout << "Points [i] " << points[i] << std::endl;
				std::cout << "players[i]->getPoints() " << players[i]->getPoints() << std::endl;
			}

			push(new EndLevelScreen(points, playersAmount));
			break;
		}
	}

	void StateManager::pop()
	{
		std::cout << "Stack size " << stateStack.size() << std::endl;
		if (stateStack.top())
		{
			delete (stateStack.top());
			stateStack.pop();
			std::cout << stateStack.top()->getId() << std::endl;
			return;
		}
		std::cout << "Not possible to pop, stack is empty" << std::endl;
	}
	void StateManager::popUntil(int amount)
	{
		while (getStackSize() > amount)
		{
			pop();
		}
	}

	int StateManager::getStackSize()
	{
		return stateStack.size();
	}

	void StateManager::execute()
	{
		stateStack.top()->execute();
	}

	void StateManager::addPlayer(Player* pP)
	{
		if (pP == NULL)
			return;
		int i = 0;
		while (players[i] != NULL)
			i++;
		players[i] = pP;

	}

	void StateManager::setPlayersAmount(int amount)
	{
		playersAmount = amount;
	}

	void StateManager::setLoadFromSave(bool s)
	{
		loadFromSave = s;
	}

	Player* StateManager::getPlayer(int position)
	{
		return players[position];
	}

	void StateManager::deletePlayers()
	{
		int playersSize = players.size();
		for (int i = 0; i < playersSize; i++)
		{
			delete players[i];
			players[i] = NULL;
		}
	}
}
