#ifndef DADO_H_
#define DADO_H_

#include <iostream>
#include <string>
#include <vector>

class Dado
{
	public:
		Dado();

		unsigned short int
		embaralha();

	private:

	protected:
		std::vector<unsigned short int>
		dado;
};

#endif /*DADO_H_*/
