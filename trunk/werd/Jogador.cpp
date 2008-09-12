#include "Jogador.h"
#include <iostream>

Jogador::Jogador()
{
    this->nick = "Jogador"; // Adicionar uma ID rand�mica em cada jogador.
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

std::string
Jogador::getIP()
{
    return this->ip;
}

void
Jogador::setIP(std::string _ip)
{
    this->ip = _ip;
}

void
Jogador::ganhaTerritorio(Territorio* _territorio)
{
    if (NULL != _territorio)
    {
        std::cout << "(Jogador::ganhaTerritorio) '" << _territorio->getNome() << "' � um territ�rio v�lido..." << std::endl;

//      Se outro possuir este territorio, este ir� perd�-lo.
        if (NULL != _territorio->getPossuidor())
        {
            if (_territorio->getPossuidor() != this)
            {
                _territorio->getPossuidor()->perdeTerritorio(_territorio);
            }

//          Ganha o territ�rio se ainda n�o for possuidor do mesmo.
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

//    Se realmente possuir o territ�rio, ent�o apague ele da cole��o.
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

    //    Se realmente possuir o territ�rio, ent�o aloque para ele a quantidade de ex�rcitos.
    if (0 != territorio && territorio->getPossuidor()->getNick() == this->nick)
    {
        territorio->setExercitos(_exercitos);
    }
}
