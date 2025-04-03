#include <iostream>
#include <cmath>

using namespace std;

int multiply(int a, int b) {
    return a * b;
}
    
    double multiply(double a, double b) {
        return a * b;
    }
    
    int multiply(int a, double b, bool flag) {
        double result = a * b;
        
        if (flag) {
            
            result = ceil (result);
        } 
        
            return static_cast<int>(result);
        }
        
    int main (){
        
        int intResult = multiply(5, 4);
        cout << "Result of multiplying two integers: "<< intResult << endl;
        
        double doubleResult = multiply(3.5, 2.2);
        cout << "Result of multiplying two doubles: "<< doubleResult << endl;
        
        int mixedResult1 = multiply(3, 2.5, false);
        cout << "Result of multiplying an integer and a double (flag = false): "<< mixedResult1 << endl;
        
        int mixedResult2 = multiply(3, 2.5, true);
        cout << "Result of multiplying an integer and a double (flag = true): "<< mixedResult2 << endl;
        
        return 0;
    }

