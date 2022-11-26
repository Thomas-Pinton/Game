#include "StateManager.hpp"
#include "Menu.hpp"
#include "EndLevelScreen.hpp"
#include "Level1.hpp"
#include "Level2.hpp"

namespace Manager
{
	StateManager::StateManager() :
		stateStack(),
		playersAmount(1)
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
			push(new Level1(GraphicManager::getInstance()->getWindow(), playersAmount));
			break;
		case level2:
			push(new Level2(GraphicManager::getInstance()->getWindow(), playersAmount));
			break;
		case endLevelScreen:
			int* points = new int[2];
			points[0] = 10; points[1] = 20;
			push(new EndLevelScreen(playersAmount, points));
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

	void StateManager::setPlayersAmount(int amount)
	{
		playersAmount = amount;
	}
}
