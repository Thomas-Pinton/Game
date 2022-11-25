#pragma once

#define ANGRY 1
#define CALM 0

#include "Enemy.hpp"

namespace Enemies
{
	class Pig :
		public Enemy
	{
	private:
		int state;
		float changeDirectionTime;
		float timeElapsed;
	public:
		Pig(float chDirTime = 4);
		void changeState(int s);
		void setHp(int newHp);
		void decreaseHp(int qtd);
		void execute();
		void save();
	};
}


