#include <iostream>
#include <stdexcept> // for std::runtime_error
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload * operator
    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;
        return Complex(newReal, newImag);
    }

    // Overload / operator with division-by-zero check
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw runtime_error("Division by zero complex number");
        }
        double newReal = (real * other.real + imag * other.imag) / denominator;
        double newImag = (imag * other.real - real * other.imag) / denominator;
        return Complex(newReal, newImag);
    }

    // Declare the << operator as a friend function
    friend ostream& operator<<(ostream& os, const Complex& c);
};

// Implement the << operator
ostream& operator<<(ostream& os, const Complex& c) {
    if (c.imag >= 0)
        os << c.real << " + " << c.imag << "i";
    else
        os << c.real << " - " << -c.imag << "i";
    return os;
}

int main() {
    try {
        Complex c1(4, 5), c2(2, -3);
        cout << "c1 = " << c1 << endl;
        cout << "c2 = " << c2 << endl;
        cout << "Sum = " << c1 + c2 << endl;
        cout << "Difference = " << c1 - c2 << endl;
        cout << "Product = " << c1 * c2 << endl;
        cout << "Quotient = " << c1 / c2 << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
