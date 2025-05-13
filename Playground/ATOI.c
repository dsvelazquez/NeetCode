#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Write a function that takes a string numeric value and retruns the corresponding integer value*/
// "1234" -> 1234
// HINTS:
// Keep track of sign

int ATOI_FUNCTION(const char *str)
{
    int sign = 1;
    int count = 0;
    int result = 0;

    // Check if string is null or \0
    if(str == NULL || *str == '\0')
    {
        return 0;
    }

    // check for sign
    if(str[count] == '-')
    {
        count++;
        sign = -1;
    }
    else if(str[count] == '+')
    {
        count++;
        sign = 1;
    }

    // Compute string to int
    while(str[count] >= '0' && str[count] <='9')
    {
        printf("result: %d\n", result);
        result = result*10 + (str[count] - '0');
        count++;
    }
    return result * sign ;
}
int main(){
    char *numStr1 = "1234567";
    printf("'%s' -> %d\n", numStr1, ATOI_FUNCTION(numStr1));
    return 0;
}