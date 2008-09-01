#include "Territorio.h"
#include <iostream>

Territorio::Territorio()
{
    this->exercitos = 1;
    this->possuidor = 0;
    std::cout << "(Territorio::Territorio) Inicializando novo territorio com 1 exercito e nenhum possuidor..." << std::endl;
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
    if (0 == this->fronteiras.count(_nomeTerritorio))
    {
        std::cout << "(Territorio::fazFronteiraCom) '" << this->nome << "' faz fronteira com '" << _nomeTerritorio << "'..." << std::endl;
        return true;
    }

    std::cout << "(Territorio::fazFronteiraCom) '" << this->nome << "' nao faz fronteira com '" << _nomeTerritorio << "'..." << std::endl;
    return false;
}

void
Territorio::adicionaFronteiraCom(Territorio* _territorio)
{
    fronteiras[_territorio->getNome()] = _territorio;
    std::cout << "(Territorio::adicionaFronteiraCom) '" << this->nome << "' está fazendo fronteira com '" << _territorio->getNome() << "'..." << std::endl;
}

Jogador*
Territorio::getPossuidor()
{
    if (NULL != this->possuidor)
    {
        std::cout << "(Territorio::getPossuidor) '" << this->getNome() << "' é possuído por '" << this->castPossuidor()->getNick() << "'..." << std::endl;
    }

    return this->castPossuidor();
}

void
Territorio::setPossuidor(Jogador* _jogador)
{
    std::cout << "(Territorio::setPossuidor) Definindo '" << _jogador->getNick() << "' como possuidor de '" << this->getNome() << "..." << std::endl;

    if (NULL == this->possuidor)
    {
        this->possuidor = _jogador;
        std::cout << "(Territorio::setPossuidor) '" << this->getNome() << "' não pertence a jogador algum. Atribuído a '" << _jogador->getNick() << "'..." << std::endl;
    }
    else if (this->castPossuidor()->getNick() != _jogador->getNick())
    {
        this->castPossuidor()->perdeTerritorio(this);
        this->possuidor = _jogador;
        std::cout << "(Territorio::setPossuidor) '" << this->getNome() << "' atribuído a '" << _jogador->getNick() << "'..." << std::endl;
        _jogador->ganhaTerritorio(this);
    }
}

bool
Territorio::pertenceA(Jogador* _jogador)
{
    return this->castPossuidor() == _jogador;
}

Jogador*
Territorio::castPossuidor()
{
    return (Jogador*) this->possuidor;
}
