#include "Plant.hpp"
#include "GraphicManager.hpp"

namespace Enemies
{
	Plant::Plant()
	{
		shootInterval = 0.0f;
		shootCooldown = 1.0f;
		pPlayer = NULL;
	}

	Plant::~Plant()
	{
		std::list<Projectile*>::iterator it;
		for (it = projectiles.begin(); it != projectiles.end(); it++)
			delete (*it);
	}

	void Plant::shoot()
	{
		std::cout << "Shooting " << std::endl;
		Projectile* pP;
		if (lastProjectileShooted == projectiles.end())
		{
			pP = *(projectiles.begin());
			lastProjectileShooted = projectiles.begin();
		}else
		{
			pP = *(lastProjectileShooted++);
			lastProjectileShooted = lastProjectileShooted++;
		}
		pP->alive = true;
		pP->speed = { 0.0f, 0.0f };
		pP->setPosition(this->getPosition());
		//pP->updatePosition({ this->getSize().x / 2, 0 });
		if (this->getPosition().x > pPlayer->getPosition().x)
			pP->speed.x = -600.0f;
		else
			pP->speed.x = 600.0f;
	}

	void Plant::execute()
	{

		updatePosition();

		shootInterval += pGraMan->getDeltaTime();

		float dy = pPlayer->getPosition().y - this->getPosition().y > 0 ? pPlayer->getPosition().y - this->getPosition().y : this->getPosition().y - pPlayer->getPosition().y;
		if (!pPlayer->getAlive())
			return;

		if (pPlayer->getPosition().y + pPlayer->getSize().y / 2 > this->getPosition().y) // se o player esta abaixo do centro do inimigo
		//if ((pPlayer->getSize().y + this->getSize().y) / 2 > dy) // estao colidindo no eixo y, entao atira
		{
			if (shootInterval > shootCooldown)
			{
				shootInterval = 0;
				std::cout << "2" << std::endl;
				shoot();
			}
		}
		
	}

	void Plant::addProjectile(Projectile* pP)
	{
		projectiles.push_back(pP);
	}

	void Plant::setAlive(bool status)
	{
		if (status == false)
		{
			std::list<Projectile*>::iterator it;
			for (it = projectiles.begin(); it != projectiles.end(); it++)
				(*it)->setAlive(false);
		}
	}
}