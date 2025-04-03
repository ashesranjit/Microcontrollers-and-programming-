#include <iostream>
using namespace std;

int main() {
    int number, reversedNumber = 0;
    cout << "Enter a number: ";
    cin >> number;

    for (int n = number; n != 0; n /= 10) {
        int digit = n % 10;
        reversedNumber = reversedNumber * 10 + digit;
     
    }

    cout << "Reversed number: " << reversedNumber << endl;
    return 0;
}