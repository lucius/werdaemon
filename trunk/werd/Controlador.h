#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <list>
#include <string>
#include "Jogador.h"
#include "Territorio.h"

class
Controlador
{
    public:
        Controlador();

        ~Controlador();

        unsigned short int
        novoJogador(std::string);

        Jogador*
        getProximoJogador();

        Territorio*
        novoTerritorio(std::string);

        Territorio*
        getTerritorio(std::string);

        std::list<Territorio*>
        getListaTerritorios();

    protected:
        std::list<Jogador*>
        jogadores;

        std::list<Jogador*>::iterator
        jogador_atual;

        std::map<std::string, Territorio*>
        territorios;
};

#endif
