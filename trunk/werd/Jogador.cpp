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

void
Jogador::ganhaTerritorio(Territorio* _territorio)
{
    if (0 != _territorio)
    {
        std::cout << "(Jogador::ganhaTerritorio) '" << _territorio->getNome() << "' é um território válido..." << std::endl;

// TODO BODACIOUS CANSADO! CORRIGIR O PONTEIRO NULO DA MESMA MANEIRA
// COMO FOI FEITO EM TERRITORIO NO CAST!
//        Se outro possuir este territorio, este irá perdê-lo.
//        if (0 != _territorio->getPossuidor())
//        {
//            if (_territorio->getPossuidor()->getNick() != this->nick)
//            {
//                _territorio->getPossuidor()->perdeTerritorio(_territorio);
//            }
//        Ganha o território se ainda não for possuidor do mesmo.
            this->territorios[_territorio->getNome()] = _territorio;
            std::cout << "(Jogador::ganhaTerritorio) '" << this->getNick() << "' ganha '" << _territorio->getNome() << "'..." << std::endl;
            _territorio->setPossuidor(this);
//        }
    }
}

void
Jogador::perdeTerritorio(Territorio* _territorio)
{
    Territorio*
    territorio = (Territorio*) this->territorios[_territorio->getNome()];

//    Se realmente possuir o território, então apague ele da coleção.
    if (0 != territorio && 0 != territorio->getPossuidor()
        &&
        territorio->getPossuidor()->getNick() == this->nick)
    {
        this->territorios.erase(_territorio->getNome());
        std::cout << "(Jogador::ganhaTerritorio) '" << this->getNick() << "' acaba de perder '"<< _territorio->getNome() << "'..." << std::endl;
    }
}

// @ TODO testar
void
Jogador::setExercitos(unsigned short int _exercitos, Territorio* _territorio)
{
    Territorio*
    territorio = (Territorio*) this->territorios[_territorio->getNome()];

    //    Se realmente possuir o território, então aloque para ele a quantidade de exércitos.
    if (0 != territorio && territorio->getPossuidor()->getNick() == this->nick)
    {
        territorio->setExercitos(_exercitos);
    }
}
