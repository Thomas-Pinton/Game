#include "Projectile.hpp"

Projectile::Projectile()
	: Entity()
{
	setPosition({ 2000.0f, 2000.f });
	damage = 1;
	alive = false;
}

Projectile::Projectile(std::string data)
	: Entity()
{
	id = classes(mushroom);
	std::cout << "Recovering Projectile " << std::endl;

	std::istringstream ss(data);

	std::string word;
	std::string entityString;
	for (int i = 0; i < 9; i++)
	{
		ss >> word;
		entityString += word + " ";
	}
	recoverEntity(entityString);

	ss >> damage;
}

const int Projectile::getDamage() const
{
	return damage;
}
void Projectile::setDamage(int d)
{
	damage = d;
}

void Projectile::reset(Coordinate<float> pos)
{
	alive = true;
	speed = { 0.0f, 0.0f };
	acceleration.y = GRAVITY;
	setPosition(pos);
}

void Projectile::save()
{
	std::ofstream projectileFile("../data/Projectile.txt", std::ios_base::app);
	projectileFile << alive << " "
		<< position.x << " " << position.y << " "
		<< size.x << " " << size.y << " "
		<< speed.x << " " << speed.y << " "
		<< acceleration.x << " " << acceleration.y << " "
		<< damage << " "
		<< std::endl;
	projectileFile.close();
}
