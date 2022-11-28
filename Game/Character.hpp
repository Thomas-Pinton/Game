#pragma once

#include "Entity.hpp"
#include "Constants.hpp"

namespace Characters
{
	class Character : public Entity
	{
	protected:
		int hp;
		float jumpHeight;
	public:
		Character();
		const int getHp() const;
		virtual void setHp(const int newHp);
		virtual void decreaseHp(const int qtd);
		virtual void increaseHp(int qtd);
		void setJumpHeight(float jH);
		float getJumpHeight();
	};
}

using namespace Characters;