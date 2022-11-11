#include "Player.hpp"

Player::Player() : Character()
{
	position.x = 0.0;
	position.y = 0.0;
	canJump = false;
	// Posic�o inicial
}
void Player::checkKeys()
{
	float vel = 3.0 * 100;

	speed.x = 0; // padr�o, caso nenhuma tecla esteja sendo apertada

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		speed.x = -vel;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		speed.y = vel;
	// Para baixo n�o faz nada (por enquanto)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		speed.x = vel;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) && canJump)
		speed.y += -sqrtf(2 * 1000 * 130); canJump = false;
	// 2 * gravidade * altura do pulo
}
void Player::setJump(bool p)
{
	canJump = p;
}

void Player::execute(float deltaTime)
{
	checkKeys();
	updatePosition(deltaTime);
}
