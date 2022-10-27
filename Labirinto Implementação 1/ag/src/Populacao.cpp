#include "Populacao.h"

int Populacao::tam = -1;

Populacao::Populacao(){
    if(tam>0) individuos.resize(tam);
}

void Populacao::inicializar(){
    for(int i=0; i<individuos.size();i++) individuos.at(i).inicializar();
}

void Populacao::imprimir(){
    for(int i=0; i<Populacao::tam;i++) individuos.at(i).imprimir();
    cout<<"----------------"<<endl;
}

Individuo* Populacao::getIndividuo(int p){
    return &(individuos.at(p));
}

vector<Individuo> Populacao::getIndividuos(){
    return individuos;
}

void Populacao::setIndividuo(Individuo i, int pos){
    individuos.at(pos) = i;
}

Populacao::~Populacao()
{
    //dtor
}
