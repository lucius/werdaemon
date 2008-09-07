#include "Wer.h"

#include <algorithm>
#include <list>
#include <vector>


Wer::Wer()
{

}

Wer::~Wer()
{

}

void
Wer::atacar( Territorio* _territorioOrigem, Territorio* _territorioDestino )
{
    unsigned short int
    ataque;

    unsigned short int
    defesa;

    std::list<unsigned short int>
    dadosAtaque;

    std::list<unsigned short int>
    dadosDefesa;

    unsigned short int
    exercitosDestino;

    unsigned short int
    exercitosOrigem;


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
                std::cout << "(Wer::atacar) Dado de Ataque: " << ataque << std::endl;
                std::cout << "(Wer::atacar) Dado de Defesa: " << defesa << std::endl;

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

void
Wer::distribuirTerritorios()
{
    unsigned short int
    i;

    std::list<Territorio*>
    listaTerritorios;

    Territorio*
    _territorio;

    std::vector<Territorio*>
    vetorTerritorios;

    listaTerritorios = controlador.getListaTerritorios();

    while ( !listaTerritorios.empty() )
    {
        _territorio = *(listaTerritorios.begin());
        vetorTerritorios.push_back( _territorio );
        listaTerritorios.pop_front();
    }
    std::random_shuffle( vetorTerritorios.begin(), vetorTerritorios.end() );

    while( !*(vetorTerritorios.end()) )
    {
        _territorio = vetorTerritorios[i];
        i++;
        _territorio->setPossuidor( controlador.getJogadorAtual() );
        controlador.getProximoJogador();
        std::cout << "boga" << std::endl;
    }
}

void
Wer::fimDoJogo()
{

}

unsigned short int
Wer::getQuantidadeExercitos()
{
	return quantidadeExercitos;
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
Wer::moverExercitos(Territorio* _territorioOrigem, Territorio* _territorioDestino, unsigned short int exercitosMovimentados)
{
	unsigned short int
	exercitosDestino = _territorioDestino->getExercitos();

	unsigned short int
    exercitosOrigem = _territorioOrigem->getExercitos();

	if ( _territorioOrigem->fazFronteiraCom(_territorioDestino->getNome()) &&
		 _territorioOrigem->pertenceA( controlador.getJogadorAtual() )     &&
		 _territorioDestino->pertenceA( controlador.getJogadorAtual() )    &&
		 (exercitosMovimentados < exercitosOrigem) )
	{
		_territorioOrigem->setExercitos( exercitosOrigem-exercitosMovimentados );
		_territorioDestino->setExercitos( exercitosDestino+exercitosMovimentados );
	}
}

bool
Wer::objetivoCumprido()
{
    std::list<Territorio*>
    listaTerritorios;

    unsigned short int
    quantidadeTerritorios = 0;

    unsigned short int
    quantidadeTerritoriosJogador;

    Territorio*
    _territorio;

    listaTerritorios = controlador.getListaTerritorios();
    quantidadeTerritoriosJogador = listaTerritorios.size();

    while ( !listaTerritorios.empty() )
    {
        _territorio = *(listaTerritorios.begin());
        listaTerritorios.pop_front();
        if ( _territorio->pertenceA( controlador.getJogadorAtual() ) )
        {
            quantidadeTerritorios++;
        }
    }

    if( quantidadeTerritorios != quantidadeTerritoriosJogador )
    {
        return false;
    }

    return true;
}

unsigned short int
Wer::rolarDado()
{
	return dado.embaralha();
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
