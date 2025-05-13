#include <stdio.h>
#include <stdlib.h>

int CountBits(int num)
{
    int count = 0;
    while(num>0)
    {
        if(num & 1)
        {
            count++;
        }
        num = num >> 1; 
        
    }
    return count;

}

int main()
{
    int num = 17;
    printf("%d", CountBits(num));
    
    return 0;
}