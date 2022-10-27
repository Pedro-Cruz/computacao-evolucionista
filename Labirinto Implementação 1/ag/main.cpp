#include <iostream>
#include "AG.h"
#include "Labirinto.hpp"
#include "Populacao.h"
#include<bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));

    AG::setParametros(100,50,50,150);

    AG ag;

    ag.executar(100);


    return 0;
}
