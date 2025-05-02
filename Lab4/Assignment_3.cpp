#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car {
private:
    string model;
    int year;
    double price;

public:
    Car(const string& m = "", int y = 0, double p = 0.0) 
        : model(m), year(y), price(p) {
        if (!model.empty()) {
            cout << "Car Constructor: " << model << " (" << year << ") - $" << price << endl;
        }
    }

    ~Car() {
        if (!model.empty()) {
            cout << "Car Destructor: " << model << " destroyed" << endl;
        }
    }

    void input() {
        cout << "Enter model: ";
        getline(cin, model);

        cout << "Enter year: ";
        while (!(cin >> year) || year < 1886 || year > 2100) {
            cout << "Invalid year. Enter a valid year: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter price: $";
        while (!(cin >> price) || price < 0) {
            cout << "Invalid price. Enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(); // Clear newline from buffer after numeric input
    }

    void display() const {
        cout << *this;
    }

    friend ostream& operator<<(ostream& os, const Car& car) {
        os << "Model: " << car.model << ", Year: " << car.year << ", Price: $" << car.price << endl;
        return os;
    }
};

class CarCollection {
private:
    vector<Car> cars;

public:
    CarCollection() {
        int count;
        cout << "How many cars do you want to enter? ";
        while (!(cin >> count) || count <= 0) {
            cout << "Please enter a valid positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(); // Clear newline after numeric input

        cars.resize(count);

        for (int i = 0; i < count; ++i) {
            cout << "\nEnter details for car " << (i + 1) << ":" << endl;
            cars[i].input();
        }

        cout << "CarCollection initialized with " << count << " cars." << endl;
    }

    ~CarCollection() {
        cout << "CarCollection destroyed" << endl;
    }

    void displayCars() const {
        cout << "\nCar Collection:\n";
        for (const auto& car : cars) {
            car.display();
        }
    }
};

int main() {
    CarCollection myCollection;
    myCollection.displayCars();

    return 0;
}
