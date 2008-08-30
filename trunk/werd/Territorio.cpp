#include "Territorio.h"
#include <iostream>

Territorio::Territorio()
{
    this->exercitos = 1;
    std::cout << "(Territorio::Territorio) Inicializando novo territorio com 1 exercito..." << std::endl;
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

unsigned short int
Territorio::getExercitos()
{
    return this->exercitos;
}

void
Territorio::setExercitos(unsigned short int _exercitos)
{
    this->exercitos = _exercitos;
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

// @ TODO testar
Jogador*
Territorio::getPossuidor()
{
    return this->castPossuidor();
}

// @ TODO testar
void
Territorio::setPossuidor(Jogador* _jogador)
{
    if (0 != this->castPossuidor()->getNick().compare(_jogador->getNick()))
    {
        this->castPossuidor()->perdeTerritorio(this);
        this->possuidor = _jogador;
        _jogador->ganhaTerritorio(this);
    }
}

// @ TODO testar
bool
Territorio::pertenceA(std::string _jogador)
{
    return (0 == this->castPossuidor()->getNick().compare(_jogador)) ? true : false;
}

// @ TODO testar
Jogador*
Territorio::castPossuidor()
{
    return (Jogador*) this->possuidor;
}
