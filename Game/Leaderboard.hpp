#include "Being.hpp"
#include <list>

class Leaderboard : public Being
{
private:
	std::list<sf::Text*> pontuations;
	sf::Event event;
public:
	Leaderboard();
	~Leaderboard();
	void loadData();
	void execute();
	void print();
};