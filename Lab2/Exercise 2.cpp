#include <iostream>
using namespace std;


void swapWithoutPointersOrReferences(float a, float b) {
    float temp = a;
    a = b;
    b = temp;

    
    cout << "Swap Without Pointers = a: " << a << ", b: " << b << endl;
}

void swapUsingPointers(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;

        cout << "Swap With Pointers = *a: " << *a << ", *b: " << *b << endl;
}

void swapUsingReferences(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;

        cout << "Swap Using References = a: " << a << ", b: " << b << endl;
}

int main() {
    float x = 5.5, y = 7.5;

    cout << "Before any swap = x: " << x << ", y: " << y << endl;

    swapWithoutPointersOrReferences(x, y);
    cout << "After swap Without Pointers (in main) = x: " << x << ", y: " << y << endl;

    swapUsingPointers(&x, &y);
    cout << "After swap Using Pointers (in main) = x: " << x << ", y: " << y << endl;

    swapUsingReferences(x, y);
    cout << "After swap Using References (in main) = x: " << x << ", y: " << y << endl;

    return 0;
}
