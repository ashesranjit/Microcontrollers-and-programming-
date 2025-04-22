#include <iostream>
using namespace std;

int main () {
    
    int arry [] = {1,3,5,7,8,10,15};
    int size = sizeof(arry)/sizeof(arry[0]);

    int reverse[size];

    int* ptr = arry;
    for (int i = 0; i < size; i++) {
        reverse[i] = *(ptr + size - 1 - i);
    }
    cout << "The Reverse array is: ";
    for (int i = 0; i < size; i++) {
        cout << reverse[i] << " ";
    }
    cout << endl;   
    return 0;
}