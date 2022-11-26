#pragma once

// Singleton design pattern
// State design pattern

#include <stack>

class Being;

enum States {
	level1,
	level2,
	menu,
	leaderboard,
	endLevelScreen
};

namespace Manager 
{
	class StateManager
	{
	private:
		StateManager();
		static StateManager* instance;
		std::stack<Being*> stateStack;
		int playersAmount;
	public:
		static StateManager* getInstance();
		void push(Being* state);
		void push(States state);
		int getStackSize();
		void setPlayersAmount(int amount);
		// when the state is a level
		void pop();
		void popUntil(int amount);
		void execute();
	};
}
