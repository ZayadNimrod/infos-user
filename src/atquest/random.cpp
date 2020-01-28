
#include "random.h"
#include <infos.h>
RNG::RNG()
{
   seed = 0;
}

void RNG::SetSeed(int s)
{
    seed = s;
}

int RNG::Next(int range)
{
    seed++;
    while (seed >= 100)
    {
        seed -=100;
    }
    struct tod t;
	
	int rc = get_time_of_day(&t);
    return (seed * (t.seconds))%range;
}