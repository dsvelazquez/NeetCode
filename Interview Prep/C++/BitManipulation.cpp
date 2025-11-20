#include <iostream>
#include <bitset>
#include <cstdint>



template <typename T>
T setBits(T value, unsigned int bit){
    return value |= ((T)1 << bit); // cast to type T
}
template <typename T>
T clearBits(T value, unsigned int bit){
    return value &= ~((T)1 << bit);
}
template <typename T>
T toggleBits(T value, unsigned int bit){
    return value ^= ((T)1 << bit);
}
template <typename T>
T rotateLeft(T value, unsigned int shift){
    const unsigned int BITS = sizeof(T) * 8;
    shift %= BITS; // makes sure it doesn't go out of bounds. Rotating by 8 bit value b 8,16,24 etc. is the same as 
                    // rotating by 0. Similarly, rotatinb by 9 is same as rotating by 1.

    return (value << shift) | (value >> (BITS - shift));
}
template <typename T>
T rotateRight(T value, unsigned int shift){
    const unsigned int BITS = sizeof(T) * 8;
    shift %= BITS;
    return (value >> shift) | (value << (BITS - shift));
}
template <typename T>
T invertBits(T value){
    return ~value;
}
//print a number between 0 and 255
/*
This method uses integer division. Consider the decimal number 148. 
The largest power of 2 that’s smaller than 148 is 128, so we’ll start there.

148 / 128 = 1 with some remainder. Since 1 is odd, this bit is a 1.
148 / 64 = 2 with some remainder. Since 2 is even, this bit is a 0.
148 / 32 = 4 with some remainder. Since 4 is even, this bit is a 0.
148 / 16 = 9 with some remainder. Since 9 is odd, this bit is a 1.
148 / 8 = 18 with some remainder. Since 18 is even, this bit is a 0.
148 / 4 = 37 with some remainder. Since 37 is odd, this bit is a 1.
148 / 2 = 74 with some remainder. Since 74 is even, this bit is a 0.
148 / 1 = 148 with some remainder. Since 148 is even, this bit is a 0.

only works for numbers 0 to 255
*/
void printBit(int x){
    for(int i = 31; i >=0; i--)
        std::cout << ((x >> i) & 1);
    // since the number is already represneted in binary (in the computer) just shift to the right
}
int main(){

    uint8_t x = 0b10000001;

    auto l = rotateLeft(x, 4);
    auto r = rotateRight(x,3);

    std::cout << std::bitset<8>(l) << "\n";
    std::cout << std::bitset<8>(r) << std::endl;

    auto s = setBits(x, 9);
    std::cout<< std::bitset<8>(s) << "\n";

    auto c = clearBits(x,0);
    std::cout << std::bitset<8>(c) << "\n";
    auto t = toggleBits(x, 3);
    std::cout << std::bitset<8>(t) << "\n";
    t = toggleBits(t,3);
    std::cout << std::bitset<8>(t) << "\n";
    t = toggleBits(t,3);
    std::cout << std::bitset<8>(t) << "\n";

    auto i = invertBits(t);
    std::cout << std::bitset<8>(i) << "\n";

    printBit(355);

    return 0;
}