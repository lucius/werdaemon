#include "testes.h"

#include <assert.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Controlador.h"
#include "TabelaStatus.h"
#include "TuplaStatus.h"

#include "Wer.h"


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

    std::cout << "(testaJogadores) Obtendo jogadores pelo nick..." << std::endl;
    std::cout << "(testaJogadores) '" << controlador.getJogador("Bode")->getNick()   << "'" << std::endl;
    std::cout << "(testaJogadores) '" << controlador.getJogador("Cido")->getNick()   << "'" << std::endl;
    std::cout << "(testaJogadores) '" << controlador.getJogador("Lucius")->getNick() << "'" << std::endl;

    std::cout << "(testaJogadores) Obtendo lista de jogadores..." << std::endl;
    std::list<Jogador*>
    jogadores = controlador.getListaJogadores();

    std::cout << "(testaJogadores) Iterando sobre a lista de jogadores que foi obtida..." << std::endl;
    for (std::list<Jogador*>::iterator it = jogadores.begin(); it != jogadores.end(); ++it)
    {
        std::cout << "(testaJogadores) '" << (*it)->getNick() << "' encontrado..." << std::endl;
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

    std::cout << "(testaTerritorios) Obtendo territ�rio por nome e adicionando fronteiras..." << std::endl;
    controlador.getTerritorio("Computacao")->adicionaFronteiraCom(controlador.getTerritorio("Economia"));

    std::cout << "(testaTerritorios) Checando fronteiras..." << std::endl;
    Computacao->fazFronteiraCom("Fisica");
    Computacao->fazFronteiraCom("Matematica");
    Computacao->fazFronteiraCom("Economia");
    Computacao->fazFronteiraCom("Biologia");
    Computacao->fazFronteiraCom("Piramide Egipcia");

    std::cout << "(testaTerritorios) Obtendo lista com todos os territ�rios..." << std::endl;
    std::list<Territorio*>
    territorios = controlador.getListaTerritorios();

    std::cout << "(testaTerritorios) Iterando sobre a lista com todos os territ�rios obtidos..." << std::endl;
    for (std::list<Territorio*>::iterator it = territorios.begin(); it != territorios.end(); ++it)
    {
        std::cout << "(testaTerritorios) '" << (*it)->getNome() << "' encontrado..." << std::endl;
    }
}

