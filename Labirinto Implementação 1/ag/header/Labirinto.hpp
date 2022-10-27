#ifndef LABIRINTO_H
#define LABIRINTO_H
#include <bits/stdc++.h>
#include <iostream>


using namespace::std;

/*

O construtor vazio irá inicializar com um labirinto padrão, caso o construtor com o
labirinto seja utilizado, esse será inicializado e os parâmetros desse labirinto deverão ser fornecidos.

O cromossomo será um conjunto de instruções, onde esse vetor de 0 a 4 será sequencialmente:
0 - sem ação
1 - mover para cima
2 - mover para baixo
3 - mover para direita
4 - mover para esquerda

O tamanho do cromossomo será definido a quantidade de passos máximos no labirinto, esse tamanho é arbitrário,
para o padrão sugestão de 150 para testes iniciais.

Também será fornecido os pontos iniciais do jogador(P = <x1,y1>) e a chegada(F = <x2,y2>).

O fitness será calculado pela distância entre o ponto P e o F da matriz, dado pela formula: 
d = |x2-x1| + |y2-y1|

O crossover e mutação serão parecidos com os exemplos ja vistos.

*/

class Labirinto{
    public:
        Labirinto(vector<vector<char>> labirinto, int LINHAS, int COLUNAS);
        Labirinto();
        virtual ~Labirinto();
        bool isWall(int x, int y); // verifica se e parede
        bool isFloor(); // verifica se e chao
        bool isFinished(); // verifica se o labirinto terminou
         pair<int,int> getPosicaoAtual(); // posicao atual do jogador
         void setPosicaoAtual(int x, int y); // seta a posicao atual
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();
         int getLinhas();
         int getColunas();
        vector<vector<char>> getLab();
        void setLab(vector<vector<char>> lab);
        void resetar();
        pair<int,int> posicaoInicial;
         pair<int,int> posicaoAtual;
         pair<int,int> posicaoFinal;
        int penalidades;
        int LINHAS;
        int COLUNAS;

        void imprimir();
        void inicializar(vector<vector<char>> labirinto, int LINHAS, int COLUNAS); // Inicializa o labirinto
    protected:

    private:

         const int LINHASPADRAO = 10;
         const int COLUNASPADRAO = 15; 
        vector<vector<char>> labirinto; // matriz do labirinto
        char PAREDE='#';
        char CHAO=' ';
        char JOGADOR='P';
        char CHEGADA='F';    
           
};

#endif // LABIRINTO_H
