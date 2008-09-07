#ifndef RANDOM_H_
#define RANDOM_H_

#include <algorithm>

class
Random
{
    public:
        Random();

        virtual
        ~Random();

        ptrdiff_t
        operator()(ptrdiff_t);
};

#endif
