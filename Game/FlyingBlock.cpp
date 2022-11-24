#include "FlyingBlock.hpp"

namespace Obstacles
{
	FlyingBlock::FlyingBlock() :
		Obstacle()
	{
		id = classes(flyingBlock);
	}
	void FlyingBlock::affectPlayer()
	{
	}

	void FlyingBlock::save()
	{
		std::ofstream FlyingBlock("../data/FlyingBlock.txt", std::ios_base::app);
		FlyingBlock << alive << " "
			<< position.x << " " << position.y << " "
			<< size.x << " " << size.y << " "
			<< speed.x << " " << speed.y << " "
			<< acceleration.x << " " << acceleration.y << " "
			<< counterForce << " "
			<< std::endl;
		FlyingBlock.close();
	}
}