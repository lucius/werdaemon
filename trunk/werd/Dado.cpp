#include "Dado.h"

#include <algorithm>
#include <iostream>
#include <vector>


Dado::Dado()
{
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
	random_shuffle( dado.begin(), dado.end() );

	return *(dado.begin());
}
