#include "Jogador.hpp"

Jogador::Jogador() : Personagem()
{
	posicao.x = 0.0;
	posicao.y = 0.0;
	podePular = false;
	// Posicão inicial
}
void Jogador::checkKeys()
{
	float vel = 3.0 * 100;

	velocidade.x = 0; // padrão, caso nenhuma tecla esteja sendo apertada

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		velocidade.x = -vel;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		velocidade.y = vel;
	// Para baixo não faz nada (por enquanto)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		velocidade.x = vel;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) && podePular)
		velocidade.y = -sqrtf(2 * 1000 * 200); podePular = false;
	// 2 * gravidade * altura do pulo
}
void Jogador::setPular(bool p)
{
	podePular = p;
}
