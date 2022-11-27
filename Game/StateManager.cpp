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
		players()
	{
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
			push(new Level1(playersAmount));
			break;
		case level2:
			push(new Level2(playersAmount));
			break;
		case leaderboard:
			push(new Leaderboard());
			break;
		case endLevelScreen:
			int* points = new int[playersAmount];
			for (int i = 0; i < playersAmount; i++)
			{
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
		if (stateStack.top())
		{
			delete (stateStack.top());
			stateStack.pop();
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
		players.push_back(pP);
	}

	void StateManager::setPlayersAmount(int amount)
	{
		playersAmount = amount;
	}
}
