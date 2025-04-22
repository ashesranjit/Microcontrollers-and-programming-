#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle {
protected:
    string brand;
    int year;
public:
    Vehicle(string b, int y) : brand(b), year(y) {}
    virtual void showInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
    virtual void startEngine() {
        cout << "Starting engine of Vehicle" << endl;
    }
    virtual ~Vehicle() {}
};

// Derived class
class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(string b, int y, int d) : Vehicle(b, y), numDoors(d) {}
    void showInfo() override {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
        cout << "Number of doors: " << numDoors << endl;
    }
    void startEngine() override {
        cout << "Car engine is starting!" << endl;
    }
};

// Derived from Car
class ElectricCar : public Car {
private:
    int batteryCapacity;
public:
    // Default constructor
    ElectricCar() : Car("Generic", 2000, 4), batteryCapacity(0) {}

    // Parameterized constructor
    ElectricCar(string b, int y, int d, int bc) : Car(b, y, d), batteryCapacity(bc) {}

    void showInfo() override {
        Car::showInfo();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }

    void startEngine() override {
        cout << "Electric engine is starting... Silent but powerful!" << endl;
    }
};

int main() {
    // Vehicle object
    Vehicle* v = new Vehicle("Generic", 2015);
    v->showInfo();
    v->startEngine();
    cout << endl;

    // Car object
    Car* c = new Car("Toyota", 2021, 4);
    c->showInfo();
    c->startEngine();
    cout << endl;

    // ElectricCar default constructor
    ElectricCar* e1 = new ElectricCar();
    e1->showInfo();
    e1->startEngine();
    cout << endl;

    // ElectricCar parameterized constructor
    ElectricCar* e2 = new ElectricCar("Nissan", 2022, 4, 40);
    e2->showInfo();
    e2->startEngine();
    cout << endl;

    // Clean up
    delete v;
    delete c;
    delete e1;
    delete e2;

    return 0;
}
