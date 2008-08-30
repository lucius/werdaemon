#include "Controlador.h"
#include <iostream>
#include <string>


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

unsigned short int
Controlador::novoJogador(std::string _nick)
{
    std::cout << "(Jogador::novoJogador) Alocando novo jogador..." << std::endl;
    Jogador*
    novoJogador = new Jogador();

    novoJogador->setId(this->jogadores.size() + 1);
    novoJogador->setNick(_nick);
    std::cout << "(Jogador::novoJogador) Jogador '" << _nick << "' alocado (id:" << novoJogador->getId() << ")..." << std::endl;

    this->jogadores.push_back(novoJogador);

    return novoJogador->getId();
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
