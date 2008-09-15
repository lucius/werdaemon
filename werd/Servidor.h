#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include <queue>
#include "Thread.h"

class
Servidor : public Thread
{
    public:
        Servidor();

        virtual
        ~Servidor();

        unsigned short int
        iniciaServidor(unsigned int);

        unsigned short int
        iniciaJogo();

        unsigned short int
        finalizaJogo();

        unsigned short int
        finalizaTurno();

        unsigned short int
        atualizaJogo();

        unsigned short int
        defineJogadorCorrente();

        unsigned short int
        enviaMensagem();

        unsigned short int
        enviaMensagemMultiCast();

        unsigned short int
        distribuiExercito();

        unsigned short int
        distribuiExercitoMultiCast();

    protected:
        virtual void*
        configura();

        virtual void*
        executa(void*);

        std::queue<std::string>
        filaPacotes;
};

#endif
