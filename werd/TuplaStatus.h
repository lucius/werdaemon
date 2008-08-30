#ifndef TUPLASTATUS_H_
#define TUPLASTATUS_H_

#include <string>

class TuplaStatus
{
    public:
        explicit
        TuplaStatus(std::string, std::string, unsigned short int);

        virtual
        ~TuplaStatus();

        void
        setStatus(std::string, std::string, unsigned short int);

        std::string
        getTerritorio();

        std::string
        getJogador();

        unsigned short int
        getExercitos();

    protected:
        std::string
        territorio;

        std::string
        jogador;

        unsigned short int
        exercitos;
};

#endif
