all:
	g++ -o executar Game/Ente.cpp Game/Entidade.cpp Game/Gerenciador.cpp Game/GerenciadorColisoes.cpp Game/GerenciadorGrafico.cpp Game/GerenciadorMovimento.cpp Game/Inimigo.cpp Game/Janela.cpp Game/Jogador.cpp Game/Jogo.cpp Game/main.cpp Game/Personagem.cpp Game/Tile.cpp -lsfml-window -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-network 
