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
	endLevelScreen,
	leaderboard
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
		bool loadFromSave;
	public:
		~StateManager();
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
		void setLoadFromSave(bool s);
		Player* getPlayer(int position);
		void deletePlayers();
	};
}
