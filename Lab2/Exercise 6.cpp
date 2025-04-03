#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    int id;
    float grade;
};

void addStudent(Student students[], int& count) {
    if (count >= 100) {
        cout << "Maximum number of students reached!" << endl;
        return;
    }

    cout << "Enter student's name: ";
    cin.ignore(); 
    cin.getline(students[count].name, 50);

    cout << "Enter student's ID: ";
    cin >> students[count].id;

    cout << "Enter student's grade: ";
    cin >> students[count].grade;

    count++;
    cout << "Student added successfully!" << endl;
}


void displayStudents(const Student students[], int count) {
    if (count == 0) {
        cout << "No students available." << endl;
        return;
    }

    cout << "Student Records:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Name: " << students[i].name
             << ", ID: " << students[i].id
             << ", Grade: " << students[i].grade << endl;
    }
}


void searchStudent(const Student students[], int count, int id) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Student found!" << endl;
            cout << "Name: " << students[i].name
                 << ", ID: " << students[i].id
                 << ", Grade: " << students[i].grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << id << " not found." << endl;
    }
}

int main() {
    Student students[100];  
    int studentCount = 0;   
    int choice, searchId;

    do {
        // Display the menu
        cout << "\nStudent Record Management" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Search for a student by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                cout << "Enter student ID to search: ";
                cin >> searchId;
                searchStudent(students, studentCount, searchId);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
