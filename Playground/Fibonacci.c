#include <stdio.h>
#include <stdlib.h>


int FibonacciRecursive(int num)
{
    if(num <= 1)
        return num; // return itself
    else
        return FibonacciRecursive(num-1) + FibonacciRecursive(num-2);
}
int FibonacciBrute(int num)
{
    if (num <= 1) {
        return num;
    }

    int t3, t2 = 1, t1 = 0;
    for (int i = 2; i <= num; i++) { // first term =1, second term = 1, third term = 2
       t3 = t1 + t2;
       t1 = t2;
       t2 = t3;
    }
    return t3;
    
}
int main()
{
    int num = 7;

    printf("Fib Recursive: %d\r\n", FibonacciRecursive(num));
    printf("Fib Brute: %d\r\n", FibonacciBrute(num));
    return 0;
}