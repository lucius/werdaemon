#include "Random.h"

#include "time.h"

Random::Random()
{
    srand(time(NULL));
}

Random::~Random()
{

}

ptrdiff_t
Random::operator()(ptrdiff_t _max)
{
    double
    tmp = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);

    return static_cast<ptrdiff_t>(tmp* _max);
}
