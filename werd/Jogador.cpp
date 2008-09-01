#include "Jogador.h"
#include <iostream>

Jogador::Jogador()
{
    this->nick = "Jogador"; // Adicionar uma ID randômica em cada jogador.
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
    if (NULL != _territorio)
    {
        std::cout << "(Jogador::ganhaTerritorio) '" << _territorio->getNome() << "' é um território válido..." << std::endl;

//      Se outro possuir este territorio, este irá perdê-lo.
        if (NULL != _territorio->getPossuidor())
        {
            if (_territorio->getPossuidor() != this)
            {
                _territorio->getPossuidor()->perdeTerritorio(_territorio);
            }

//          Ganha o território se ainda não for possuidor do mesmo.
            this->territorios[_territorio->getNome()] = _territorio;
            std::cout << "(Jogador::ganhaTerritorio) '" << this->nick << "' ganha '" << ((Territorio*) this->territorios[_territorio->getNome()])->getNome() << "'..." << std::endl;
            _territorio->setPossuidor(this);
        }
    }
}

void
Jogador::perdeTerritorio(Territorio* _territorio)
{
    Territorio*
    territorio = (Territorio*) this->territorios[_territorio->getNome()];

//    Se realmente possuir o território, então apague ele da coleção.
    if (NULL != territorio && NULL != territorio->getPossuidor()
        &&
        territorio->getPossuidor()->getNick() == this->nick)
    {
        this->territorios.erase(_territorio->getNome());
        std::cout << "(Jogador::ganhaTerritorio) '" << this->getNick() << "' acaba de perder '"<< _territorio->getNome() << "'..." << std::endl;
    }
}

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
