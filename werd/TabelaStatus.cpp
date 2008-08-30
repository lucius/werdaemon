#include "TabelaStatus.h"

#include <assert.h>

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
        this->tabela[_territorio] = new TuplaStatus(_territorio, _jogador, _exercitos);
    }
    else
    {
        this->tabela[_territorio]->setStatus(_territorio, _jogador, _exercitos);
    }
}
