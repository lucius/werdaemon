#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <map>
#include "Jogador.h"

class
Territorio; /*   Referência cruzada entre classes   */
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

        void
        ganhaTerritorio(Territorio*);

        void
        perdeTerritorio(Territorio*);

        // @ TODO testar
        void
        setExercitos(unsigned short int, Territorio*);

    protected:
        std::string
        nick;
                                     /*   Referência cruzada entre classes   */
        std::map<std::string, void*> /*   std::map<std::string, Territorio*>   */
        territorios;
};

#endif
