#include "Projectile.hpp"

Projectile::Projectile()
	: Entity()
{
	setPosition({ 2000.0f, 2000.f });
	damage = 1;
	alive = false;
}
