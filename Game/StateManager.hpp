#pragma once

// Singleton design pattern
// State design pattern

#include <stack>
#include <vector>

class Being;
class Player;

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
		std::vector<Player*> players;
		int playersAmount;
	public:
		static StateManager* getInstance();
		void push(Being* state);
		void push(States state);
		int getStackSize();
		// when the state is a level
		void pop();
		void popUntil(int amount);
		void execute();
		void addPlayer(Player* pP = NULL);
		void setPlayersAmount(int amount);
	};
}
