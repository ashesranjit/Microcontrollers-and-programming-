#include <iostream>
#include <string>
#include <cctype>  

using namespace std;

int countVowels(const string& str) {
    int count = 0;
    for (char ch : str) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }
    return count;
}


string reverseString(const string& str) {
    string reversed = str;
    int n = reversed.length();
    for (int i = 0; i < n / 2; ++i) {
        swap(reversed[i], reversed[n - i - 1]);
    }
    return reversed;
}

int main() {
    string input;
    
    
    cout << "Enter a string: ";
    getline(cin, input);

    
    for (char &ch : input) {
        ch = toupper(ch);
    }
    
    cout << "String in uppercase: " << input << endl;

    
    int vowelCount = countVowels(input);
    cout << "Number of vowels: " << vowelCount << endl;

    
    string reversedString = reverseString(input);
    cout << "Reversed string: " << reversedString << endl;

    return 0;
}
