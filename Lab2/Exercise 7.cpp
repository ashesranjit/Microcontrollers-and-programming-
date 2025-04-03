#include <iostream>
using namespace std;

int main() {
    int x = 100;  
    
    int* p1 = &x;  
    int* p2 = p1;   

   
    cout << "Before modification:" << endl;
    cout << "Value of x: " << x << endl;               
    cout << "Pointer p1 points to address: " << p1 << endl;  
    cout << "Pointer p2 points to address: " << p2 << endl;  
    cout << "Value pointed by p1: " << *p1 << endl;   
    cout << "Value pointed by p2: " << *p2 << endl;   

    
    *p1 = 200;

    
    cout << "\nAfter modifying value through p1:" << endl;
    cout << "Value of x: " << x << endl;               
    cout << "Pointer p1 points to address: " << p1 << endl;  
    cout << "Pointer p2 points to address: " << p2 << endl;  
    cout << "Value pointed by p1: " << *p1 << endl;    
    cout << "Value pointed by p2: " << *p2 << endl;    

    return 0;
}
