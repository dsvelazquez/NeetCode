#include <iostream>


int readNumber(void){
    int x{};
    std::cout << "Enter integer: ";
    std::cin >> x;

    return x;
}
void writeAnswer(int num){
    std::cout << "Sum: " << num; 
}

int main(){
    int x{readNumber()};
    int y{readNumber()};

    writeAnswer(x+y);


    return 0;
}