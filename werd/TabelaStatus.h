#ifndef TABELASTATUS_H_
#define TABELASTATUS_H_

#include <list>
#include <map>
#include <string>
#include <vector>

#include "TuplaStatus.h"

class
TabelaStatus
{
    public:
        TabelaStatus();

        virtual
        ~TabelaStatus();

        std::vector<TuplaStatus*>
        getTuplas();

        void
        setTupla(std::string, std::string, unsigned short int);

    protected:
        std::map< std::string, TuplaStatus* >
        tabela;
};

#endif
