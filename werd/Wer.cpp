#include "Wer.h"

#include <algorithm>
#include <assert.h>
#include <list>
#include <vector>
#include "Random.h"


Wer::Wer()
{

}

Wer::~Wer()
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
    ataque;

    unsigned short int
    defesa;

    unsigned short int
    exercitosDestino;

    unsigned short int
    exercitosOrigem;

    unsigned short int
    _dado;


    exercitosOrigem = _territorioOrigem->getExercitos();
    exercitosDestino = _territorioDestino->getExercitos();

    std::cout << "(Wer::atacar) Territorio de Origem: " << _territorioOrigem->getNome() << std::endl;
    std::cout << "(Wer::atacar) Territorio de Destino: " << _territorioDestino->getNome() << std::endl;

    if( _territorioOrigem->pertenceA(controlador.getJogadorAtual()) )
    {
    	std::cout << "(Wer::atacar) " << _territorioOrigem->getNome() << " pertence a " << (_territorioOrigem->getPossuidor())->getNick() << "." << std::endl; 

    	if( _territorioOrigem->fazFronteiraCom(_territorioDestino->getNome()) )
    	{
    		std::cout << "(Wer::atacar) " << _territorioOrigem->getNome() << " faz fronteira com " << _territorioDestino->getNome() << std::endl;

    		if( _territorioOrigem->getExercitos() > 1 )
    		{
    			std::cout << "(Wer::atacar) " << _territorioOrigem->getNome() << " possui " << _territorioOrigem->getExercitos() << " exercitos... " << std::endl;

    			if( !(_territorioDestino->pertenceA(controlador.getJogadorAtual())) )
    			{
    				std::cout << "(Wer::atacar) " << _territorioDestino->getNome() << " pertence a " << (_territorioDestino->getPossuidor())->getNick() << std::endl;

    				if( exercitosOrigem >= 2 )
			        {
    					_dado = this->rolarDado();
			            dadosAtaque.push_back( _dado );
			            std::cout << "(Wer::atacar) Primeiro dado de ataque: " << _dado << std::endl;
			        }

			        if( exercitosOrigem >= 3 )
			        {
    					_dado = this->rolarDado();
			            dadosAtaque.push_back( _dado );

			            std::cout << "(Wer::atacar) Segundo dado de ataque: " << _dado << std::endl;
			        }

			        if( exercitosOrigem >= 4 )
			        {
    					_dado = this->rolarDado();
			            dadosAtaque.push_back( _dado );
			            std::cout << "(Wer::atacar) Terceiro dado de ataque: " << _dado << std::endl;			        
			        }

			        if( exercitosDestino >= 1 )
			        {
    					_dado = this->rolarDado();
			            dadosDefesa.push_back( _dado );
			            std::cout << "(Wer::atacar) Primeiro dado de defesa: " << _dado << std::endl;
			        }

			        if( exercitosDestino >= 2 )
			        {
    					_dado = this->rolarDado();
			            dadosDefesa.push_back( _dado );
			            std::cout << "(Wer::atacar) Segundo dado de defesa: " << _dado << std::endl;
			        }

			        if( exercitosDestino >= 3 )
			        {
    					_dado = this->rolarDado();
			            dadosDefesa.push_back( _dado );
			            std::cout << "(Wer::atacar) Terceiro dado de defesa: " << _dado << std::endl;
			        }

			        dadosAtaque.sort();
			        dadosDefesa.sort();
			        std::cout << "(Wer::atacar) Dados ordenados..." << std::endl;

			        while( !dadosAtaque.empty() && !dadosDefesa.empty() )
			        {
			        	std::cout << "(Wer::atacar) Comparando dados..." << std::endl;
			            ataque = *(dadosAtaque.rbegin());
			            dadosAtaque.pop_back();

			            defesa = *(dadosDefesa.rbegin());
			            dadosDefesa.pop_back();

			            std::cout << "(Wer::atacar) Dado de Ataque: " << ataque << std::endl;
			            std::cout << "(Wer::atacar) Dado de Defesa: " << defesa << std::endl;

			            if( ataque > defesa )
			            {
			            	std::cout << "(Wer::atacar) Ataque ganha..." << std::endl;

			                if( exercitosDestino == 1 )
			                {
			                    _territorioOrigem->setExercitos( --exercitosOrigem );
			                    _territorioDestino->setPossuidor( controlador.getJogadorAtual() );
			                }
			                else
			                {
			                    _territorioDestino->setExercitos( --exercitosDestino );
			                }
			            }
			            else
			            {
			            	std::cout << "(Wer::atacar) Defesa ganha..." << std::endl;

			                _territorioOrigem->setExercitos( --exercitosOrigem );
			            }

			            std::cout << "(Wer::atacar) Quantidade de exercitos no territorio de origem: " << _territorioOrigem->getExercitos() << std::endl;
			            std::cout << "(Wer::atacar) Quantidade de exercitos no territorio de destino: " << _territorioDestino->getExercitos() << std::endl;
			        }

    			}
    			else
    			{
    				std::cout << "(Wer::atacar) " << _territorioDestino->getNome() << " pertence a " << (_territorioDestino->getPossuidor())->getNick() << std::endl;
    				std::cout << "(Wer::atacar) Não é possivel atacar um territorio próprio..." << std::endl;
    			}
    		}
    		else
    		{
    			std::cout << "(Wer::atacar) Quantidade de exercitos insuficientes... " << _territorioOrigem->getExercitos() << " exercito..." << std::endl;
    		}
    	}
    	else
    	{
    		std::cout << "(Wer::atacar) " << _territorioOrigem->getNome() << " não faz fronteira com " << _territorioDestino->getNome() << std::endl;
    	}
    }
    else
    {
    	std::cout << "(Wer::atacar) " << _territorioOrigem->getNome() << " pertence a " << (_territorioOrigem->getPossuidor())->getNick() << "." << std::endl;
    }
}

