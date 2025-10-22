#include <iostream>
#include <cmath>

void nullify(int*& refptr){
    refptr = nullptr;
}
int main()
{
    int x{ 5 };
    int* ptr{&x};
    
    //int*& refPTR{ptr};

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    
    return 0;
}