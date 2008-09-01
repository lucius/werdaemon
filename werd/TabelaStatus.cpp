#include "TabelaStatus.h"

#include <iostream>

TabelaStatus::TabelaStatus()
{

}

TabelaStatus::~TabelaStatus()
{

}

std::vector< TuplaStatus* >
TabelaStatus::getTuplas()
{
    std::vector<TuplaStatus*>
    tuplas;

    for (std::map<std::string, TuplaStatus*>::iterator it = this->tabela.begin();
         it != this->tabela.end(); ++it)
    {
        tuplas.push_back(it->second);
    }

    return tuplas;
}

void
TabelaStatus::setTupla(std::string _territorio, std::string _jogador, unsigned short int _exercitos)
{
    // Ou seja, a tupla ainda não foi inicializada.
    if (0 == this->tabela[_territorio])
    {
        std::cout << "(TabelaStatus::setTupla) Uma nova tupla deverá ser inicializada..." << std::endl;

        TuplaStatus*
        novaTupla = new TuplaStatus();

        novaTupla->setStatus(_territorio, _jogador, _exercitos);

        this->tabela[_territorio] = novaTupla;
    }
    else
    {
        std::cout << "(TabelaStatus::setTupla) Atualizando uma tupla existente..." << std::endl;
        this->tabela[_territorio]->setStatus(_territorio, _jogador, _exercitos);
    }
}
