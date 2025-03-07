#include <stdio.h>
#include <stdlib.h>

int CountBits(int num)
{
    int count = 0;
    while(num > 0)
    {
        if((num & 1)) // // check the rightmost bit. if true (1), increment the count
            count++;
        num = num >> 1; // shift the next bit over to check.
    }
    return count;

}

int main()
{
    int num = 64;
    printf("%d", CountBits(num));
    
    return 0;
}