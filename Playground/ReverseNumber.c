#include <stdio.h>
#include <stdlib.h>

int ReverseNumber(int n)
{
    int temp=0;
    int res=0;
    int i=0;
    while(n!=0)
    {
        temp = n %10;
        res = res*10 + temp; 
        n /= 10;  
    }
    return res;

}
int main()
{
    int num = 562223;

    printf("%d\r\n", ReverseNumber(num));
    return 0;
}