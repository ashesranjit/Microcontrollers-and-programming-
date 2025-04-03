#include <iostream>


void swapUsingReferences(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

int main() {
    
    int a = 100;
    int& refA = a; 
    std::cout << "Original value of a: " << a << std::endl;

    refA = 30; 
    std::cout << "Value of a after modifying refA: " << a << std::endl;

   

    return 0;
}
