#include "Individuo.h"

int Individuo::tam = -1;
int Individuo::mut_prob = -1;

Individuo::Individuo(){
    setPosicaoFinal(-1,-1);
    if(tam>0) cromossomo.resize(tam);
}

void Individuo::inicializar(){
    for(int g=0; g<cromossomo.size();g++){
        int coin = rand()%5;  // de 0 a 4
         cromossomo.at(g) = coin;
        
    }
}

void Individuo::imprimir(){

    cout<<"\t"<<this->fitness << "\t" << "(" << this->posicaoFinal.first << "," << this->posicaoFinal.second <<")";
    cout<<endl;
}

void Individuo::setPosicaoFinal(int i, int j){
    this->posicaoFinal.first = i;
    this->posicaoFinal.second = j;
}
void Individuo::mutar(){
    for(int g=0; g<cromossomo.size();g++){
        int coin = rand()%100; // de 0 a 4
        if(coin < mut_prob){
            int coin2 = rand()%5;
            cromossomo.at(g) = coin2;
        }  
    }
}

void Individuo::setCromossomo(vector<tipo> cromossomo){
    if(this->cromossomo.size() == cromossomo.size()){
        this->cromossomo = cromossomo;
    }
}

vector<tipo> Individuo::getCromossomo(){
    return this->cromossomo;
}

tipo Individuo::getGene(int pos){
    return cromossomo.at(pos);
}

void Individuo::setFitness(double fitness){
    this->fitness = fitness;
}

double Individuo::getFitness(){
    return this->fitness;
}

Individuo::~Individuo(){
    //dtor
}
