#include "employeeType.h"
#include <iostream>

using namespace std;

// Default constructor
employeeType::employeeType() : employeeID(0), firstName(""), lastName(""), position(""), salary(0.0), department(""), yearsOfExperience(0) {}

// Constructors with Parameters
employeeType::employeeType(int id, string fName, string lName, string pos, double sal, string dept, int exp) {
    setEmployeeID(id);        // Call mutator method to set employee ID
    setFirstName(fName);      // Call mutator method to set first name
    setLastName(lName);       // Call mutator method to set last name
    setPosition(pos);         // Call mutator method to set position
    updateSalary(sal);        // Call mutator method to set salary
    setDepartment(dept);      // Call mutator method to set department
    yearsOfExperience = exp;  // Set years of experience
}

// Mutator methods (Setter Functions)
void employeeType::setEmployeeID(int id) {
    if (id < 0) {  // Using if-else to ensure employeeID is not negative
        employeeID = 0;
    } else {
        employeeID = id;
    }
}

void employeeType::setFirstName(const string& fName) {
    firstName = fName;
}

void employeeType::setLastName(const string& lName) {
    lastName = lName;
}

void employeeType::setPosition(const string& pos) {
    position = pos;
}

void employeeType::setDepartment(const string& dept) {
    department = dept;
}

void employeeType::updateSalary(double sal) {
    if (sal >= 0) {  // Ensure salary is not negative
        salary = sal;
    }
}

void employeeType::setYearsOfExperience(int exp) {
    yearsOfExperience = exp;
}

// Accessor methods (Getter Functions)
int employeeType::getEmployeeID() const {
    return employeeID;
}

string employeeType::getFullName() const {
    return firstName + " " + lastName;
}

string employeeType::getPosition() const {
    return position;
}

double employeeType::getSalary() const {
    return salary;
}

string employeeType::getDepartment() const {
    return department;
}

int employeeType::getYearsOfExperience() const {
    return yearsOfExperience;
}

// Print employee details
void employeeType::print() const {
    cout << "--------------------------------------" << endl;
    cout << "Employee ID    : " << employeeID << endl;
    cout << "Name           : " << getFullName() << endl;
    cout << "Position       : " << position << endl;
    cout << "Salary         : $" << salary << endl;
    cout << "Department     : " << department << endl;
    cout << "Years of Exp.  : " << yearsOfExperience << " years" << endl;
    cout << "--------------------------------------" << endl;
}
