#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <queue>
#include <string>

class
Cliente
{
    public:
        Cliente();

        virtual
        ~Cliente();

        unsigned short int
        iniciaClienteServidor(std::string, unsigned int);

        unsigned short int
        setNick(std::string);

        unsigned short int
        enviaMensagem(std::string);

        unsigned short int
        enviaMensagemMulticast(std::string);

        unsigned short int
        moveExercito();

        unsigned short int
        ataca();

        unsigned short int
        passaTurno();

        unsigned short int
        atualizaStatus();

    protected:
        std::queue<std::string>
        pacotesEntrada,
        pacotesSaida;
};

#endif
