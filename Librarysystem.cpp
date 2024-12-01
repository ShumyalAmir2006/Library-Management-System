#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class temp {
    string id, name, author, search;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
} obj;

void temp::addBook() {
    cout << "\nEnter Book ID :: ";
    getline(cin, id);
    cout << "Enter Book Name :: ";
    getline(cin, name);
    cout << "Enter Author's Name :: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    file << id << "*" << name << "*" << author << endl;
    file.close();
    cout << "Book added successfully!\n";
}

void temp::showAll() {
    file.open("bookData.txt", ios::in);
    if (!file) {
        cout << "Error opening file for reading or no books available!" << endl;
        return;
    }

    cout << "\n\n\t\t Book ID \t\t Book Name \t\t Author's Name\n";
    cout << "--------------------------------------------------------------------------------\n";
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n')) {
        cout << "\t\t " << id << " \t\t " << name << " \t\t " << author << endl;
    }
    file.close();
}

void temp::extractBook() {
    cout << "Enter Book ID to search: ";
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    if (!file) {
        cout << "Error opening file or no books available!" << endl;
        return;
    }

    bool found = false;
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n')) {
        if (search == id) {
            if (!found) {
                cout << "\n\n\t\t Book ID \t\t Book Name \t\t Author's Name\n";
                cout << "--------------------------------------------------------------------------------\n";
            }
            cout << "\t\t " << id << " \t\t " << name << " \t\t " << author << endl;
            found = true;
        }
    }
    file.close();

    if (found) {
        cout << "\nBook is extracted successfully!\n";
    } else {
        cout << "\nBook with ID \"" << search << "\" not found!\n";
    }
}

int main() {
    char choice;
    while (true) {
        cout << "\n________________________________________\n";
        cout << "1) Show All Books\n";
        cout << "2) Extract a Book\n";
        cout << "3) Add a Book [Admin]\n";
        cout << "4) Exit\n";
        cout << "________________________________________\n";
        cout << "Enter Your Choice :: ";
        cin >> choice;
        cin.ignore(); // To handle leftover newline from previous input

        switch (choice) {
        case '1':
            obj.showAll();
            break;
        case '2':
            obj.extractBook();
            break;
        case '3':
            obj.addBook();
            break;
        case '4':
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid Choice! Please try again.\n";
        }
    }
    return 0;
}
