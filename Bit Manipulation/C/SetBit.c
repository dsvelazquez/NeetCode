#include <stdio.h>
#include <stdlib.h>

int SetBit(int num, int pos)
{
    int mask = 1<< pos;

    return (num | mask);
}

int main()
{
    int num = 5;
    printf("%d", SetBit(num, 1));
    
    return 0;
}