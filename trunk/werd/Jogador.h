#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <map>
#include "Jogador.h"

class
Territorio; /*   Refer�ncia cruzada entre classes   */
#include "Territorio.h"

class
Jogador
{
    public:
        Jogador();

        ~Jogador();

        std::string
        getNick();

        void
        setNick(std::string);

        unsigned short int
        getExercitos();

        void
        setExercitos(unsigned short int);

        // @ TODO testar
        void
        ganhaTerritorio(Territorio*);

        // @ TODO testar
        void
        perdeTerritorio(Territorio*);

    protected:
        std::string
        nick;

        unsigned short int
        exercitos;

                                     /*   Refer�ncia cruzada entre classes   */
        std::map<std::string, void*> /*   std::map<std::string, Territorio*>   */
        territorios;
};

#endif
