#include <iostream>
using namespace std;

int main () {
    int number ;

    while (true) {
        cout << "Enter a number: ";
        cin >> number;

        if (number < 0) {
            cout << "Negative Number Entered.\n The program STOP." << endl;
            break;
        }

        else if (number == 0) {
            continue;

        } 
        else {
            cout << "The Square of " << number << " is :" << number * number << endl;
        }
    }

    return 0;
   
    
}