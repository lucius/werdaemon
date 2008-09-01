#include "Controlador.h"
#include "TuplaStatus.h"
#include <iostream>


Controlador::Controlador()
{
    std::cout << "(Controlador::Controlador) Instanciando o 'Controlador'..." << std::endl;

    std::cout << "(Controlador::Controlador) Atribuindo ponteiro inicial a 'jogadores'..." << std::endl;
    this->jogador_atual = this->jogadores.begin();
}

Controlador::~Controlador()
{
    std::cout << "(Controlador::~Controlador) Iterando sobre 'jogadores' para desalocacao..." << std::endl;
    for (std::list<Jogador*>::iterator it = this->jogadores.begin();
         it != this->jogadores.end(); ++it)
    {
        std::cout << "(Controlador::~Controlador) Desalocando o jogador '" << (*it)->getNick() << "'..." << std::endl;
        delete *it;
    }


    std::cout << "(Controlador::~Controlador) Iterando sobre 'territorios' para desalocacao..." << std::endl;
    for (std::map<std::string, Territorio*>::iterator it = this->territorios.begin();
         it != this->territorios.end(); ++it)
    {
        std::cout << "(Controlador::~Controlador) Desalocando o territorio '" << it->first << "'..." << std::endl;
        delete it->second;
    }
}

Jogador*
Controlador::novoJogador(std::string _nick)
{
    std::cout << "(Jogador::novoJogador) Alocando novo jogador..." << std::endl;
    Jogador*
    novoJogador = new Jogador();

    novoJogador->setNick(_nick);
    std::cout << "(Jogador::novoJogador) Jogador '" << _nick << "' alocado..." << std::endl;

    this->jogadores.push_back(novoJogador);

    return novoJogador;
}

Jogador*
Controlador::getJogadorAtual()
{
    return *(this->jogador_atual);
}

Jogador*
Controlador::getProximoJogador()
{
    std::cout << "(Controlador::getProximoJogador) Obtendo proximo jogador..." << std::endl;
    ++(this->jogador_atual);

    if (this->jogador_atual == this->jogadores.end())
    {
        std::cout << "(Controlador::getProximoJogador) Fim da lista atingido, escolhendo o jogador inicial da lista..." << std::endl;
        this->jogador_atual = this->jogadores.begin();
    }

    return *(this->jogador_atual);
}

Jogador*
Controlador::getJogador(std::string _nick)
{
    // Os Jogadores não são indexados por nome, pois serão no máximo 6.
    std::cout << "(Controlador::getJogador) Buscando pelo jogador " << _nick << std::endl;
    for (std::list<Jogador*>::iterator it = this->jogadores.begin(); it != this->jogadores.end(); ++it)
    {
        if ((*it)->getNick() == _nick)
        {
            std::cout << "(Controlador::getJogador) '" << _nick << "' encontrado..." << std::endl;
            return *it;
        }
    }

    return 0;
}

std::list<Jogador*>
Controlador::getListaJogadores()
{
    return this->jogadores;
}

Territorio*
Controlador::novoTerritorio(std::string _nomeTerritorio)
{
    std::cout << "(Jogador::novoTerritorio) Alocando novo territorio..." << std::endl;
    Territorio*
    novoTerritorio = new Territorio();

    novoTerritorio->setNome(_nomeTerritorio);

    this->territorios[_nomeTerritorio] = novoTerritorio;

    std::cout << "(Jogador::novoTerritorio) Territorio '" << _nomeTerritorio << "' alocado..." << std::endl;

    return novoTerritorio;
}

Territorio*
Controlador::getTerritorio(std::string _territorio)
{
	return (this->territorios.find(_territorio))->second;
}

std::list<Territorio*>
Controlador::getListaTerritorios()
{
    std::list<Territorio*>
    listaTerritorios;

    for (std::map<std::string, Territorio*>::iterator it = this->territorios.begin();
         it != this->territorios.end(); ++it)
    {
        listaTerritorios.push_back(it->second);
    }

    return listaTerritorios;
}

// TODO testar
void
Controlador::atualizaTabelaStatus()
{
    std::list<Territorio*>
    listaTerritorios = this->getListaTerritorios();

    std::vector<TuplaStatus*>
    tuplas = this->tabelaStatus.getTuplas();

    unsigned short int
    i = 0;

    std::cout << "(Controlador::atualizaTabelaStatus) Tabela de status antes da atualizacao..." << std::endl;
    std::cout << "(Controlador::atualizaTabelaStatus) Território | Jogador | Exércitos..." << std::endl;

    if (tuplas.empty())
    {
        std::cout << "(Controlador::atualizaTabelaStatus) Tabela vazia..." << std::endl;
    }
    else
    {
        for (std::vector<TuplaStatus*>::iterator it = tuplas.begin(); it != tuplas.end(); ++it)
        {
            std::cout << "(Controlador::atualizaTabelaStatus) [" << i++ << "]: "
                      << (*it)->getTerritorio() << " | "
                      << (*it)->getJogador()    << " | "
                      << (*it)->getExercitos()  << std::endl;
        }
    }

    for (std::list<Territorio*>::iterator it = listaTerritorios.begin();
         it != listaTerritorios.end(); ++it)
    {
        if (NULL != (*it)->getPossuidor())
        {
            this->tabelaStatus.setTupla((*it)->getNome(), (*it)->getPossuidor()->getNick(), (*it)->getExercitos());
        }
        else
        {
            this->tabelaStatus.setTupla((*it)->getNome(), "", (*it)->getExercitos());
        }
    }

    i = 0;

    std::cout << "(Controlador::atualizaTabelaStatus) Tabela de status depois da atualizacao..." << std::endl;
    std::cout << "(Controlador::atualizaTabelaStatus) Território | Jogador | Exércitos..." << std::endl;
    for (std::vector<TuplaStatus*>::iterator it = tuplas.begin(); it != tuplas.end(); ++it)
    {
        std::cout << "(Controlador::atualizaTabelaStatus) [" << i++ << "]: "
                  << (*it)->getTerritorio() << " | "
                  << (*it)->getJogador()    << " | "
                  << (*it)->getExercitos()  << std::endl;
    }
}
