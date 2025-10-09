#include <stdio.h>
#include <stdint.h> // For uint8_t
#include <stddef.h> // For size_t

#define NUM_CONTROLLERS 3
#define NUM_FANS 6

int main(){

    int FANS[NUM_CONTROLLERS][NUM_FANS];

    FANS[0][0] = 1;
    FANS[0][2] = 3;
    FANS[0][5] = 5;
    FANS[2][3] = 2;

    printf("%d", FANS[0][0]);
    printf("%d", FANS[0][2]);
    printf("%d", FANS[0][5]);
    printf("%d", FANS[2][3]);
    

    return 0;
}