#ifndef AG_H
#define AG_H

#include "Populacao.h"
#include <algorithm>
#include <stdio.h>
#include "Labirinto.hpp"
#include <cstdlib>
#include<time.h>
#include <stdlib.h>
#include<stdio.h>

using namespace::std;

    


class AG{

    public:
        static void setParametros(int tam_pop, int mut_prob, int cross_p_corte, int passos)
        {
            Individuo::setTamanho(passos);
            Individuo::setProbMutacao(mut_prob);
            Populacao::setTamanho(tam_pop);
            AG::cross_p_corte = cross_p_corte;
            AG::setted = true;
            //AG::m = m;
        }

        AG();
        void executar(int maxGen);
        void imprimirPopulacao();
        void imprimirMelhor();
        virtual ~AG();

    protected:

    private:
        static int cross_p_corte;
        static bool setted;
       // static Mochila* m;

        void inicializar();
        void crossover();
        void mutacao();
        void fitness(Populacao* p);
        void calcFitness(Individuo* i);
        int getIndicePai();
        void selecaoGeracional();

        Populacao* p = NULL;
        Populacao* f = NULL;
        
};

#endif // AG_H