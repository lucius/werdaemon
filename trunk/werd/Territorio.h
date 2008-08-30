#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>
#include <map>


// Adicionar exercitos
class Territorio
{
    public:
        Territorio();

        ~Territorio();

        std::string
        getNome();

        void
        setNome(std::string);

        bool
        fazFronteiraCom(std::string);

        void
        adicionaFronteiraCom(Territorio*);

    protected:
        std::string
        nome;

        std::map<std::string, Territorio*>
        fronteiras;
};

#endif
