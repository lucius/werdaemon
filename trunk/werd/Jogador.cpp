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

// @ TODO testar
void
Jogador::ganhaTerritorio(Territorio* _territorio)
{
//    Ganha o território se ainda não for possuidor do mesmo.
    if (this->territorios[_territorio->getNome()] != 0)
    {
        this->territorios[_territorio->getNome()] = _territorio;
        _territorio->setPossuidor(this);
    }
}

// @ TODO testar
void
Jogador::perdeTerritorio(Territorio* _territorio)
{
    Territorio*
    territorio = (Territorio*) this->territorios[_territorio->getNome()];

//    Se realmente possuir o território, então apague ele da coleção.
    if (0 == territorio->getPossuidor()->getNick().compare(this->getNick()))
    {
        this->territorios.erase(_territorio->getNome());
    }
}

// @ TODO testar
void
Jogador::setExercitos(unsigned short int _exercitos, Territorio* _territorio)
{
    Territorio*
    territorio = (Territorio*) this->territorios[_territorio->getNome()];

    //    Se realmente possuir o território, então aloque para ele a quantidade de exércitos.
    if (0 == territorio->getPossuidor()->getNick().compare(this->getNick()))
    {
        territorio->setExercitos(_exercitos);
    }
}
