#include "AG.h"

int ger = 0;
int encontrou = 0;
int AG::cross_p_corte = -1;
bool AG::setted = false;
clock_t t;
    Labirinto lab;

AG::AG(){
    if(!AG::setted){
        cout<<"AG nao configurado previamente. Valores padrões estão sendo usados."<<endl;
        AG::setParametros(10,50,5,150);
    }
}

void AG::executar(int maxGen){
    t = clock();
    inicializar();
    fitness(p);
    for(int g=0; g<maxGen; g++){
        cout << endl << "----------------------------------------------" << endl;
        cout << "GERACAO " << g << endl;
        p->imprimir();
        
        crossover();
        cout << "Terminou" << endl;
        mutacao();
    
        fitness(f);
        selecaoGeracional();
        
    }
        std::cout << "Tempo de execucao: " << ((double)t)/((CLOCKS_PER_SEC/1000)) << " milisegundos" << std::endl;

}

void AG::selecaoGeracional(){
    vector<Individuo> pop1 = p->getIndividuos();
    vector<Individuo> pop2 = f->getIndividuos();

    sort(pop1.begin(),pop1.end(),Individuo::comparar);
    sort(pop2.begin(),pop2.end(),Individuo::comparar);

    int ind1=0, ind2 = 0;
    for(int i=0; i<Populacao::getTamanho();i++){
        Individuo escolhido;
        if(pop1.at(ind1).getFitness()  < pop2.at(ind2).getFitness()){
            escolhido = pop1.at(ind1);
            ind1++;
        }
        else{
            escolhido = pop2.at(ind2);
            ind2++;
        }
        p->setIndividuo(escolhido,i);
    }
}

void AG::inicializar(){
    p = new Populacao();
    f = new Populacao();
    p->inicializar();
}

void AG::crossover(){
    for(int i=0; i<f->getTamanho();i+=2){
        int p_pai1 = getIndicePai();
        int p_pai2 = getIndicePai();

        Individuo* pai1 = p->getIndividuo(p_pai1);
        Individuo* pai2 = p->getIndividuo(p_pai2);

        vector<tipo> cromo1;
        vector<tipo> cromo2;

        for(int g=0; g<AG::cross_p_corte;g++){
            cromo1.push_back(pai1->getGene(g));
            cromo2.push_back(pai2->getGene(g));
        }
        for(int g=AG::cross_p_corte; g<pai1->getTamanho();g++){
            cromo1.push_back(pai2->getGene(g));
            cromo2.push_back(pai1->getGene(g));
        }

        Individuo i1;
        Individuo i2;

        i1.setCromossomo(cromo1);
        i2.setCromossomo(cromo2);

        f->setIndividuo(i1,i);
        f->setIndividuo(i2,i+1);
    }
}

void AG::mutacao(){
    for(int i=0; i<f->getTamanho();i++){
        f->getIndividuo(i)->mutar();
    }
}

void AG::fitness(Populacao* p){
    Labirinto aux;
    int fitAux = 1000000000;
    for(int i=0; i<p->getTamanho();i++){
        calcFitness(p->getIndividuo(i));
        if(p->getIndividuo(i)->getFitness() < fitAux){
            fitAux = p->getIndividuo(i)->getFitness(); 
            aux.setLab(lab.getLab());
        }
        if(p->getIndividuo(i)->posicaoFinal.first == 8  && p->getIndividuo(i)->posicaoFinal.second == 12){
            cout << "ENCONTROU!!!" << endl;
            if(encontrou == 0){
                t = clock()-t;
                encontrou = 1;
                system("pause");
            }
            
        }
        //lab.imprimir();
        lab.resetar();
    }
    //aux.imprimir();
}

int AG::getIndicePai(){
    return rand()%p->getTamanho();
}

void AG::calcFitness(Individuo* i){
    int fit = 0, mov = 0;
    
    for(int c=0; c<i->getTamanho(); c++){

        mov = i->getGene(c);
        if (mov == 0)
            lab.penalidades++;
        if (mov == 1)
            lab.MoveUp();
        if (mov == 2)
            lab.MoveDown();
        if (mov == 3)
            lab.MoveRight();
        if (mov == 4)
            lab.MoveLeft();
        
    }

    i->setPosicaoFinal(lab.posicaoAtual.first,lab.posicaoAtual.second);

    // fit = |xf - xi|+ |yf - yi| + penalidades
    fit = abs(lab.posicaoFinal.first - lab.posicaoAtual.first) + abs(lab.posicaoFinal.second - lab.posicaoAtual.second);// + lab.penalidades;

    i->setFitness(fit);
   
}
void AG::imprimirPopulacao(){
    if(p!=NULL) p->imprimir();
    else cout<<"Populacao nao inicializada"<<endl;
}

AG::~AG(){
    if(p!=NULL) delete p;
    if(f!=NULL) delete f;
}