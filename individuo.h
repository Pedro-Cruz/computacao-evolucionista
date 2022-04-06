#include <string>
#include <bits/stdc++.h>

typedef vector<double> vetor;
using namespace std;

 class individuo {

    public:
        individuo();
        char* Imprimir();

    private:
        int id;
        int tamanho;
        vetor cromossomo;
};