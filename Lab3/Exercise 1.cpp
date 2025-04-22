#include <iostream>
using namespace std;

class Book {
private:
    string title;
    int pages;
    string author = "Ashes Ranjit";

protected:
    float price;

public:
    string publisher;

    void setTitle(string t) {
        title = t;
    }

    string getTitle() {
        return title;
    }

    void displayAuthorInfo() {
        cout << "Author: " << author << endl;
    }
};

int main() {
    Book myBook;

    // Part A: Try to access private attribute (will cause compilation error if uncommented)
    // myBook.title = "C++ Programming";  // ❌ ERROR
    // cout << "Title: " << myBook.title << endl;

    // Correct way using setter and getter:
    myBook.setTitle("C++ Programming");
    cout << "Title: " << myBook.getTitle() << endl;

    // Part B: Accessing public member
    myBook.publisher = "O'Reilly Media";
    cout << "Publisher: " << myBook.publisher << endl;

    // Part C: Display author info via public method
    myBook.displayAuthorInfo();

    return 0;
}
