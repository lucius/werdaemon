#include "Dado.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include "Random.h"

Dado::Dado()
{
    #define RANDMAX 5

	dado.push_back(1);
	dado.push_back(2);
	dado.push_back(3);
	dado.push_back(4);
	dado.push_back(5);
	dado.push_back(6);
}

unsigned short int
Dado::embaralha()
{
    Random
    funcaoGeradora;

	random_shuffle( dado.begin(), dado.end(), funcaoGeradora );

	return *(dado.begin());
}
