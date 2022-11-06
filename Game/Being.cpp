#include "Entity.hpp"
#include "GraphicManager.hpp"

Ente::Ente()
	: //sprite(),
	rectangle() //temporário
{
	id = id_count;
	id_count++;
	// id não imprementado ainda
}

void Ente::setTexture(std::string filePath)
{
	if (!texture.loadFromFile(filePath))
	{
		std::cout << "Erro ao carregar imagem" << std::endl;
		return;
	}
	sprite.setTexture(texture);
}

void Ente::setTamanho(Coordenada<float> t) {
	tamanho = t;
	rectangle.setSize(sf::Vector2f(t.x, t.y));
	rectangle.setOrigin(sf::Vector2f(t.x / 2, t.y / 2));
	// mudar para sprite
}

void Ente::setPosicao(Coordenada<float> p)
{
	posicao = p;
	rectangle.setPosition(sf::Vector2f(p.x, p.y));
	// mudar para sprite
}

void Ente::imprimir(GerenciadorGrafico* pGerenciadorGrafico)
{
	pGerenciadorGrafico->imprimeEnte(this);
}

const Coordenada<float> Ente::getTamanho() const {
	return tamanho;
}

const Coordenada<float> Ente::getPosicao() const {
	return posicao;
}

const int Ente::getId() const {
	return id;
}