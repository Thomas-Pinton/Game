#include "Gerenciador.hpp"

Gerenciador::Gerenciador()
{
}

Gerenciador::Gerenciador(Janela* window)
{
	// criar entes
	Jogador* player1 = new Jogador();

	player1->setTamanho({ 100, 100 });
	player1->setPosicao({ 50.0f, 50.0f });

	addPlayer(player1);

	Tile* t = NULL;

	std::list<Tile*>::iterator i;

	std::list<Tile*> tiles; // temporário

	for (int i = 0; i * 100 + 50 < window->getWIDTH() + 300; i++) // will need to work with memory managent later
	{
		t = new Tile;
		t->rectangle.setFillColor(sf::Color(255 / ((i % 2) + 1), 100, 150));
		t->setTamanho({ 100, 100 });
		t->setPosicao({ (float)(i * 100) + 50, (float)window->getHEIGHT() / 2 + 200 });
		addStaticEntity((Entidade*)t);
		tiles.push_back(t);
	}

}
void Gerenciador::addStaticEntity(Ente* pE) {
	staticEntities.push_back(pE);
}
void Gerenciador::addMovingEntity(Entidade* pE) {
	movingEntities.push_back(pE);
}
void Gerenciador::addPlayer(Jogador* pP) {
	players.push_back(pP);
}