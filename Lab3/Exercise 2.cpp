#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    char grade;
    string group = "2025 group";  // default value

public:
    // Setters
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    void setGrade(char g) {
        grade = g;
    }

    // Getters
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    char getGrade() {
        return grade;
    }

    // Display method
    void displayInfo() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Grade: " << getGrade() << endl;
        cout << "Group: " << group << endl;
    }
};

// Main function
int main() {
    Student s1;

    // Using setters to assign values
    s1.setName("Alice");
    s1.setAge(17);
    s1.setGrade('A');

    // Using getters to print individual values
    cout << "Using getters:" << endl;
    cout << "Name: " << s1.getName() << endl;
    cout << "Age: " << s1.getAge() << endl;
    cout << "Grade: " << s1.getGrade() << endl;

    // Using displayInfo
    cout << "\nFull student info using displayInfo():" << endl;
    s1.displayInfo();

    return 0;
}