void
testaTabelaStatus()
{
    TabelaStatus
    tabelaStatus;

    tabelaStatus.setTupla("Computacao", "Bode",   10);
    tabelaStatus.setTupla("Matematica", "Cido",   15);
    tabelaStatus.setTupla("Fisica",     "Lucius", 24);

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
testeRelacaoJogadoresTerritorios()
{
    Controlador
    controlador;

    Jogador
    *Bode   = controlador.novoJogador("Bode"),
    *Cido   = controlador.novoJogador("Cido"),
    *Lucius = controlador.novoJogador("Lucius");

    Territorio
    *Computacao = controlador.novoTerritorio("Computacao"),
    *Fisica     = controlador.novoTerritorio("Fisica"),
    *Matematica = controlador.novoTerritorio("Matematica"),
    *Economia   = controlador.novoTerritorio("Economia"),
    *Biologia   = controlador.novoTerritorio("Biologia");

    Bode->ganhaTerritorio(Computacao);
    Cido->ganhaTerritorio(Fisica);
    Lucius->ganhaTerritorio(Matematica);

    std::cout << "(testeRelacaoJogadoresTerritorios) Atualizando a tabela de status do jogo." << std::endl;
    controlador.atualizaTabelaStatus();

    Computacao->setPossuidor(Cido);
    std::cout << "(testeRelacaoJogadoresTerritorios) " << Computacao->getNome() << " � possu�do por: " << Computacao->getPossuidor()->getNick() << std::endl;

    std::cout << "(testeRelacaoJogadoresTerritorios) Atualizando a tabela de status do jogo." << std::endl;
    controlador.atualizaTabelaStatus();

    Economia->setPossuidor(Bode);
    Biologia->setPossuidor(Cido);
    Computacao->setPossuidor(Lucius);
    std::cout << "(testeRelacaoJogadoresTerritorios) " << Economia->getNome()   << " � possu�do por: " << Economia->getPossuidor()->getNick()   << std::endl;
    std::cout << "(testeRelacaoJogadoresTerritorios) " << Biologia->getNome()   << " � possu�do por: " << Biologia->getPossuidor()->getNick()   << std::endl;
    std::cout << "(testeRelacaoJogadoresTerritorios) " << Computacao->getNome() << " � possu�do por: " << Computacao->getPossuidor()->getNick() << std::endl;

    std::cout << "(testeRelacaoJogadoresTerritorios) Atualizando a tabela de status do jogo." << std::endl;
    controlador.atualizaTabelaStatus();
}

void
todosOsTestes()
{

    std::cout << "(todosOsTestes) Iniciando o WERd..." << std::endl;

    testaJogadores();
    testaTerritorios();
    testaTabelaStatus();
    testeRelacaoJogadoresTerritorios();

    std::cout << "(todosOsTestes) Finalizando o WERd..." << std::endl;
}

void
testaJogo()
{
    Wer
    wer;

    Controlador
    controlador;

    //adicionar x jogadores
    std::cout << "(testaJogo) Adicionando jogadores..." << std::endl;
    Jogador
    *Bode = controlador.novoJogador("Bode"),
    *Cido = controlador.novoJogador("Cido"),
    *Lucius = controlador.novoJogador("Lucius");

    std::cout << "(testaJogo) Obtendo primeiro jogador..." << std::endl;
    std::cout << "(testaJogo) Jogador escolhido: '" << controlador.getProximoJogador()->getNick() << "'..." << std::endl;

    //adicionar territorios e fronteiras
   std::cout << "(testaJogo) Adicionando territorios..." << std::endl;
   Territorio
   *A = controlador.novoTerritorio("A"),
   *B = controlador.novoTerritorio("B"),
   *C = controlador.novoTerritorio("C"),
   *D = controlador.novoTerritorio("D"),
   *E = controlador.novoTerritorio("E"),
   *F = controlador.novoTerritorio("F"),
   *G = controlador.novoTerritorio("G"),
   *H = controlador.novoTerritorio("H"),
   *I = controlador.novoTerritorio("I"),
   *J = controlador.novoTerritorio("J");

   std::cout << "(testaJogo) Adicionando fronteiras..." << std::endl;
   A->adicionaFronteiraCom(B);
   A->adicionaFronteiraCom(C);
   A->adicionaFronteiraCom(D);
   A->adicionaFronteiraCom(F);
   A->adicionaFronteiraCom(J);
   B->adicionaFronteiraCom(A);
   B->adicionaFronteiraCom(C);
   C->adicionaFronteiraCom(A);
   C->adicionaFronteiraCom(B);
   C->adicionaFronteiraCom(D);
   C->adicionaFronteiraCom(E);
   C->adicionaFronteiraCom(F);
   D->adicionaFronteiraCom(A);
   D->adicionaFronteiraCom(C);
   D->adicionaFronteiraCom(F);
   E->adicionaFronteiraCom(C);
   E->adicionaFronteiraCom(F);
   F->adicionaFronteiraCom(A);
   F->adicionaFronteiraCom(C);
   F->adicionaFronteiraCom(D);
   F->adicionaFronteiraCom(E);
   F->adicionaFronteiraCom(I);
   F->adicionaFronteiraCom(J);
   G->adicionaFronteiraCom(C);
   G->adicionaFronteiraCom(H);
   H->adicionaFronteiraCom(G);
   H->adicionaFronteiraCom(I);
   H->adicionaFronteiraCom(J);
   I->adicionaFronteiraCom(F);
   I->adicionaFronteiraCom(H);
   J->adicionaFronteiraCom(A);
   J->adicionaFronteiraCom(F);
   J->adicionaFronteiraCom(H);

   std::cout << "(testaJogo) Distribuindo territorios aos jogadores..." << std::endl;
   //wer.distribuirTerritorios();
   A->setPossuidor(Bode);
   B->setPossuidor(Cido);
   C->setPossuidor(Lucius);
   D->setPossuidor(Bode);
   E->setPossuidor(Cido);
   F->setPossuidor(Lucius);
   G->setPossuidor(Bode);
   H->setPossuidor(Cido);
   I->setPossuidor(Lucius);
   J->setPossuidor(Bode);

   std::list<Territorio*>
   listaTerritorios;

   Territorio*
   _territorio;

   listaTerritorios = controlador.getListaTerritorios();
   while( !listaTerritorios.empty() )
   {
       _territorio = *(listaTerritorios.begin());
       listaTerritorios.pop_front();

       std::cout << "(testaJogo) " << _territorio->getNome() << " pertence a: " << (_territorio->getPossuidor())->getNick() << std::endl;
   }

   std::cout << "(testaJogo) Quantidade de exercitos no territorio A: " << A->getExercitos() << std::endl;
   A->setExercitos( 5 );
   std::cout << "(testaJogo) Quantidade de exercitos no territorio A: " << A->getExercitos() << std::endl;

   //wer.atacar( A, B );
   std::cout << "(testaJogo) Quantidade de exercitos no territorio A: " << A->getExercitos() << std::endl;
   std::cout << "(testaJogo) Quantidade de exercitos no territorio B: " << B->getExercitos() << std::endl;

}
