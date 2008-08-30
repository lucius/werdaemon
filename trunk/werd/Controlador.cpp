#include "Controlador.h"
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

// TODO testar
Jogador*
Controlador::getJogador(std::string _nick)
{
    // Os Jogadores não são indexados por nome, pois serão no máximo 6.
    for (std::list<Jogador*>::iterator it = jogadores.begin(); it != jogadores.end(); ++it)
    {
        if ((*it)->getNick() == _nick)
        {
            return *it;
        }
    }

    return 0;
}

// TODO testar
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

// TODO testar
Territorio*
Controlador::getTerritorio(std::string _territorio)
{
	return (this->territorios.find(_territorio))->second;
}

// TODO testar
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

    for (std::list<Territorio*>::iterator it = listaTerritorios.begin();
         it != listaTerritorios.end(); ++it)
    {
        tabelaStatus.setTupla((*it)->getNome(), (*it)->getPossuidor()->getNick(), (*it)->getExercitos());
    }
}
