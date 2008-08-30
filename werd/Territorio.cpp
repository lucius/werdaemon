#include "Territorio.h"
#include <iostream>

Territorio::Territorio()
{
    std::cout << "(Territorio::Territorio) Inicializando novo territorio..." << std::endl;
}


Territorio::~Territorio()
{
    std::cout << "(Territorio::~Territorio) Territorio '" << this->nome << "' desalocado..." << std::endl;
}

std::string
Territorio::getNome()
{
    return this->nome;
}

void
Territorio::setNome(std::string _nome)
{
    this->nome = _nome;
}

bool
Territorio::fazFronteiraCom(std::string _nomeTerritorio)
{
    if (this->fronteiras.count(_nomeTerritorio) > 0)
    {
        std::cout << "(Territorio::fazFronteiraCom) Territorio '" << this->nome << "' faz fronteira com '" << _nomeTerritorio << "'..." << std::endl;
        return true;
    }

    std::cout << "(Territorio::fazFronteiraCom) Territorio '" << this->nome << "' nao faz fronteira com '" << _nomeTerritorio << "'..." << std::endl;
    return false;
}

void
Territorio::adicionaFronteiraCom(Territorio* _territorio)
{
    std::cout << "(Territorio::adicionaFronteiraCom) Territorio '" << this->nome << "' esta fazendo fronteira com '" << _territorio->getNome() << "'..." << std::endl;
    fronteiras[_territorio->getNome()] = _territorio;
}
