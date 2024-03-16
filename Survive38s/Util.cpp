#include "Header.h"
#include "Util.h"

void limit(short& n, short min, short max)
{
    if (n < min) n = min;
    if (n > max) n = max;
}