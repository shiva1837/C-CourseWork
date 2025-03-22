/**************************************************************************************************************/
/*  Author:         Shivamani Jadi                                                                            */
/*  Major:          Computer Science                                                                          */
/*  Creation Date:  March 08, 2025                                                                            */
/*  Section:        CSC 136 010                                                                               */
/*  Due Date:       March 24, 2025                                                                            */
/*  Professor Name: prof. Yong Zhang                                                                          */
/*  Assignment:     Project-3 (Address Book Program)                                                          */
/*  Filename:       project3.cpp                                                                              */
/*  Purpose:        This program reads address data from a file (addressData.txt), populates an               */
/*                  array of extPersonType objects, and provides a menu-driven interface for                  */
/*                  various search and display operations on the address book.                                */
/**************************************************************************************************************/

#include <iostream>        // for cin and cout
#include <fstream>         // for file handling
#include <sstream>         // for string stream
#include <string>          // for string
#include "extPersonType.h" // for employee class

using namespace std;

/*************************************************************************/
/* Function name: main                                                   */
/* Description:   Reads address data from a file, populates an array of  */
/*                extPersonType objects, and provides a menu-driven      */
/*                interface for user operations on the address book.     */
/* Parameters:    none                                                   */
/* Return Value:  int - exit status (0 for success)                      */
/*************************************************************************/

int main() {

  extPersonType aList[100];
    int length = 0;
    
    // Open the address data file.
    ifstream inFile("addressData.txt");
    if (!inFile) {
        cerr << "Error opening addressData.txt file." << endl;
        return 1;
    }
    
    // Read the number of records.
    int count;
    inFile >> count;
    inFile.ignore(); // Ignore newline after count.
    
    for (int i = 0; i < count; i++) {
        // Read first and last names directly using >>
        string firstName, lastName;
        inFile >> firstName >> lastName;
        inFile.ignore(); // Ignore the rest of the line.
        
        int month, day, year;
        inFile >> month >> day >> year;
        inFile.ignore(); // Ignore the newline after the date.
        
        // Read the address and contact information using getline.
        string street, city, state, zip, phone, status;
        getline(inFile, street);
        getline(inFile, city);
        getline(inFile, state);
        getline(inFile, zip);
        getline(inFile, phone);
        getline(inFile, status);
        
        // Set the information for the extPersonType object.
        aList[length].setInfo(firstName, lastName, month, day, year,
                              street, city, state, zip, phone, status);
        length++;
    }
    inFile.close();
    
    int choice;
    do {
        // Display the menu.
        cout << "=========================================" << endl;
        cout << "Welcome to the address book program." << endl;
        cout << "Choose among the following options:" << endl;
        cout << "1: Search a person by last name:" << endl;
        cout << "2: Search a person by birthday:" << endl;
        cout << "3: Print the names of persons having birthday in a particular month" << endl;
        cout << "4: Print the names of persons between two last names" << endl;
        cout << "5: Print the names of persons having a particular status" << endl;
        cout << "6: Terminate the program" << endl;
        cout << "=========================================" << endl;
        cout << "Enter a choice [1-6]: ";
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer.
        
        if (choice == 1) {
            // Option 1: Search by last name.
            cout << "Enter the last name of the person: ";
            string lname;
            getline(cin, lname);
            bool found = false;
            for (int i = 0; i < length; i++) {
                if (aList[i].isLastName(lname)) {
                    aList[i].printInfo();
                    cout << endl;
                    found = true;
                }
            }
            if (!found)
                cout << "No person found with last name: " << lname << endl;
        }
        else if (choice == 2) {
            // Option 2: Search by birthday.
            cout << "Enter the birthday (mm-dd-yyyy): ";
            int m, d, y;
            char dash1, dash2;
            cin >> m >> dash1 >> d >> dash2 >> y;
            cin.ignore(); // Clear newline.
            bool found = false;
            for (int i = 0; i < length; i++) {
                if (aList[i].isDOB(m, d, y)) {
                    aList[i].printInfo();
                    cout << endl;
                    found = true;
                }
            }
            if (!found)
                cout << "No person found with birthday: " << m << "-" << d << "-" << y << endl;
        }
        else if (choice == 3) {
            // Option 3: Print persons with birthday in a given month.
            cout << "Enter the month number: ";
            int m;
            cin >> m;
            cin.ignore();
            bool found = false;
            for (int i = 0; i < length; i++) {
                if (aList[i].isMonth(m)) {
                    cout << aList[i].getFirstName() << " " << aList[i].getLastName() << endl;
                    found = true;
                }
            }
            if (!found)
                cout << "No persons found with birthday in month: " << m << endl;
        }
        else if (choice == 4) {
            // Option 4: Print persons between two last names.
            cout << "Enter starting last name: ";
            string startLast;
            getline(cin, startLast);
            cout << "Enter ending last name: ";
            string endLast;
            getline(cin, endLast);
            bool found = false;
            for (int i = 0; i < length; i++) {
                string currLast = aList[i].getLastName();
                if (currLast >= startLast && currLast <= endLast) {
                    cout << aList[i].getFirstName() << " " << currLast << endl;
                    found = true;
                }
            }
            if (!found)
                cout << "No persons found between last names " << startLast << " and " << endLast << endl;
        }
        else if (choice == 5) {
            // Option 5: Print persons with a particular status.
            cout << "Enter person type Family, Friend, Business: ";
            string status;
            getline(cin, status);
            bool found = false;
            for (int i = 0; i < length; i++) {
                if (aList[i].isStatus(status)) {
                    cout << aList[i].getFirstName() << " " << aList[i].getLastName() << endl;
                    found = true;
                }
            }
            if (!found)
                cout << "No persons found with status: " << status << endl;
        }
        else if (choice == 6) {
            cout << "Program terminated." << endl;
        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);
    
    return 0;
}
