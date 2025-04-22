#include <iostream>
using namespace std;

int main() {
    double value1, value2, result;
    char op;

    cout << "Enter the first value: ";
    cin >> value1;
    
    cout << "Enter the second value: ";
    cin >> value2;
    
    cout << "Enter the operator (+, -, *, /): ";
    cin >> op;

    
    switch(op) {
        case '+':
            result = value1 + value2;
            cout << "The result of " << value1 << " + " << value2 << " is: " << result << endl;
            break;
        case '-':
            result = value1 - value2;
            cout << "The result of " << value1 << " - " << value2 << " is: " << result << endl;
            break;
        case '*':
            result = value1 * value2;
            cout << "The result of " << value1 << " * " << value2 << " is: " << result << endl;
            break;
        case '/':
            if (value2 != 0) {
                result = value1 / value2;
                cout << "The result of " << value1 << " / " << value2 << " is: " << result << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
            break;
    }

    return 0;
}
