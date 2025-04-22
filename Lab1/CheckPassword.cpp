#include <iostream>
#include <cctype>  
#include <cstring> 


#define MIN_LENGTH 8

using namespace std;


void checkPasswordStrength(string password) {
    
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    string missingCriteria = "";

    
    if (password.length() < MIN_LENGTH) {
        missingCriteria += "Length (minimum 8 characters), ";
    }

    
    for (char ch : password) {
        if (isupper(ch)) {
            hasUpper = true;
        } else if (islower(ch)) {
            hasLower = true;
        } else if (isdigit(ch)) {
            hasDigit = true;
        } else if (ispunct(ch)) {
            hasSpecial = true;
        }
    }

    
    if (password.length() >= MIN_LENGTH && hasUpper && hasLower && hasDigit && hasSpecial) {
        cout << "Strong Password" << endl;
    } else {
        
        if (!hasLower) missingCriteria += "Lowercase letter, ";
        if (!hasDigit) missingCriteria += "Digit, ";
        if (!hasSpecial) missingCriteria += "Special character (e.g., !@#$%^&*), ";

        
        if (!missingCriteria.empty()) {
            missingCriteria = missingCriteria.substr(0, missingCriteria.length() - 2);
        }

        
        cout << "Weak Password: Missing criteria - " << missingCriteria << endl;
    }
}

int main() {
    string password;
    
   
    cout << "Enter your password: ";
    cin >> password;

    
    checkPasswordStrength(password);
    
    return 0;
}