void
Wer::contagemExercitos()
{
	this->quantidadeExercitos = this->contagemTerritorios()/2;

	if( this->quantidadeExercitos < 3 )
	{
	    this->quantidadeExercitos = 3;
	}
	std::cout << "(Wer::contagemExercitos) " << this->quantidadeExercitos << " exércitos disponiveis para distribuição..." << std::endl;
}

unsigned short int
Wer::contagemTerritorios()
{
	std::list<Territorio*>
	listaTerritorios;

	Territorio*
	_territorio;

	unsigned short int
	quantidadeTerritorios = 0;


	listaTerritorios = controlador.getListaTerritorios();

	while ( !listaTerritorios.empty() )
	{
		_territorio = *(listaTerritorios.begin());
		listaTerritorios.pop_front();

		if ( _territorio->pertenceA( controlador.getJogadorAtual() ) )
		{
			quantidadeTerritorios++;
		}
	}
	std::cout << "(Wer::contagemTerritorios) " << quantidadeTerritorios << " territorios pertencentes à: " << controlador.getJogadorAtual()->getNick() << std::endl;

	return quantidadeTerritorios;
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

    // @ TODO QUANDO TRABALHAR COM 42 TERRITORIOS, RANDMAX DEVE SER IGUAL A 41
    #define RANDMAX 9

    Random
    funcaoGeradora;

    listaTerritorios = controlador.getListaTerritorios();

    while ( !listaTerritorios.empty() )
    {
        _territorio = *(listaTerritorios.begin());
        vetorTerritorios.push_back( _territorio );
        listaTerritorios.pop_front();

        std::cout << "(Wer::distribuiTerritorios) Seleciona o territorio: " << _territorio->getNome() << std::endl;
    }

    std::cout << "(Wer::distribuiTerritorios) Randomiza os territorios para serem distribuidos..." << std::endl;
    std::random_shuffle( vetorTerritorios.begin(), vetorTerritorios.end(), funcaoGeradora );

    std::cout << "(Wer::distribuiTerritorios) Distribuir territorios aos jogadores..." << std::endl;
    while( i < vetorTerritorios.size() )
    {
        _jogador = controlador.getJogadorAtual();

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
	return this->quantidadeExercitos;
}

void
Wer::jogo()
{
    unsigned short int
    i;

    std::list<Jogador*>
    listaJogadores;

    listaJogadores = controlador.getListaJogadores();

    std::cout << "(Wer::jogo) Distribuir territorios aos jogadores... " << std::endl;
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
    	if( this->contagemTerritorios() != 0 )
    	{
    		this->turno();
    	}
    	else
    	{
    		std::cout << "(Wer::jogo) " << controlador.getJogadorAtual()->getNick() << " foi eliminado do jogo..." << std::endl;
    	}
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

	if( _territorioOrigem->pertenceA(controlador.getJogadorAtual()) )
	{
		std::cout << "(Wer::moverExercitos) " << _territorioOrigem->getNome() << " pertence a " << (_territorioOrigem->getPossuidor())->getNick() << "." << std::endl;

		if( _territorioOrigem->fazFronteiraCom(_territorioDestino->getNome()) )
		{
			std::cout << "(Wer::moverExercitos) " << _territorioOrigem->getNome() << " faz fronteira com " << _territorioDestino->getNome() << std::endl;

			if( _territorioDestino->pertenceA(controlador.getJogadorAtual()) )
			{
				std::cout << "(Wer::moverExercitos) " << _territorioDestino->getNome() << " pertence a " << (_territorioDestino->getPossuidor())->getNick() << "." << std::endl;

				if( (exercitosMovimentados < exercitosOrigem) )
				{
					std::cout << "(Wer::moverExercitos) Movimentando " << exercitosMovimentados << " exercitos, de " << exercitosOrigem << " disponíveis..." << std::endl; 
					_territorioOrigem->setExercitos( exercitosOrigem-exercitosMovimentados );
					_territorioDestino->setExercitos( exercitosDestino+exercitosMovimentados );
				}
				else
				{
					std::cout << "(Wer::moverExercitos) Quantidade de exercitos insuficientes..." << std::endl;
				}
			}
			else
			{
				std::cout << "(Wer::atacar) " << _territorioDestino->getNome() << " pertence a " << (_territorioDestino->getPossuidor())->getNick() << "." << std::endl;
			}
		}
		else
		{
			std::cout << "(Wer::atacar) " << _territorioOrigem->getNome() << " não faz fronteira com " << _territorioDestino->getNome() << std::endl;
		}
	}
	else
	{
		std::cout << "(Wer::atacar) " << _territorioOrigem->getNome() << " pertence a " << (_territorioOrigem->getPossuidor())->getNick() << "." << std::endl;
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

    std::cout << "(Wer::objetivoCumprido) Testar se o objetivo foi cumprido..." << std::endl;
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
    	std::cout << "(Wer::obejtivoCumprido) Objetivo não cumprido..." << std::endl;
        return false;
    }

    std::cout << "(Wer::objetivoCumprido) Objetivo cumprido..." << std::endl;
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

void
Wer::teste()
{
    //adicionar x jogadores
    std::cout << "(Wer::teste) Adicionando jogadores..." << std::endl;

    Jogador
    *Bode = controlador.novoJogador("Bode"),
    *Cido = controlador.novoJogador("Cido"),
    *Lucius = controlador.novoJogador("Lucius");

    std::cout << "(Wer::teste) Jogadores adicionados..." << std::endl;

    std::cout << "(Wer::teste) Obtendo primeiro jogador..." << std::endl;
    std::cout << "(Wer::teste) Jogador escolhido: '" << controlador.getProximoJogador()->getNick() << "'..." << std::endl;

    //adicionar territorios e fronteiras
    std::cout << "(Wer::teste) Adicionando territorios..." << std::endl;

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

    std::cout << "(Wer::teste) Adicionando fronteiras..." << std::endl;
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

    std::cout << "(Wer::teste) Fronteiras adicionadas..." << std::endl;

    this->jogo();

//    std::cout << "(Wer::teste) Testar fornteiras:" << std::endl;
//    (controlador.getTerritorio("A"))->fazFronteiraCom("A");
//    (controlador.getTerritorio("A"))->fazFronteiraCom("B");
//    (controlador.getTerritorio("A"))->fazFronteiraCom("C");
//    (controlador.getTerritorio("A"))->fazFronteiraCom("D");
//    (controlador.getTerritorio("A"))->fazFronteiraCom("E");
//    (controlador.getTerritorio("A"))->fazFronteiraCom("F");
//    (controlador.getTerritorio("A"))->fazFronteiraCom("G");
//    (controlador.getTerritorio("A"))->fazFronteiraCom("H");
//    (controlador.getTerritorio("A"))->fazFronteiraCom("I");
//    (controlador.getTerritorio("A"))->fazFronteiraCom("J");
//    (controlador.getTerritorio("B"))->fazFronteiraCom("A");
//    (controlador.getTerritorio("B"))->fazFronteiraCom("B");
//    (controlador.getTerritorio("B"))->fazFronteiraCom("C");
//    (controlador.getTerritorio("B"))->fazFronteiraCom("D");
//    (controlador.getTerritorio("B"))->fazFronteiraCom("E");
//    (controlador.getTerritorio("B"))->fazFronteiraCom("F");
//    (controlador.getTerritorio("B"))->fazFronteiraCom("G");
//    (controlador.getTerritorio("B"))->fazFronteiraCom("H");
//    (controlador.getTerritorio("B"))->fazFronteiraCom("I");
//    (controlador.getTerritorio("B"))->fazFronteiraCom("J");
//    (controlador.getTerritorio("C"))->fazFronteiraCom("A");
//    (controlador.getTerritorio("C"))->fazFronteiraCom("B");
//    (controlador.getTerritorio("C"))->fazFronteiraCom("C");
//    (controlador.getTerritorio("C"))->fazFronteiraCom("D");
//    (controlador.getTerritorio("C"))->fazFronteiraCom("E");
//    (controlador.getTerritorio("C"))->fazFronteiraCom("F");
//    (controlador.getTerritorio("C"))->fazFronteiraCom("G");
//    (controlador.getTerritorio("C"))->fazFronteiraCom("H");
//    (controlador.getTerritorio("C"))->fazFronteiraCom("I");
//    (controlador.getTerritorio("C"))->fazFronteiraCom("J");
//    (controlador.getTerritorio("D"))->fazFronteiraCom("A");
//    (controlador.getTerritorio("D"))->fazFronteiraCom("B");
//    (controlador.getTerritorio("D"))->fazFronteiraCom("C");
//    (controlador.getTerritorio("D"))->fazFronteiraCom("D");
//    (controlador.getTerritorio("D"))->fazFronteiraCom("E");
//    (controlador.getTerritorio("D"))->fazFronteiraCom("F");
//    (controlador.getTerritorio("D"))->fazFronteiraCom("G");
//    (controlador.getTerritorio("D"))->fazFronteiraCom("H");
//    (controlador.getTerritorio("D"))->fazFronteiraCom("I");
//    (controlador.getTerritorio("D"))->fazFronteiraCom("J");
//    (controlador.getTerritorio("E"))->fazFronteiraCom("A");
//    (controlador.getTerritorio("E"))->fazFronteiraCom("B");
//    (controlador.getTerritorio("E"))->fazFronteiraCom("C");
//    (controlador.getTerritorio("E"))->fazFronteiraCom("D");
//    (controlador.getTerritorio("E"))->fazFronteiraCom("E");
//    (controlador.getTerritorio("E"))->fazFronteiraCom("F");
//    (controlador.getTerritorio("E"))->fazFronteiraCom("G");
//    (controlador.getTerritorio("E"))->fazFronteiraCom("H");
//    (controlador.getTerritorio("E"))->fazFronteiraCom("I");
//    (controlador.getTerritorio("E"))->fazFronteiraCom("J");
//    (controlador.getTerritorio("F"))->fazFronteiraCom("A");
//    (controlador.getTerritorio("F"))->fazFronteiraCom("B");
//    (controlador.getTerritorio("F"))->fazFronteiraCom("C");
//    (controlador.getTerritorio("F"))->fazFronteiraCom("D");
//    (controlador.getTerritorio("F"))->fazFronteiraCom("E");
//    (controlador.getTerritorio("F"))->fazFronteiraCom("F");
//    (controlador.getTerritorio("F"))->fazFronteiraCom("G");
//    (controlador.getTerritorio("F"))->fazFronteiraCom("H");
//    (controlador.getTerritorio("F"))->fazFronteiraCom("I");
//    (controlador.getTerritorio("F"))->fazFronteiraCom("J");
//    (controlador.getTerritorio("G"))->fazFronteiraCom("A");
//    (controlador.getTerritorio("G"))->fazFronteiraCom("B");
//    (controlador.getTerritorio("G"))->fazFronteiraCom("C");
//    (controlador.getTerritorio("G"))->fazFronteiraCom("D");
//    (controlador.getTerritorio("G"))->fazFronteiraCom("E");
//    (controlador.getTerritorio("G"))->fazFronteiraCom("F");
//    (controlador.getTerritorio("G"))->fazFronteiraCom("G");
//    (controlador.getTerritorio("G"))->fazFronteiraCom("H");
//    (controlador.getTerritorio("G"))->fazFronteiraCom("I");
//    (controlador.getTerritorio("G"))->fazFronteiraCom("J");
//    (controlador.getTerritorio("H"))->fazFronteiraCom("A");
//    (controlador.getTerritorio("H"))->fazFronteiraCom("B");
//    (controlador.getTerritorio("H"))->fazFronteiraCom("C");
//    (controlador.getTerritorio("H"))->fazFronteiraCom("D");
//    (controlador.getTerritorio("H"))->fazFronteiraCom("E");
//    (controlador.getTerritorio("H"))->fazFronteiraCom("F");
//    (controlador.getTerritorio("H"))->fazFronteiraCom("G");
//    (controlador.getTerritorio("H"))->fazFronteiraCom("H");
//    (controlador.getTerritorio("H"))->fazFronteiraCom("I");
//    (controlador.getTerritorio("H"))->fazFronteiraCom("J");
//    (controlador.getTerritorio("I"))->fazFronteiraCom("A");
//    (controlador.getTerritorio("I"))->fazFronteiraCom("B");
//    (controlador.getTerritorio("I"))->fazFronteiraCom("C");
//    (controlador.getTerritorio("I"))->fazFronteiraCom("D");
//    (controlador.getTerritorio("I"))->fazFronteiraCom("E");
//    (controlador.getTerritorio("I"))->fazFronteiraCom("F");
//    (controlador.getTerritorio("I"))->fazFronteiraCom("G");
//    (controlador.getTerritorio("I"))->fazFronteiraCom("H");
//    (controlador.getTerritorio("I"))->fazFronteiraCom("I");
//    (controlador.getTerritorio("I"))->fazFronteiraCom("J");
//    (controlador.getTerritorio("J"))->fazFronteiraCom("A");
//    (controlador.getTerritorio("J"))->fazFronteiraCom("B");
//    (controlador.getTerritorio("J"))->fazFronteiraCom("C");
//    (controlador.getTerritorio("J"))->fazFronteiraCom("D");
//    (controlador.getTerritorio("J"))->fazFronteiraCom("E");
//    (controlador.getTerritorio("J"))->fazFronteiraCom("F");
//    (controlador.getTerritorio("J"))->fazFronteiraCom("G");
//    (controlador.getTerritorio("J"))->fazFronteiraCom("H");
//    (controlador.getTerritorio("J"))->fazFronteiraCom("I");
//    (controlador.getTerritorio("J"))->fazFronteiraCom("J");
//
//    std::cout << "(Wer::teste) Termino teste fronteiras... )" << std::endl;

    std::cout << "(Wer::teste) Quantidade de exercitos em A: " << (controlador.getTerritorio("A"))->getExercitos() << std::endl;
    (controlador.getTerritorio("A"))->setExercitos( 10 );
    (controlador.getTerritorio("C"))->setExercitos( 2 );
    std::cout << "(Wer::teste) Quantidade de exercitos em A: " << (controlador.getTerritorio("A"))->getExercitos() << std::endl;
    std::cout << "(Wer::teste) Quantidade de exercitos em C: " << (controlador.getTerritorio("C"))->getExercitos() << std::endl;
    std::cout << "(Wer::teste) Atacar do Territorio A no Territorio C... " << std::endl;

    (controlador.getTerritorio("A"))->setPossuidor(Cido);
    (controlador.getTerritorio("C"))->setPossuidor(Bode);
    (controlador.getTerritorio("F"))->setPossuidor(Cido);
    
    this->atacar( controlador.getTerritorio("A"), controlador.getTerritorio("C") );
    std::cout << "(Wer::teste) Quantidade de exercitos em A: " << (controlador.getTerritorio("A"))->getExercitos() << std::endl;
    std::cout << "(Wer::teste) Quantidade de exercitos em C: " << (controlador.getTerritorio("C"))->getExercitos() << std::endl;

    this->moverExercitos( controlador.getTerritorio("A"), controlador.getTerritorio("F"), 7);
    std::cout << "(Wer::teste) Quantidade de exercitos em A: " << (controlador.getTerritorio("A"))->getExercitos() << std::endl;
    std::cout << "(Wer::teste) Quantidade de exercitos em F: " << (controlador.getTerritorio("F"))->getExercitos() << std::endl;

}
