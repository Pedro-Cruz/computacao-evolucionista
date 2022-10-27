#include "Labirinto.hpp"
#include <bits/stdc++.h>
#include <iostream>

Labirinto::Labirinto(vector<vector<char>> labirinto, int LINHAS, int COLUNAS){

};

Labirinto::Labirinto(){
    LINHAS = LINHASPADRAO;
    COLUNAS = COLUNASPADRAO;
    
cout << LINHAS << " " << COLUNAS << endl;

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
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

    vector<vector<char>> lab;
    vector<char> aux;
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            aux.push_back(labirintoPadrao[i][j]);     
    }
    lab.push_back(aux);
    aux.clear();
    }
    setPosicaoAtual(5,1);
    posicaoInicial.first = 5;
    posicaoInicial.second = 1;
    posicaoFinal.first = 8;
    posicaoFinal.second = 12;
    penalidades = 0;
    inicializar(lab,LINHAS,COLUNAS);

};

void Labirinto::inicializar(vector<vector<char>> labirinto, int LINHAS, int COLUNAS){
        this->labirinto = labirinto;
}

bool Labirinto::isWall(int i, int j){

        if(labirinto[i][j] == '#')
            return true;

        return false;
}

bool Labirinto::isFloor(){
    int i = getPosicaoAtual().first;
    int j = getPosicaoAtual().second;

    if(labirinto[i][j] == ' ')
        return true;

    return false;
}

bool Labirinto::isFinished(){
    return posicaoAtual == posicaoFinal;
}

pair<int,int> Labirinto::getPosicaoAtual(){
    return  posicaoAtual;
}

void Labirinto::setPosicaoAtual(int i, int j){
    posicaoAtual.first = i;
    posicaoAtual.second = j;
}

int Labirinto::getLinhas(){
    return  LINHAS;
}

int Labirinto::getColunas(){
    return  COLUNAS;
}

void Labirinto::imprimir(){
  
    for (int i = 0; i < labirinto.size(); i++) {
        for (int j = 0; j < labirinto[i].size(); j++){
            cout << labirinto[i][j] << " ";
        }
        cout << endl;
      }
}


void Labirinto::MoveUp(){
    int i = getPosicaoAtual().first;
    int j = getPosicaoAtual().second; 
    if(i > 0){
        if(!isWall(i-1,j)){
            labirinto[i][j] = ' '; 
            labirinto[i-1][j] = 'P';
            setPosicaoAtual(i-1,j);
        }else{
            penalidades++;
        }
    }else{
            penalidades++;
    }
}

void Labirinto::MoveDown(){
    int i = getPosicaoAtual().first;
    int j = getPosicaoAtual().second; 
    if(i < getLinhas()){
        if(!isWall(i+1,j)){
            labirinto[i][j] = ' ';
            labirinto[i+1][j] = 'P';
            setPosicaoAtual(i+1,j);
        }else{
            penalidades++;
        }
    }else{
            penalidades++;
    }
}

void Labirinto::MoveRight(){
    int i = getPosicaoAtual().first;
    int j = getPosicaoAtual().second; 
    if(j < getColunas()){
        if(!isWall(i,j+1)){
            labirinto[i][j] = ' ';
            labirinto[i][j+1] = 'P';
            setPosicaoAtual(i,j+1);
        }else{
            penalidades++;
        }
    }else{
            penalidades++;
    }
}

void Labirinto::MoveLeft(){
    int i = getPosicaoAtual().first;
    int j = getPosicaoAtual().second; 
    if(j > 0){
        if(!isWall(i,j-1)){
            labirinto[i][j] = ' ';
            labirinto[i][j-1] = 'P';
            setPosicaoAtual(i,j-1);
        }else{
            penalidades++;
        }
    }else{
            penalidades++;
    }
}
void Labirinto::resetar(){
    labirinto[posicaoInicial.first][posicaoInicial.second] = 'P';
    labirinto[posicaoAtual.first][posicaoAtual.second] = ' ';
    labirinto[posicaoFinal.first][posicaoFinal.second] = 'F';
    posicaoAtual = posicaoInicial;
    penalidades = 0;
}


Labirinto::~Labirinto()
{
    //dtor
}

