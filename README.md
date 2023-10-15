# Pixel Adventure - Jogo de plataforma 2d

## Introdução
Esse jogo foi desenvolvido, primariamente, como um trabalho para a disciplina de técnicas de programação. Apesar de existir outro usuário na parte dos contribuidores, ele não participou no desenvolvimento do jogo, pois desistiu da matéria, sendo que todo trabalho do jogo foi realizado inteiramente por mim. 

## Features
O jogo possui funcionamento similar ao tradicional jogo de plataforma 2D Mário, no qual é necessário "bater na cabeça" dos inimigos para neutralizá-los, enquanto uma colisão lateral resultará na morte do seu personagem. Ele possui diversas características, como gerenciamento de colisões, pulo, movimentação, sistema de pontuação, 3 inimigos e 3 blocos cada um com características únicas e inicializados com geração aleatória, salvamento de pontuação e estado da fase, jogabilidade para um ou dois jogadores, que podem ser controlados pelas setas do teclado e pelas teclas WASD, e menu gráfico, controlado pelas também pelas setas, que possibilita a escolha entre duas fases de jogo únicas, verificação do leaderboard com as 10 maiores pontuações e configurações.

## Obstáculos e Inimigos
Com relação aos inimigos, existem 3: o cogumelo, que anda para os lados com velocidade aleatória, a planta, que fica parada mas atira projéteis, e o porco, que possui 3 vidas (é necessário pular 3 vezes em sua cabeça para neutralizá-lo), sendo que depois de atingido duas vezes ele muda para o estado irritado, no qual sua velocidade aumenta. Com relação aos 3 obstáculos existentes, o fogo faz com que o personagem principal morra, a lama (obstáculo verde) diminui a velocidade do seu personagem e impossibilita o pulo e o gelo faz com que os inimigos que passem em cima dele pulem.

## Código
Quanto ao código, ele foi feito na linguagem C++ com o uso da biblioteca gráfica SFML. Nele foi utilizado o princípio de programação orientada a objetos com a utilização de diversos de seus conceitos, como Classe, Objeto, Gabaritos, Polimorfismo e Persistências de Objetos. Além disso, a construção desse jogo também foi amparada pela utilização dos conceitos de engenharia de software e do uso de diversos padrões de projeto, como por exemplo o Singleton. Esse jogo obteve nota 9 na avaliação do professor da disciplina citada acima.

## Como Executar
Para executar o jogo, é necessário estar no sistema operacional Windows. Entre na pasta "Release" e execute o arquivo "Game.exe".
