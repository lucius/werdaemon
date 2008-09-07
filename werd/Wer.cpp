#include "Wer.h"

#include <algorithm>
#include <list>
#include <vector>


Wer::Wer()
{
    //adicionar x jogadores
    std::cout << "(Wer::Wer) Adicionando jogadores..." << std::endl;
    Jogador
    *Bode = controlador.novoJogador("Bode"),
    *Cido = controlador.novoJogador("Cido"),
    *Lucius = controlador.novoJogador("Lucius");

    std::cout << "(Wer::Wer) Obtendo primeiro jogador..." << std::endl;
    std::cout << "(Wer::Wer) Jogador escolhido: '" << controlador.getProximoJogador()->getNick() << "'..." << std::endl;

    //adicionar territorios e fronteiras
   std::cout << "(Wer::Wer) Adicionando territorios..." << std::endl;
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

   std::cout << "(Wer::Wer) Adicionando fronteiras..." << std::endl;
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

    std::cout << "(Wer::atacar) Territorio de Origem: " << std::cout << _territorioOrigem->getNome() << std::endl;
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
	std::cout << "(Wer::contagemExercitos) " << std::cout << quantidadeExercitos;
	std::cout << " territorios pertencentes à: " << std::cout << controlador.getJogadorAtual()->getNick() << std::endl;

	this->quantidadeExercitos = this->quantidadeExercitos/2;

	if( this->quantidadeExercitos < 3 )
	{
	    this->quantidadeExercitos = 3;
	}
	std::cout << "(Wer::contagemExercitos) " << std::cout << this->quantidadeExercitos;
	std::cout << " exércitos disponiveis para distribuição..." << std::endl;
}

void
Wer::distribuirTerritorios()
{
    unsigned short int
    i = 0;

    std::list<Territorio*>
    listaTerritorios;

    Jogador*
    _jogador;

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

        std::cout << "(Wer::distribuiTerritorios) Seleciona o territorio: " << std::cout << _territorio->getNome() << std::endl;
    }

    std::cout << "(Wer::distribuiTerritorios) Randomiza os territorios para serem distribuidos..." << std::endl;
    std::random_shuffle( vetorTerritorios.begin(), vetorTerritorios.end() );

    std::cout << "(Wer::distribuiTerritorios) Distribuir territorios..." << std::endl;
    while( i < vetorTerritorios.size() )
    {
        _jogador = controlador.getJogadorAtual();
        std::cout << "(Wer::distribuirTerritorios) Jogador atual: " << std::cout << _jogador->getNick() << std::endl;

        _territorio = vetorTerritorios[i];
        i++;
        _territorio->setPossuidor( _jogador );
        controlador.getProximoJogador();
    }
    std::cout << "(Wer::distribuiTerritorios) Termino da distribuição dos territorios..." << std::endl;
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

    /*
    while( !this->objetivoCumprido() )
    {
        this->turno();
        controlador.getProximoJogador();
    }

    this->fimDoJogo();
    */

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
