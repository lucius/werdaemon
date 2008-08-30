#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <list>
#include <string>
#include "Jogador.h"
#include "Territorio.h"
#include "TabelaStatus.h"

class
Controlador
{
    public:
        Controlador();

        ~Controlador();

        Jogador*
        novoJogador(std::string);

        Jogador*
        getJogadorAtual();

        Jogador*
        getProximoJogador();

        Jogador*
        getJogador(std::string);

        std::list<Jogador*>
        getListaJogadores();

        Territorio*
        novoTerritorio(std::string);

        Territorio*
        getTerritorio(std::string);

        std::list<Territorio*>
        getListaTerritorios();

        void
        atualizaTabelaStatus();

    protected:
        std::list<Jogador*>
        jogadores;

        std::list<Jogador*>::iterator
        jogador_atual;

        std::map<std::string, Territorio*>
        territorios;

        TabelaStatus
        tabelaStatus;
};

#endif
