#include <iostream>
#include <string>
#include <vector>  // for std::vector

using namespace std;

class Book {
private:
    string title;
    int pages;
public:
    // Constructor
    Book(const string& t = "Untitled", int p = 0) : title(t), pages(p) {
        cout << "Book Constructor: \"" << title << "\" with " << pages << " pages\n";
    }

    // Destructor
    ~Book() {
        cout << "Book Destructor: \"" << title << "\" destroyed\n";
    }

    // Method to display book info
    void display() const {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }
};

class BookShelf {
private:
    vector<Book> books;  // safer than raw pointer
public:
    // Constructor: initialize vector with 3 Book objects
    BookShelf() : books{
        Book("C++ Fundamentals", 300),
        Book("Data Structures", 450),
        Book("Algorithms", 500)
    } {
        cout << "BookShelf Constructor: Shelf initialized with " << books.size() << " books\n";
    }

    // No need for custom destructor – vector handles cleanup

    void displayBooks() const {
        cout << "\nBooks on shelf:\n";
        for (const auto& book : books) {
            book.display();
        }
    }
};

// Example 1: Array of Book objects (stack allocation)
void example1() {
    cout << "EXAMPLE 1: Array of Book objects\n";
    cout << "--------------------------------\n";

    Book library[3] = {
        Book("C++ Fundamentals", 300),
        Book("Data Structures", 450),
        Book("Algorithms", 500)
    };

    cout << "\n--- Library Contents ---\n";
    for (int i = 0; i < 3; ++i) {
        library[i].display();
    }
    cout << "\n--- End of Program ---\n";
}

// Example 2: BookShelf with vector-based allocation
void example2() {
    cout << "\n\nEXAMPLE 2: BookShelf using vector\n";
    cout << "----------------------------------\n";

    BookShelf shelf;
    shelf.displayBooks();

    cout << "\n--- End of Program ---\n";
}

int main() {
    // Run both examples
    example1();
    example2();

    // Discussion
    cout << "\nADVANTAGES AND DISADVANTAGES\n";
    cout << "----------------------------\n";
    cout << "Example 1 (Stack-based array):\n";
    cout << "  Advantages: Simpler code, automatic cleanup, no memory leaks\n";
    cout << "  Disadvantages: Fixed size at compile time, can't resize\n\n";
    cout << "Example 2 (Vector-based BookShelf):\n";
    cout << "  Advantages: Dynamic size, safe memory management via vector\n";
    cout << "  Disadvantages: Slightly more abstraction, small runtime overhead\n\n";
    cout << "Role of Destructors:\n";
    cout << "  Destructors ensure cleanup:\n";
    cout << "  - Book destructors are automatically called in both examples\n";
    cout << "  - In Example 2, the vector calls destructors for each Book\n\n";
    cout << "If Destructors Were Removed:\n";
    cout << "  We'd lose destruction messages and risk leaks if dynamic resources existed\n";
    cout << "  With vector, the risk is minimized due to RAII\n";

    return 0;
}
