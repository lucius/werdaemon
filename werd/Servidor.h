#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include <queue>

class
Servidor
{
    public:
        Servidor();

        virtual
        ~Servidor();

        unsigned short int
        iniciaServidor();

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
        static unsigned short int
        escutaPorConexoes();

        static unsigned short int
        enviaPacote();

        //CRIAR FILA ENCAMINHAMENTO DE PACOTES
};

#endif
