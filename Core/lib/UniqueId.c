#include "UniqueId.h"

static long int counter = 0;

long int generate_id()
{
    return counter++;
}
