#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include "Jogador.h"

// adicionar exercitos
class
Jogador
{
    public:
        Jogador();

        ~Jogador();

        unsigned short int
        getId();

        void
        setId(unsigned short int);

        std::string
        getNick();

        void
        setNick(std::string);

    protected:
        unsigned short int
        id;

        std::string
        nick;
};

#endif
