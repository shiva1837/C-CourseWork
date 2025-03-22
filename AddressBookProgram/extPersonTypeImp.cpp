/**************************************************************************************************************/
/*  Author:         Shivamani Jadi                                                                            */
/*  Major:          Computer Science                                                                          */
/*  Creation Date:  March 08, 2025                                                                            */
/*  Section:        CSC 136 010                                                                               */
/*  Due Date:       March 24, 2025                                                                            */
/*  Professor Name: prof. Yong Zhang                                                                          */
/*  Assignment:     Project-3 (Address Book Program)                                                          */
/*  Filename:       extPersonTypeImp.cpp                                                                      */
/*  Purpose:        Implements the extPersonType class methods. This class is used in the address             */
/*                  book program to store and manage detailed information about a person including            */
/*                  name, date of birth, address, phone number, and status.                                   */
/**************************************************************************************************************/

// This file contains the header files and the using directives
#include <iostream>
#include <string>          // for string class
#include "extPersonType.h" // for extPersonType class

using namespace std;

/*************************************************************************/
/* Function name: printInfo                                              */
/* Description:   Prints the full information of the person including    */
/*                name, date of birth, phone number, person type, and    */
/*                address.                                               */
/* Parameters:    none - uses class members - input                      */
/* Return Value:  none                                                   */
/*************************************************************************/
void extPersonType::printInfo() const {
    // Print first and last name (from the base class personType)
    personType::print();
    cout << "\nDate of Birth: ";
    dob.printDate();
    cout << "\nPhone Number: " << phoneNumber
         << "\nPerson Type: " << personStatus << "\n";
    // Print the address information (addressType::print should format it accordingly)
    address.print();
}

/****************************************************************************/
/* Function name: setInfo                                                   */
/* Description:   Sets all information for a person, including name,        */
/*                date of birth, address, phone number, and person status.  */
/* Parameters:    string fName: first name - input                          */
/*                string lName: last name - input                           */
/*                int month: birth month - input                            */
/*                int day: birth day - input                                */
/*                int year: birth year - input                              */
/*                string street: street address - input                     */
/*                string c: city - input                                    */
/*                string s: state - input                                   */
/*                string z: zip code - input                                */
/*                string phone: phone number - input                        */
/*                string pStatus: person status - input                     */
/* Return Value:  none                                                      */
/****************************************************************************/
void extPersonType::setInfo(string fName, string lName,
                            int month, int day, int year,
                            string street, string c, string s, string z,
                            string phone, string pStatus) {
    setName(fName, lName);               // Set the name (from personType)
    dob.setDate(month, day, year);       // Set the date of birth
    address.setAddress(street, c, s, z); // Set the address information
    phoneNumber = phone;
    personStatus = pStatus;
}

/***************************************************************************/
/* Function name: isLastName                                               */
/* Description:   Checks if the person's last name matches the given name. */
/* Parameters:    string lName: last name to compare - input               */
/* Return Value:  bool - true if match, false otherwise                    */
/***************************************************************************/
bool extPersonType::isLastName(string lName) const {
    return (getLastName() == lName);
}

/*************************************************************************/
/* Function name: getAddress                                             */
/* Description:   Retrieves the address information and stores it in the */
/*                provided reference parameters.                         */
/* Parameters:    string &sAddress: street address - output              */
/*                string &c: city - output                               */
/*                string &s: state - output                              */
/*                string &z: zip code - output                           */
/* Return Value:  none                                                   */
/*************************************************************************/
void extPersonType::getAddress(string &sAddress, string &c, string &s, string &z) {
    address.getAddress(sAddress, c, s, z);
}

/****************************************************************************/
/* Function name: getStatus                                                 */
/* Description:   Returns the person's status (e.g., Family, Friend, etc.). */
/* Parameters:    none                                                      */
/* Return Value:  string - the person's status                              */
/****************************************************************************/
string extPersonType::getStatus() const {
    return personStatus;
}

/*************************************************************************/
/* Function name: getPhoneNumber                                         */
/* Description:   Returns the person's phone number.                     */
/* Parameters:    none                                                   */
/* Return Value:  string - the phone number                              */
/*************************************************************************/
string extPersonType::getPhoneNumber() const {
    return phoneNumber;
}

/***************************************************************************/
/* Function name: isStatus                                                 */
/* Description:   Checks if the person's status matches the given status.  */
/* Parameters:    string status: status to compare - input                 */
/* Return Value:  bool - true if match, false otherwise                    */
/***************************************************************************/
bool extPersonType::isStatus(string status) {
    return (personStatus == status);
}

/*************************************************************************/
/* Function name: isDOB                                                  */
/* Description:   Checks if the person's date of birth matches the given */
/*                date.                                                  */
/* Parameters:    int month: birth month - input                         */
/*                int day: birth day - input                             */
/*                int year: birth year - input                           */
/* Return Value:  bool - true if date of birth matches, false otherwise  */
/*************************************************************************/
bool extPersonType::isDOB(int month, int day, int year) {
    return (dob.getMonth() == month &&
            dob.getDay() == day &&
            dob.getYear() == year);
}

/****************************************************************************/
/* Function name: getDOB                                                    */
/* Description:   Retrieves the date of birth and stores it in the provided */
/*                reference parameters.                                     */
/* Parameters:    int &month: birth month - output                          */
/*                int &day: birth day - output                              */
/*                int &year: birth year - output                            */
/* Return Value:  none                                                      */
/****************************************************************************/
void extPersonType::getDOB(int &month, int &day, int &year) {
    month = dob.getMonth();
    day = dob.getDay();
    year = dob.getYear();
}

/******************************************************************************/
/* Function name: isMonth                                                     */
/* Description:   Checks if the person's birth month matches the given month. */
/* Parameters:    int month: month to compare - input                         */
/* Return Value:  bool - true if match, false otherwise                       */
/******************************************************************************/
bool extPersonType::isMonth(int month) const {
    return (dob.getMonth() == month);
}

/******************************************************************************/
/* Function name: extPersonType (constructor)                                 */
/* Description:   Constructs an extPersonType object with provided initial    */
/*                values for name, date of birth, address, phone, and status. */
/* Parameters:    string fName: first name - input                            */
/*                string lName: last name - input                             */
/*                int month: birth month - input                              */
/*                int day: birth day - input                                  */
/*                int year: birth year - input                                */
/*                string street: street address - input                       */
/*                string c: city - input                                      */
/*                string s: state - input                                     */
/*                string z: zip code - input                                  */
/*                string phone: phone number - input                          */
/*                string pStatus: person status - input                       */
/* Return Value:  none                                                        */
/******************************************************************************/
extPersonType::extPersonType(string fName, string lName,
                             int month, int day, int year,
                             string street, string c, string s, string z,
                             string phone, string pStatus)
    : personType(fName, lName), 
      dob(month, day, year), 
      address(street, c, s, z), 
      phoneNumber(phone), 
      personStatus(pStatus)
{
    // All initialization is handled in the initializer list.
}