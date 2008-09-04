#include "Wer.h"
#include <list>
#include <algorithm>
#include <vector>


Wer::Wer()
{

}

void
Wer::jogo()
{
	unsigned short int
	i;

	std::list<Jogador*>
	listaJogadores;

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

void
Wer::atacar( Territorio* _territorioOrigem, Territorio* _territorioDestino )
{
	std::list<unsigned short int>
	dadosAtaque;

	std::list<unsigned short int>
	dadosDefesa;
		
	unsigned short int
	exercitosOrigem;

	unsigned short int
	exercitosDestino;

	unsigned short int
	ataque;

	unsigned short int
	defesa;

	exercitosOrigem = _territorioOrigem->getExercitos();
	exercitosDestino = _territorioDestino->getExercitos();

	if ( _territorioOrigem->pertenceA(controlador.getJogadorAtual())       &&
		 _territorioOrigem->fazFronteiraCom(_territorioDestino->getNome()) &&
		 _territorioOrigem->getExercitos() > 1                             &&
		 !(_territorioDestino->pertenceA( controlador.getJogadorAtual() ))  )
	{
		if( exercitosOrigem >= 4 )
		{
			dadosAtaque.push_back( this->rolarDado() );
		}
		if( exercitosOrigem >=3 )
		{
			dadosAtaque.push_back( this->rolarDado() );
		}
		if( exercitosOrigem >=2 )
		{
			dadosAtaque.push_back( this->rolarDado() );
		}if( exercitosOrigem >= 3 )
		{
			dadosDefesa.push_back( this->rolarDado() );
		}
		if( exercitosOrigem >=2 )
		{
			dadosDefesa.push_back( this->rolarDado() );
		}
		if( exercitosOrigem >=1 )
		{
			dadosDefesa.push_back( this->rolarDado() );
		}
		dadosAtaque.sort();
		dadosDefesa.sort();
		while( !dadosAtaque.empty() )
		{
			if( !dadosDefesa.empty() )
			{
				ataque = *(dadosAtaque.rbegin());
				dadosAtaque.pop_back();
				defesa = *(dadosDefesa.rbegin());
				dadosDefesa.pop_back();

				if( ataque > defesa )
				{
					if( exercitosDestino == 1 )
					{
						--exercitosOrigem;
						_territorioOrigem->setPossuidor( controlador.getJogadorAtual() );
					}
					else
					{
						--exercitosDestino;
					}
				}
				else
				{
					--exercitosDestino;
				}
			}
		}

		_territorioOrigem->setExercitos( exercitosOrigem );
		_territorioDestino->setExercitos( exercitosDestino );

	}
}

void
Wer::moverExercitos(Territorio* _territorioOrigem, Territorio* _territorioDestino, unsigned short int exercitosMovimentados)
{
	unsigned short int
	exercitosOrigem = _territorioOrigem->getExercitos();

	unsigned short int
	exercitosDestino = _territorioDestino->getExercitos();

	if ( _territorioOrigem->fazFronteiraCom(_territorioDestino->getNome()) &&
		 _territorioOrigem->pertenceA( controlador.getJogadorAtual() )     &&
		 _territorioDestino->pertenceA( controlador.getJogadorAtual() )    &&
		 (exercitosMovimentados < exercitosOrigem) )
	{
		_territorioOrigem->setExercitos( exercitosOrigem-exercitosMovimentados );
		_territorioDestino->setExercitos( exercitosDestino+exercitosMovimentados );
	}
}

unsigned short int
Wer::rolarDado()
{
	return dado.embaralha();
}
