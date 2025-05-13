#include <stdio.h>
#include <stdlib.h>


int ClearBit(int n, int pos)
{
    int mask = ~(1 << pos);// create the pattern with a mask. i.e. 000010000. Inverted: 111101111
    return n & mask;
}

int main()
{
    int num = 21;

    printf("%d", ClearBit(num, 2));
    
    return 0;
}