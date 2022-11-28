#include "Plant.hpp"
#include "GraphicManager.hpp"

namespace Enemies
{
	Plant::Plant()
	{
		id = classes(plant);
		shootInterval = 0.0f;
		shootCooldown = 1.0f;
	}

	Plant::Plant(std::string data)
	{
		id = classes(plant);
		std::cout << "Recovering Mushroom " << std::endl;

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
		ss >> shootInterval;
		ss >> shootCooldown;
	}

	Plant::~Plant()
	{
		std::list<Projectile*>::iterator it;
		for (it = projectiles.begin(); it != projectiles.end(); it++)
			delete (*it);
	}

	void Plant::shoot(Player* pPlayer)
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
		pP->reset(this->getPosition());
		//pP->updatePosition({ this->getSize().x / 2, 0 });
		if (this->getPosition().x > pPlayer->getPosition().x)
			pP->speed.x = -400.0f;
		else
			pP->speed.x = 400.0f;
	}

	void Plant::execute()
	{
		checkIce();
		updatePosition();

		shootInterval += pGraMan->getDeltaTime();

		//float dy = pPlayer->getPosition().y - this->getPosition().y > 0 ? pPlayer->getPosition().y - this->getPosition().y : this->getPosition().y - pPlayer->getPosition().y;
		
		for (std::list<Player*>::iterator pPlayer = players.begin(); pPlayer != players.end(); pPlayer++)
		{
			if ((*pPlayer)->getAlive())
			{
				if ((*pPlayer)->getPosition().y + (*pPlayer)->getSize().y / 2 > this->getPosition().y) // se o player esta abaixo do centro do inimigo
					//if ((pPlayer->getSize().y + this->getSize().y) / 2 > dy) // estao colidindo no eixo y, entao atira
				{
					if (shootInterval > shootCooldown)
					{
						shootInterval = 0;
						std::cout << "2" << std::endl;
						shoot((*pPlayer));
					}
				}
			}
		}
	}

	void Plant::addProjectile(Projectile* pP)
	{
		projectiles.push_back(pP);
		std::cout << "Projectile " << pP->getAlive() << std::endl;
	}

	void Plant::setAlive(bool status)
	{
		if (status == false)
		{
			std::list<Projectile*>::iterator it;
			for (it = projectiles.begin(); it != projectiles.end(); it++)
				(*it)->setAlive(false);
		}
		alive = false;
	}
	
	void Plant::save()
	{
		std::cout << "Saving plant " << std::endl;
		try {
			std::ofstream plantFile("../data/Level1/Plant.txt", std::ios_base::app);
			plantFile << alive << " "
				<< position.x << " " << position.y << " "
				<< size.x << " " << size.y << " "
				<< speed.x << " " << speed.y << " "
				<< acceleration.x << " " << acceleration.y << " "
				<< hp << " "
				<< damage << " "
				<< shootInterval << " "
				<< shootCooldown << " "
				<< std::endl;
			plantFile.close();
			std::list<Projectile*>::iterator projectile;
			for (projectile = lastProjectileShooted; projectile != lastProjectileShooted; projectile++)
			{
				(*projectile)->save();
				if (projectile == projectiles.end())
					projectile = projectiles.begin();
			}
		}
		catch (const std::exception& ex) {
			std::cout << "Error saving plant " << std::endl;
			std::cout << ex.what() << std::endl;
		}
		
		
	}
}