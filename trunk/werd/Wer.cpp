#include "Wer.h"
#include <list>
#include <algorithm>
#include <vector>

Wer::Wer()
{
	Controlador
	controlador;
}

void
Wer::jogo()
{
	unsigned short int
	i;

	listaJogadores = controlador.getListaJogadores();

	this->distribuirTerritorios();

	for( i=1; i<=listaJogadores.size(); i++ )
	{
		this->contagemExercitos();
		// @ TODO xxxxxxxxxxx
		//this->setExercitosNoMapa();
		controlador.getProximoJogador();
	}

	while( !this->objetivoCumprido() )
	{
		this->turno();
		controlador.getProximoJogador();
	}

	this->fimDoJogo();

}

void
Wer::distribuirTerritorios()
{
	unsigned short int
	i;

	std::list<Territorio*>
	listaTerritorios;

	std::vector<Territorio*>
	vectorTerritorios;

	Territorio*
	_territorio;

	listaTerritorios = controlador.getListaTerritorios();

	while ( !listaTerritorios.empty() )
	{
		_territorio = *(listaTerritorios.begin());
		vectorTerritorios.push_back( _territorio );
		listaTerritorios.pop_front();
	}
	std::random_shuffle( vectorTerritorios.begin(), vectorTerritorios.end() );

	while( !*(vectorTerritorios.end()) )
	{
		_territorio = vectorTerritorios[i];
		i++;
		_territorio->setPossuidor( controlador.getJogadorAtual() );
		controlador.getProximoJogador();
	}
}

void
Wer::contagemExercitos()
{
	std::list<Territorio*>
	listaTerritorios;

	Territorio*
	_territorio;

	this->quantidadeExercitos = 0;
	listaTerritorios = controlador.getListaTerritorios();
	while ( !listaTerritorios.empty() )
	{
		_territorio = *(listaTerritorios.begin());
		listaTerritorios.pop_front();
		if ( _territorio->pertenceA( controlador.getJogadorAtual() ) )
		{
			this->quantidadeExercitos++;
		}
	}

	quantidadeExercitos = quantidadeExercitos/2;
}

unsigned short int
Wer::getQuantidadeExercitos()
{
	return quantidadeExercitos;
}

bool
Wer::objetivoCumprido()
{
	return true; 
}

void
Wer::turno()
{
	this->contagemExercitos();
	// @ TODO xxxxxxxxxxx
	//this->setExercitosNoMapa();
	//this->atacar( controlador.getTerritorioOrigem(), controlador.getTerritorioDestino() );
	//this->moverExercitos( controlador.getTerritorioOrigem(), controlador.getTerritorioDestino(), controlador.getExercitosMovidos() );
}

void
Wer::fimDoJogo()
{

}
/*
void
Wer::atacar( Territorio* _territorioOrigem, Territorio _territorioDestino )
{
	unsigned short int
	exercitosOrigem;

	unsigned short int
	exercitosDestino;

	exercitosOrigem = _territorioOrigem.getExercitos();
	exercitosDestino = _territorioDestino.getExercitos();
}

void
Wer::moverExercitos()
{

}
*/