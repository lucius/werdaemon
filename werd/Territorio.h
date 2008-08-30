#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>
#include <map>

class
Jogador; /*   Referência cruzada entre classes   */
#include "Jogador.h"

class
Territorio
{
    public:
        Territorio();

        ~Territorio();

        std::string
        getNome();

        void
        setNome(std::string);

        unsigned short int
        getExercitos();

        void
        setExercitos(unsigned short int);

        bool
        fazFronteiraCom(std::string);

        void
        adicionaFronteiraCom(Territorio*);

        // @ TODO testar
        Jogador*
        getPossuidor();

        // @ TODO testar
        void
        setPossuidor(Jogador*);

        // @ TODO testar
        bool
        pertenceA(std::string);

    protected:
        std::string
        nome;

        unsigned short int
        exercitos;

        std::map<std::string, Territorio*>
        fronteiras;

              /*   Referência cruzada entre classes   */
        void* /*   Jogador*   */
        possuidor;

        Jogador*
        castPossuidor();
};

#endif
