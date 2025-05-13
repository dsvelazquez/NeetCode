#include <stdio.h>
#include <stdlib.h>

int factorialRecursive(int num)
{
    if(num == 0) // base case
        return 1;
    else
        return num * factorialRecursive(num-1);
}
int factorialBrute(int num)
{
    int res=1;
    if(num < 0)
        return 0;

    while(num > 0)
    {
        res = res * num;
        num--;
    }
    return res;
}

int main()
{
    int num = 7;

    printf("Recursive: %d\r\n", factorialRecursive(num));
    printf("Brute Force: %d\r\n", factorialBrute(num));

    return 0;
}