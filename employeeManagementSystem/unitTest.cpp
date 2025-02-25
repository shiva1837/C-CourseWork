#define CATCH_CONFIG_MAIN  

#include <string>
#include "/export/home/public/zhang/catch.hpp"
#include "employeeType.h"

string firstName = "John";
string lastName = "Doe";
string position = "Manager";
string department = "HR";
int employeeID = 101;
double salary = 50000.0;
int yearsOfExperience = 10;

TEST_CASE("Test Default Constructor") {
    employeeType emp;

    REQUIRE(emp.getEmployeeID() == 0);
    REQUIRE(emp.getFullName() == " ");
    REQUIRE(emp.getPosition() == "");
    REQUIRE(emp.getSalary() == 0.0);
    REQUIRE(emp.getDepartment() == "");
    REQUIRE(emp.getYearsOfExperience() == 0);
}

TEST_CASE("Test Parameterized Constructor") {
    employeeType emp(employeeID, firstName, lastName, position, salary, department, yearsOfExperience);

    REQUIRE(emp.getEmployeeID() == employeeID);
    REQUIRE(emp.getFullName() == "John Doe");
    REQUIRE(emp.getPosition() == position);
    REQUIRE(emp.getSalary() == salary);
    REQUIRE(emp.getDepartment() == department);
    REQUIRE(emp.getYearsOfExperience() == yearsOfExperience);
}

TEST_CASE("Test Setters") {
    employeeType emp;

    emp.setEmployeeID(123);
    emp.setFirstName("Alice");
    emp.setLastName("Smith");
    emp.setPosition("Engineer");
    emp.setDepartment("R&D");

    REQUIRE(emp.getEmployeeID() == 123);
    REQUIRE(emp.getFullName() == "Alice Smith");
    REQUIRE(emp.getPosition() == "Engineer");
    REQUIRE(emp.getDepartment() == "R&D");
}

TEST_CASE("Test Salary Update") {
    employeeType emp(employeeID, firstName, lastName, position, salary, department, yearsOfExperience);

    emp.updateSalary(60000.0);  // valid update
    REQUIRE(emp.getSalary() == 60000.0);

    emp.updateSalary(-1000.0);  // invalid update, salary should not change
    REQUIRE(emp.getSalary() == 60000.0);
}

TEST_CASE("Test Invalid Values in Constructor") {
    employeeType emp(-1, "Negative", "ID", "Technician", -5000.0, "Maintenance", 5);

    REQUIRE(emp.getEmployeeID() == 0);  // ID should be reset to 0
    REQUIRE(emp.getSalary() == 0.0);   // Salary should be reset to 0
}

TEST_CASE("Test Print Method") {
    employeeType emp(employeeID, firstName, lastName, position, salary, department, yearsOfExperience);

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    emp.print();

    std::string expectedOutput = "--------------------------------------\n"
                                 "Employee ID    : 101\n"
                                 "Name           : John Doe\n"
                                 "Position       : Manager\n"
                                 "Salary         : $50000\n"
                                 "Department     : HR\n"
                                 "Years of Exp.  : 10 years\n"
                                 "--------------------------------------\n";

    REQUIRE(output.str() == expectedOutput);

    // Restore original cout buffer
    std::cout.rdbuf(oldCout);
}

TEST_CASE("Test Update with Negative ID and Salary") {
    employeeType emp;

    emp.setEmployeeID(-100);
    emp.updateSalary(-2000.0);

    REQUIRE(emp.getEmployeeID() == 0);  // ID should be reset to 0
    REQUIRE(emp.getSalary() == 0.0);   // Salary should be reset to 0
}
