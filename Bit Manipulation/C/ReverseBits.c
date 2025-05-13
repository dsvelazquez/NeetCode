/*
Given a 32-bit unsigned integer n, reverse the bits of the binary representation of n and return the result.

Example 1:

Input: n = 00000000000000000000000000010101

Output:    2818572288 (10101000000000000000000000000000)
Explanation: Reversing 00000000000000000000000000010101, which represents the unsigned integer 21, gives us 10101000000000000000000000000000 which represents the unsigned integer 2818572288.

*/
#include <stdio.h>
#include <stdlib.h>

unsigned char reverseBits(unsigned char n)
{
    unsigned char bit;
    unsigned char res;
    unsigned char count = 0;
    
    while(count < 8)
    {
        bit = n & 1; // Get the least significant bit
        n = n >> 1; // update n. shift to the right one time
        res |= (bit << (7 - count)); // shift to the left (MSB)
        count++;
    }
    
    return res;

}

int main()
{
    int num = 8;
    printf("%d\r\n", reverseBits(num));

    return 0;
}