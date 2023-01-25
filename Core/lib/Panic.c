#include "Panic.h"
#include <stdio.h>
#include <stdlib.h>

void panic(char *msg)
{
    printf("CRITICAL ERROR: %s", msg);
    exit(1);
}
