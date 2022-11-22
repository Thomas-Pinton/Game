#include "Player.hpp"
#include "GraphicManager.hpp"

Player::Player(int pId) : 
	Character(),
	playerId(pId)
{
	position.x = 0.0;
	position.y = 0.0;
	canJump = false;
	pontuation = 0;
	movingSpeed = 300.0f;
	mudCooldown = 0.0f;

	if (pId == 1)
	{
		keys[0] = sf::Keyboard::Key::A;
		keys[1] = sf::Keyboard::Key::D;
		keys[2] = sf::Keyboard::Key::W;
	}
	else if (pId == 2)
	{
		keys[0] = sf::Keyboard::Key::Left;
		keys[1] = sf::Keyboard::Key::Right;
		keys[2] = sf::Keyboard::Key::Up;
	}
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		//pausar jogo
	}

	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keys[0]))
		speed.x = -movingSpeed;
	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keys[1]))
		speed.x = movingSpeed;
	if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keys[2])) && canJump)
		speed.y += -sqrtf(2 * GRAVITY * 130); canJump = false;
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

void Player::executeJump(float height)
{
	speed.y = height; 
	canJump = false;
}