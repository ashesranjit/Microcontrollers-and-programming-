#include <iostream>
using namespace std;
#define Macros(x) ((x)*(x))

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The SQUARE of "<< num << " is: " << Macros(num) << endl;
        return 0;
}