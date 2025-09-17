#include <stdio.h>
#include <stdint.h> // For uint8_t
#include <stddef.h> // For size_t



int main(){

    int A = 10;
    int B = 20;

    if(A^B)
        printf("SAME\n");
    else
        printf("DIFF\n");

    return 0;
}