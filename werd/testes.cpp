#include "testes.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Controlador.h"
#include "TabelaStatus.h"
#include "TuplaStatus.h"


void
testaJogadores()
{
    std::cout << "(testaJogadores) Testando jogadores..." << std::endl;

    Controlador
    controlador;

    std::cout << "(testaJogadores) Adicionando jogadores..." << std::endl;
    controlador.novoJogador("Bode");
    controlador.novoJogador("Cido");
    controlador.novoJogador("Lucius");

    std::cout << "(testaJogadores) Obtendo proximos 10 jogadores..." << std::endl;
    for (unsigned short int i = 0; i < 10; ++i)
    {
        std::cout << "(testaJogadores) Jogador escolhido: '" << controlador.getProximoJogador()->getNick() << "'..." << std::endl;
    }
}

void
testaTerritorios()
{
    std::cout << "(testaTerritorios) Testando territorios..." << std::endl;

    Controlador
    controlador;

    std::cout << "(testaTerritorios) Adicionando territorios..." << std::endl;
    Territorio
    *Computacao = controlador.novoTerritorio("Computacao"),
    *Fisica     = controlador.novoTerritorio("Fisica"),
    *Matematica = controlador.novoTerritorio("Matematica"),
    *Economia   = controlador.novoTerritorio("Economia"),
    *Biologia   = controlador.novoTerritorio("Biologia");

    std::cout << "(testaTerritorios) Adicionando fronteiras..." << std::endl;
    Computacao->adicionaFronteiraCom(Fisica);
    Computacao->adicionaFronteiraCom(Matematica);
    controlador.getTerritorio("Computacao")->adicionaFronteiraCom(controlador.getTerritorio("Economia"));

    std::cout << "(testaTerritorios) Checando fronteiras..." << std::endl;
    Computacao->fazFronteiraCom("Fisica");
    Computacao->fazFronteiraCom("Matematica");
    Computacao->fazFronteiraCom("Economia");
    Computacao->fazFronteiraCom("Biologia");
    Computacao->fazFronteiraCom("Piramide Egipcia");

}

void
testaTabelaStatus()
{
    TabelaStatus
    tabelaStatus;

    tabelaStatus.setTupla("Computacao", "Bode",   10);
    tabelaStatus.setTupla("Matematica", "Cido",   10);
    tabelaStatus.setTupla("Fisica",     "Lucius", 10);

    std::vector< TuplaStatus* >
    tuplas = tabelaStatus.getTuplas();

    std::cout << "(testaTabelaStatus) Iterando sobre as tuplas inseridas..." << std::endl;
    for (std::vector<TuplaStatus*>::iterator it = tuplas.begin();
         it != tuplas.end(); ++it)
    {
        std::cout << "(testaTabelaStatus) Territorio: " << (*it)->getTerritorio() << "..." << std::endl;
        std::cout << "(testaTabelaStatus) Jogador:    " << (*it)->getJogador()    << "..." << std::endl;
        std::cout << "(testaTabelaStatus) Exercitos:  " << (*it)->getExercitos()  << "..." << std::endl;
    }
}

void
todosOsTestes()
{

    std::cout << "(main) Iniciando o WERd..." << std::endl;

    testaJogadores();
    testaTerritorios();
    testaExercitos();
    testaTabelaStatus();

    std::cout << "(main) Finalizando o WERd..." << std::endl;
}
