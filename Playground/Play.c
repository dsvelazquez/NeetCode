#include <stdlib.h>
#include <stdio.h>

#define FILTER 0x1E22338D
int main()
{
    printf("%x\n", FILTER >> 24);
    printf("%x\n", (FILTER & 0x00FF0000)>>16);
    printf("%x\n", (FILTER & 0x0000FF00)>>8);
    printf("%x\n", (FILTER & 0x000000FF));
    return 0;
}