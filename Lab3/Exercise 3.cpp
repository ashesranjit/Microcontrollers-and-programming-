#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    int year;

public:
    // Constructor
    Car(string b, int y) {
        brand = b;
        year = y;
        cout << "Car " << brand << " from " << year << " created." << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car " << brand << " destroyed." << endl;
    }

    // Method to show car info
    void showInfo() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    // Create object on the heap using new
    Car* myCar = new Car("Toyota", 2022);

    // Call showInfo method
    myCar->showInfo();

    // Delete the object to call destructor
    delete myCar;

    return 0;
}
