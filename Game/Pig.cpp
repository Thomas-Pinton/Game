#include "Pig.hpp"
#include "GraphicManager.hpp"

namespace Enemies
{
	Pig::Pig(float chanDirTime) :
		Enemy()
	{
		id = classes(pig);
		changeDirectionTime = chanDirTime;
		changeState(CALM);
		hp = 3;
		timeElapsed = 0;
	}

	Pig::Pig(std::string data)
	{
		id = classes(pig);

		std::istringstream ss(data);

		std::string word;
		std::string entityString;
		for (int i = 0; i < 9; i++)
		{
			ss >> word;
			entityString += word + " ";
		}
		recoverEntity(entityString);

		ss >> hp;
		ss >> damage;
		ss >> state;
		ss >> changeDirectionTime;
		ss >> timeElapsed;
	}

	Pig::~Pig()
	{

	}

	void Pig::changeState(int s)
	{
		if (s == state)
			return;
		if (s == ANGRY)
		{
			std::cout << "Angry " << std::endl;
			speed.x *= 2.0f;
			changeDirectionTime /= 2.0f;
			state = ANGRY;
			rectangle.setFillColor(sf::Color::Red);
		}
		else if (s == CALM)
		{
			speed = { 200.0f, 0 };
			state = CALM;
		}
			
	}

	void Pig::setHp(int newHp)
	{
		hp = newHp;
		if (hp <= 0)
			alive = false;
		if (hp == 1)
			changeState(ANGRY);
		else if (hp == 2)
			changeState(CALM);
	}

	void Pig::decreaseHp(int qtd)
	{
		std::cout << "Decreasing pig hp" << hp << std::endl;
		hp -= qtd;
		if (hp <= 0)
			alive = false;
		if (hp == 1)
			changeState(ANGRY);
	}

	void Pig::execute()
	{
		timeElapsed += pGraMan->getDeltaTime();
		if (timeElapsed > changeDirectionTime)
		{
			speed.x *= -1;
			timeElapsed -= changeDirectionTime;
		} 
		updatePosition();
	}

	void Pig::save()
	{
		std::ofstream pigFile("../data/Level2/Pig.txt", std::ios_base::app);
		pigFile << alive << " "
			<< position.x << " " << position.y << " "
			<< size.x << " " << size.y << " "
			<< speed.x << " " << speed.y << " "
			<< acceleration.x << " " << acceleration.y << " "
			<< hp << " "
			<< damage << " "
			<< state << " "
			<< changeDirectionTime << " "
			<< timeElapsed << " "
			<< std::endl;
		pigFile.close();
	}
}