#include "Player.hpp"
#include "GraphicManager.hpp"
#include "Level.hpp"

Player::Player(int pId) : 
	Character(),
	playerId(pId)
{
	id = (classes)player;
	position.x = 0.0;
	position.y = 0.0;
	canJump = false;
	canWalk = true;
	pontuation = 0;
	movingSpeed = 300.0f;
	jumpHeight = -sqrtf(2 * GRAVITY * 130);
	mudCooldown = 0.0f;
	sandCooldown = 0.0f;

	assignKeys();
	// Posic�o inicial
}

Player::Player(std::string data)
{
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
	ss >> playerId;
	ss >> canJump;
	ss >> canWalk;
	ss >> pontuation;
	ss >> movingSpeed;
	ss >> jumpHeight;
	ss >> mudCooldown;
	ss >> sandCooldown;

	assignKeys();
}

void Player::assignKeys()
{
	if (playerId == 1)
	{
		keys[0] = sf::Keyboard::Key::A;
		keys[1] = sf::Keyboard::Key::D;
		keys[2] = sf::Keyboard::Key::W;
	}
	else if (playerId == 2)
	{
		keys[0] = sf::Keyboard::Key::Left;
		keys[1] = sf::Keyboard::Key::Right;
		keys[2] = sf::Keyboard::Key::Up;
	}
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

	speed.x = 0; // padr�o, caso nenhuma tecla esteja sendo apertada
	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keys[0]) && (canWalk || canJump == false))
		speed.x = -movingSpeed;
	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keys[1]) && (canWalk || canJump == false))
		speed.x = movingSpeed;
	if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keys[2])) && canJump)
		speed.y = jumpHeight; canJump = false;
	// 2 * gravidade * altura do pulo
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		Manager::StateManager::getInstance()->push(level2);
		
}

void Player::checkForObstacles()
{
	if (sandCooldown > 0.05f)
	{
		sandCooldown -= pGraMan->getDeltaTime();
	}
	else {
		jumpHeight = -sqrtf(2 * GRAVITY * 130);
		sandCooldown = 0.0f;
		setWalk(true);
	}

	if (mudCooldown > 0.05f)
	{
		mudCooldown -= pGraMan->getDeltaTime();
		setJump(false);
	}
	else {
		movingSpeed = 300.0f;
		mudCooldown = 0.0f;
	}
}

void Player::setJump(bool p)
{
	canJump = p;
}

void Player::setWalk(bool w)
{
	canWalk = w;
}

void Player::execute()
{
	checkForObstacles();
	checkKeys();
	updatePosition();
	//displayPoints();
}

void Player::executeJump(float height)
{
	speed.y = height; 
	canJump = false;
}

void Player::setHp(int newHp)
{
	if (!alive)
		return;
	hp = newHp;
	if (hp <= 0)
	{
		pLevel->decreasePlayerAmount();
		setAlive(false);
	}
}
void Player::decreaseHp(int qtd)
{
	if (!alive)
		return;
	hp -= qtd;
	if (hp <= 0)
	{
		pLevel->decreasePlayerAmount();
		setAlive(false);
	}
}

void Player::save()
{
	std::cout << "Saving player " << pLevel->getId() << std::endl;
	std::ofstream playerFile;
	if (pLevel->getId() == 1)
		playerFile.open("../data/Level1/Player.txt", std::ios_base::app);
	else
		playerFile.open("../data/Level2/Player.txt", std::ios_base::app);
	playerFile  << alive << " " 
				<< position.x << " " << position.y << " " 
				<< size.x << " " << size.y << " "
				<< speed.x << " " << speed.y << " "
				<< acceleration.x << " " << acceleration.y << " "
				<< hp << " "
				<< playerId << " "
				<< canJump << " "
				<< canWalk << " "
				<< pontuation << " "
				<< movingSpeed << " "
				<< jumpHeight << " "
				<< mudCooldown << " " 
				<< sandCooldown << " "
				<< std::endl;
	playerFile.close();
}