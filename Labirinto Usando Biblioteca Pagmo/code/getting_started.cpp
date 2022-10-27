#include <cmath>
#include <initializer_list>
#include <iostream>
#include <utility>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <time.h>
#include <pagmo/algorithm.hpp>
#include <pagmo/algorithms/sga.hpp>
#include <pagmo/population.hpp>
#include <pagmo/problem.hpp>
#include <pagmo/problems/dtlz.hpp>
#include <pagmo/problem.hpp>
#include <pagmo/types.hpp>

using namespace pagmo;

using namespace std;

typedef double tipo;
clock_t t;

class Labirinto
{
public:
    // WLabirinto(vector<vector<char>> labirinto, int LINHAS, int COLUNAS);
    // virtual ~Labirinto();

    pair<int, int> posicaoInicial;
    pair<int, int> posicaoAtual;
    pair<int, int> posicaoFinal;
    int penalidades;
    int LINHAS;
    int COLUNAS;

    Labirinto()
    {
        LINHAS = LINHASPADRAO;
        COLUNAS = COLUNASPADRAO;

        // cout << LINHAS << " " << COLUNAS << endl;

        char labirintoPadrao[LINHAS][COLUNAS] = {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, // # = Wall
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, // P = Player
            {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', '#'}, // F = Finish
            {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', '#'}, //' '= Floor (Empty Character)
            {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', 'P', '#', '#', '#', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
            {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#'},
            {'#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', '#', 'F', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

        vector<vector<char>> lab;
        vector<char> aux;
        for (int i = 0; i < LINHAS; i++)
        {
            for (int j = 0; j < COLUNAS; j++)
            {
                aux.push_back(labirintoPadrao[i][j]);
            }
            lab.push_back(aux);
            aux.clear();
        }
        setPosicaoAtual(5, 1);
        posicaoInicial.first = 5;
        posicaoInicial.second = 1;
        posicaoFinal.first = 8;
        posicaoFinal.second = 12;
        penalidades = 0;
        inicializar(lab, LINHAS, COLUNAS);
    };

    void inicializar(vector<vector<char>> labirinto, int LINHAS, int COLUNAS)
    {
        this->labirinto = labirinto;
    }

    bool isWall(int i, int j)
    {

        if (labirinto[i][j] == '#')
            return true;

        return false;
    }

    bool isFloor()
    {
        int i = getPosicaoAtual().first;
        int j = getPosicaoAtual().second;

        if (labirinto[i][j] == ' ')
            return true;

        return false;
    }

    bool isFinished()
    {
        return posicaoAtual == posicaoFinal;
    }

    pair<int, int> getPosicaoAtual()
    {
        return posicaoAtual;
    }

    void setPosicaoAtual(int i, int j)
    {
        posicaoAtual.first = i;
        posicaoAtual.second = j;
    }

    int getLinhas()
    {
        return LINHAS;
    }

    int getColunas()
    {
        return COLUNAS;
    }

    void imprimir()
    {

        for (int i = 0; i < labirinto.size(); i++)
        {
            for (int j = 0; j < labirinto[i].size(); j++)
            {
                cout << labirinto[i][j] << " ";
            }
            cout << endl;
        }
    }

    void MoveUp( )
    {

        int i = getPosicaoAtual().first;
        int j = getPosicaoAtual().second;
        if (i > 0)
        {
            if (!isWall(i - 1, j))
            {
                labirinto[i][j] = ' ';
                labirinto[i - 1][j] = 'P';
                setPosicaoAtual(i - 1, j);
            }
            else
            {
                penalidades++;
            }
        }
        else
        {
            penalidades++;
        }
    }

    void MoveDown()
    {
        int i = getPosicaoAtual().first;
        int j = getPosicaoAtual().second;
        if (i < getLinhas())
        {
            if (!isWall(i + 1, j))
            {
                labirinto[i][j] = ' ';
                labirinto[i + 1][j] = 'P';
                setPosicaoAtual(i + 1, j);
            }
            else
            {
                penalidades++;
            }
        }
        else
        {
            penalidades++;
        }
    }

    void MoveRight()
    {
        int i = getPosicaoAtual().first;
        int j = getPosicaoAtual().second;
        if (j < getColunas())
        {
            if (!isWall(i, j + 1))
            {
                labirinto[i][j] = ' ';
                labirinto[i][j + 1] = 'P';
                setPosicaoAtual(i, j + 1);
            }
            else
            {
                penalidades++;
            }
        }
        else
        {
            penalidades++;
        }
    }

    void MoveLeft()
    {
        int i = getPosicaoAtual().first;
        int j = getPosicaoAtual().second;
        if (j > 0)
        {
            if (!isWall(i, j - 1))
            {
                labirinto[i][j] = ' ';
                labirinto[i][j - 1] = 'P';
                setPosicaoAtual(i, j - 1);
            }
            else
            {
                penalidades++;
            }
        }
        else
        {
            penalidades++;
        }
    }
    void resetar()
    {
        labirinto[posicaoInicial.first][posicaoInicial.second] = 'P';
        labirinto[posicaoAtual.first][posicaoAtual.second] = ' ';
        labirinto[posicaoFinal.first][posicaoFinal.second] = 'F';
        posicaoAtual = posicaoInicial;
        penalidades = 0;
    }

protected:
private:
    const int LINHASPADRAO = 10;
    const int COLUNASPADRAO = 15;
    vector<vector<char>> labirinto; // matriz do labirinto
    char PAREDE = '#';
    char CHAO = ' ';
    char JOGADOR = 'P';
    char CHEGADA = 'F';
};

using namespace pagmo;

int geracoes = 0;
int tot_ind = 0;
// Our simple example problem, version 0.
struct problem_v0
{

    

    // Implementation of the objective function.
    vector_double fitness(const vector_double &dv) const
    {
        tot_ind++;
        if(tot_ind == 150){
            geracoes++;
            tot_ind = 0;
        }

        Labirinto lab;
        Labirinto aux;

       
        
        vector<double> cromossomo;

        for(int i = 0; i < dv.size(); i++){
            cromossomo.push_back(dv[i]);
        }


         int fit = 0;
         double mov = 0.0;

    std::cout << "-------------------------------------------" << std::endl;
    
    for(int c=0; c<dv.size(); c++){

        
         
        mov = dv[c];
        if (mov >= 0 && mov < 0.2){
            lab.penalidades++;
        }
            
        if (mov >= 0.2 && mov < 0.4){
            lab.MoveUp();
        }
            
        if (mov >= 0.4 && mov < 0.6){
            lab.MoveDown();
        }
            
        if (mov >= 0.6 && mov < 0.8){
             lab.MoveRight();
        }
           
        if (mov >= 0.8){
            lab.MoveLeft();
        }
            
        

    }
            std::cout<<"POSICAO ATUAL: (" << lab.getPosicaoAtual().first << "," << lab.getPosicaoAtual().second << ")" << std::endl;

    lab.imprimir();
        std::cout << "-------------------------------------------" << std::endl;


    // fit = |xf - xi|+ |yf - yi| + penalidades
    fit = abs(lab.posicaoFinal.first - lab.posicaoAtual.first) + abs(lab.posicaoFinal.second - lab.posicaoAtual.second) ;//+ lab.penalidades;

    
    
    
    double fitn = (double)fit;
    int a;
    if(fitn == 0.){
        cout << "ACHOU NA GERACAO: " << geracoes << endl;
         t = clock() - t;
        cin >> a ;
    }

    std::cout << "fit: " << fitn << std::endl;
    lab.resetar();
        return {fitn};
    }
    // Implementation of the box bounds.
    std::pair<vector_double, vector_double> get_bounds() const
    {
        std::vector<double> ub;
        std::vector<double> lb;
        int tam = 150;
        for(int i = 0; i < tam; i++){
            ub.push_back(1);
            lb.push_back(0);
        }
        pair<vector_double,vector_double> retorno;
        retorno.first = lb;
        retorno.second = ub;
        return {retorno};
    }
};


int main()
{
    
    t = clock();
    static Labirinto lab;
    problem prob{problem_v0{}};

    algorithm algo{sga(100,0.5,50,0.5)};

    population pop{prob, 100};

    pop = algo.evolve(pop);
    
    std::cout << "Tempo de execucao: " << ((double)t)/((CLOCKS_PER_SEC/1000)) << " milisegundos" << std::endl;


}