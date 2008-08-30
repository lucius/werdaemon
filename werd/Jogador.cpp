#include "Jogador.h"
#include <iostream>

Jogador::Jogador()
{
    std::cout << "(Jogador::Jogador) Inicializando novo jogador..." << std::endl;
}


Jogador::~Jogador()
{
    std::cout << "(Jogador::~Jogador) Jogador '" << this->nick << "' desalocado..." << std::endl;
}

unsigned short int
Jogador::getId()
{
    return this->id;
}

void
Jogador::setId(unsigned short int _id)
{
    this->id = _id;
}

std::string
Jogador::getNick()
{
    return this->nick;
}

void
Jogador::setNick(std::string _nick)
{
    this->nick = _nick;
}
