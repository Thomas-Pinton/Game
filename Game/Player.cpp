#include "Player.hpp"
#include "GraphicManager.hpp"

Player::Player() : Character()
{
	position.x = 0.0;
	position.y = 0.0;
	canJump = false;
	pontuation = 0;
	movingSpeed = 300.0f;
	mudCooldown = 0.0f;
	// Posic�o inicial
}

void Player::addPoints(int amount)
{
	pontuation += amount;
}

const int Player::getPoints() const
{
	return pontuation;
}

void Player::checkKeys()
{
	//float vel = 3.0 * 100;

	if (mudCooldown > 0.05f)
	{
		mudCooldown -= pGraMan->getDeltaTime();
		setJump(false);
	}
	else {
		movingSpeed = 300.0f;
		mudCooldown = 0.0f;
	}

	speed.x = 0; // padr�o, caso nenhuma tecla esteja sendo apertada
	std::cout << "Moving speed " << movingSpeed << std::endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		speed.x = -movingSpeed;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
	//	sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	//	speed.y = vel;
	// Para baixo n�o faz nada (por enquanto)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		speed.x = movingSpeed;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) && canJump)
		speed.y += -sqrtf(2 * 1000 * 130); canJump = false;
	// 2 * gravidade * altura do pulo
}
/*
void Player::displayPoints()
{
	pGraMan->displayPoints();
}
*/
void Player::setJump(bool p)
{
	canJump = p;
}

void Player::execute()
{
	checkKeys();
	updatePosition();
	//displayPoints();
}
