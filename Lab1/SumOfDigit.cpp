#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;

    cout << "Enter a value: ";
    cin >> num;

    for (; num > 0; num /= 10) {  
        sum += num % 10;  
    }

    cout << "Sum is: " << sum << endl;
    return 0;
}
