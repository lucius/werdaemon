#include "TuplaStatus.h"

TuplaStatus::TuplaStatus()
{

}

TuplaStatus::~TuplaStatus()
{

}

void
TuplaStatus::setStatus(std::string _territorio, std::string _jogador, short unsigned int _exercitos)
{
    this->territorio = _territorio;
    this->jogador    = _jogador;
    this->exercitos  = _exercitos;
}

std::string
TuplaStatus::getTerritorio()
{
    return this->territorio;
}

std::string
TuplaStatus::getJogador()
{
    return this->jogador;
}

unsigned short int
TuplaStatus::getExercitos()
{
    return this->exercitos;
}
