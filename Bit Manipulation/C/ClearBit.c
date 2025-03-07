#include <stdio.h>
#include <stdlib.h>


int ClearBit(int n, int pos)
{
    int mask = ~(1<<pos);
    return (n & mask);
}

int main()
{
    int num = 5;

    printf("%d", ClearBit(num, 2));
    
    return 0;
}