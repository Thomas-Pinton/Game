#include "Projectile.hpp"

Projectile::Projectile()
	: Entity()
{
	setPosition({ 2000.0f, 2000.f });
	damage = 1;
	alive = false;
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
		<< std::endl;
	projectileFile.close();
}
