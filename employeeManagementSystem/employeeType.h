#include <iostream>
#include <string>

using namespace std;

class employeeType {

public:
    // default Constructor
    employeeType();

    //constructor, set given inputs to object
    // if ID is negative, set to zero instead
    // if salary is negative, set to zero instead
    employeeType(int, string, string, string, double, string, int);

    //mutator methods for individual component
    void setEmployeeID(int);  // if ID is negative, set to zero instead
    void setFirstName(const string& fName); // if fName is empty, set to "Unknown" instead
    void setLastName(const string& lName);  // if lName is empty, set to "Unknown" instead
    void setPosition(const string& pos);    // if pos is empty, set to "Unknown" instead
    void setDepartment(const string& dept); // if dept is empty, set to "Unknown" instead
    void setYearsOfExperience(int exp);     // if exp is negative, set to zero instead
    void updateSalary(double);              // if the new salary is negative, don't update
    
    // access methods
    int getEmployeeID() const;
    string getFullName() const;  //returns first name, followed by a space, followed by last name
    string getPosition() const;
    double getSalary() const;
    string getDepartment() const;
    int getYearsOfExperience() const;

    /*
    outputs a format like the following:
    
    --------------------------------------
    Employee ID    : 103
    Name           : Bob Brown
    Position       : Technician
    Salary         : $55000
    Department     : Maintenance
    Years of Exp.  : 8 years
--------------------------------------
    */

    void print() const;
    

private:
    int employeeID;
    string firstName;
    string lastName;
    string position;
    double salary;
    string department;
    int yearsOfExperience;

};

