#include <iostream>
#include <string>
#include <limits>  // For numeric_limits
using namespace std;

// Base Car class
class Car {
protected:
    string model;
    int year;
    float price;

public:
    Car(string m = "", int y = 0, float p = 0.0) : model(m), year(y), price(p) {}

    virtual ~Car() {
        cout << "Car destroyed: " << model << endl;
    }

    // Function to input basic car details with validation
    void inputBasic() {
        cout << "Enter model: ";
        cin.ignore();
        getline(cin, model);

        year = getValidYear();
        price = getValidPrice();
    }

    // Function to display basic car details
    void displayBasic() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price;
    }

    // Virtual functions for polymorphism
    virtual void input() {
        inputBasic();
    }

    virtual void display() const {
        displayBasic();
        cout << endl;
    }

private:
    // Function to get a valid year (positive and realistic range)
    int getValidYear() {
        int inputYear;
        while (true) {
            cout << "Enter year: ";
            cin >> inputYear;
            if (cin.fail() || inputYear < 1886 || inputYear > 2025) {  // Cars started in 1886, and 2025 is a future realistic year.
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid year. Please enter a valid year between 1886 and 2025." << endl;
            } else {
                break;
            }
        }
        return inputYear;
    }

    // Function to get a valid price (positive float)
    float getValidPrice() {
        float inputPrice;
        while (true) {
            cout << "Enter price: $";
            cin >> inputPrice;
            if (cin.fail() || inputPrice < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid price. Please enter a valid positive price." << endl;
            } else {
                break;
            }
        }
        return inputPrice;
    }
};

// ElectricCar class
class ElectricCar : public Car {
private:
    float batterySize;

public:
    ElectricCar() : batterySize(0.0) {}

    ~ElectricCar() override {
        cout << "Destroying Electric Car: " << model << endl;
    }

    void input() override {
        inputBasic();
        batterySize = getValidBatterySize();
    }

    void display() const override {
        displayBasic();
        cout << ", Battery: " << batterySize << " kWh" << endl;
    }

private:
    // Function to get valid battery size (positive value)
    float getValidBatterySize() {
        float inputBattery;
        while (true) {
            cout << "Enter battery size (kWh): ";
            cin >> inputBattery;
            if (cin.fail() || inputBattery <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid battery size. Please enter a positive value." << endl;
            } else {
                break;
            }
        }
        return inputBattery;
    }
};

// GasCar class
class GasCar : public Car {
private:
    float fuelCapacity;

public:
    GasCar() : fuelCapacity(0.0) {}

    ~GasCar() override {
        cout << "Destroying Gas Car: " << model << endl;
    }

    void input() override {
        inputBasic();
        fuelCapacity = getValidFuelCapacity();
    }

    void display() const override {
        displayBasic();
        cout << ", Fuel: " << fuelCapacity << " L" << endl;
    }

private:
    // Function to get valid fuel capacity (positive value)
    float getValidFuelCapacity() {
        float inputFuel;
        while (true) {
            cout << "Enter fuel capacity (L): ";
            cin >> inputFuel;
            if (cin.fail() || inputFuel <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid fuel capacity. Please enter a positive value." << endl;
            } else {
                break;
            }
        }
        return inputFuel;
    }
};

// HybridCar class
class HybridCar : public Car {
private:
    float batterySize;
    float fuelCapacity;

public:
    HybridCar() : batterySize(0.0), fuelCapacity(0.0) {}

    ~HybridCar() override {
        cout << "Destroying Hybrid Car: " << model << endl;
    }

    void input() override {
        inputBasic();
        batterySize = getValidBatterySize();
        fuelCapacity = getValidFuelCapacity();
    }

    void display() const override {
        displayBasic();
        cout << ", Battery: " << batterySize << " kWh, Fuel: " << fuelCapacity << " L" << endl;
    }
};

int main() {
    int n;
    cout << "Enter total number of cars: ";
    cin >> n;

    // Create dynamic arrays
    Car** cars = new Car*[n];
    int* types = new int[n];

    // Input car data
    for (int i = 0; i < n; i++) {
        int type;
        cout << "\nCar " << (i + 1) << " type:" << endl;
        cout << "[1] Electric" << endl;
        cout << "[2] Gasoline" << endl;
        cout << "[3] Hybrid" << endl;
        cout << "Enter choice: ";
        cin >> type;

        types[i] = type;

        // Create appropriate car object
        switch (type) {
            case 1:
                cars[i] = new ElectricCar();
                break;
            case 2:
                cars[i] = new GasCar();
                break;
            case 3:
                cars[i] = new HybridCar();
                break;
            default:
                cout << "Invalid type. Creating default car." << endl;
                cars[i] = new Car();
                break;
        }

        // Input car details
        cars[i]->input();
    }

    // Display all cars
    cout << "\n--- Fleet Information ---" << endl;
    for (int i = 0; i < n; i++) {
        // Use static_cast to call the correct display function
        switch (types[i]) {
            case 1:
                static_cast<ElectricCar*>(cars[i])->display();
                break;
            case 2:
                static_cast<GasCar*>(cars[i])->display();
                break;
            case 3:
                static_cast<HybridCar*>(cars[i])->display();
                break;
            default:
                cars[i]->display();
                break;
        }
    }

    // Clean up memory
    cout << "\n--- Cleaning up fleet ---" << endl;
    for (int i = 0; i < n; i++) {
        delete cars[i]; // This will call the appropriate destructor
    }

    delete[] cars;
    delete[] types;

    return 0;
}
