#include <iostream>
#include <string>
#include <limits> // For numeric limits
using namespace std;

// Function to handle input validation for integer values (age)
int getValidAge() {
    int age;
    while (true) {
        cout << "Enter your age: ";
        cin >> age;
        
        // Check if the input is a valid integer
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input in the buffer
            cout << "Invalid input. Please enter a valid integer for age." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any leftover characters
            return age;
        }
    }
}

// Example without cin.ignore() - Demonstrating potential issue
void withoutCinIgnore() {
    int age;
    string name;
    
    cout << "EXAMPLE WITHOUT cin.ignore()" << endl;
    cout << "----------------------------" << endl;
    
    // Getting valid age input
    age = getValidAge();
    
    cout << "Enter your full name: ";
    getline(cin, name); // Will fail to get correct name due to leftover newline character
    
    cout << "Age: " << age << ", Name: \"" << name << "\"" << endl;
    cout << endl;
}

// Example with cin.ignore() - Correct handling
void withCinIgnore() {
    int age;
    string name;
    
    cout << "EXAMPLE WITH cin.ignore()" << endl;
    cout << "------------------------" << endl;
    
    // Getting valid age input
    age = getValidAge();
    
    // Using cin.ignore() to clear the input buffer
    cout << "Enter your full name: ";
    getline(cin, name); // Now correctly reads the name
    
    cout << "Age: " << age << ", Name: \"" << name << "\"" << endl;
}

int main() {
    // Running both examples to showcase the difference
    withoutCinIgnore();
    withCinIgnore();
    
    cout << "\nEXPLANATION:" << endl;
    cout << "-----------" << endl;
    cout << "Without cin.ignore():" << endl;
    cout << "  The newline character left in the input buffer after reading" << endl;
    cout << "  the age is immediately consumed by getline(), resulting in" << endl;
    cout << "  an empty string for the name." << endl;
    cout << endl;
    cout << "With cin.ignore():" << endl;
    cout << "  The newline character is discarded by cin.ignore()," << endl;
    cout << "  allowing getline() to wait for actual user input" << endl;
    cout << "  for the name, resulting in correct behavior." << endl;
    
    return 0;
}
