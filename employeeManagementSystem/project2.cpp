/**************************************************************************************************************/
/*  Author:         Shivamani Jadi
/*  Major:          Computer Science
/*  Creation Date:  february 25, 2025 
/*  Section:        CSC 136 010
/*  Due Date:       Februrary 26, 2025
/*  Professor Name: prof. Yong Zhang covered by (Prof. Walter) 
/*  Assignment:     Project-2 (Employee Management System)   
/*  Purpose:        This program is designed to manage employee records. 
/*                  The program will read employee records from a file, 
/*                  store them in an array of employee objects, 
/*                  and provide a menu to perform various operations on the employee records. 
/*                  The program will allow the user to display all employees, 
/*                  search for an employee by ID, update an employee's salary, 
/*                  search for employees by department, and search for employees by experience. 
/*                  The program will continue to display the menu until the user chooses to exit the program.        
/*                             
/**************************************************************************************************************/

#include <iostream> // For input and output
#include <fstream>  // For file input and output
#include <string>  // For output formatting
#include "employeeType.h" // For employeeType class

using namespace std;

const int MAX_EMPLOYEES = 100;

//function prototypes
// Function Prototypes
  void loadEmployees(const string& filename, employeeType employees[], int &count);
  void displayMenu();
  void displayAllEmployees(employeeType employees[], int count);
  int searchByID(employeeType employees[], int count, int id);
  void updateSalary(employeeType employees[], int count, int id, double salary);
  void searchByDepartment(employeeType employees[], int count, string dept);
  void searchByExperience(employeeType employees[], int count, int exp);


// ** Main Function **
int main() {
  employeeType employees[MAX_EMPLOYEES];
  int count = 0;
  loadEmployees("employee.dat", employees, count);

  int choice;
  do {
      displayMenu();
      cin >> choice;

      switch (choice) {
          case 1:
              displayAllEmployees(employees, count);
              break;
          case 2:
              searchByID(employees, count, 0); // ID entered inside function
              break;
          case 3:
              updateSalary(employees, count, 0, 0.0);
              break;
          case 4:
              searchByDepartment(employees, count, "");
              break;
          case 5:
              searchByExperience(employees, count, 0);
              break;
          case 6:
              cout << "Exiting Program..." << endl;
              break;
          default:
              cout << "Invalid Choice. Please try again.\n";
      }
  } while (choice != 6);

  return 0;
}


// funciton to load employees from data file ('employee.dat')
void loadEmployees(const string& filename, employeeType employees[], int &count) {
  ifstream file(filename);
  if (!file) {
      cout << "Error Opening File: '" << filename << "'" << endl;
      exit(1);
  }

  count = 0;
  int id, exp;
  double salary;
  string fName, lName, pos, dept;
  while (file >> id >> fName >> lName >> pos >> salary >> dept >> exp && count < MAX_EMPLOYEES) {
      employees[count] = employeeType(id, fName, lName, pos, salary, dept, exp);
      count++;
  }
}

// Function to display Menu 
void displayMenu() {
  cout << "\n===== Welcome to Employee Management System =====\n";
  cout << "1. Print all employees\n";
  cout << "2. Search an employee by ID\n";
  cout << "3. Update an employee's salary\n";
  cout << "4. Search employees by department\n";
  cout << "5. Search employees by experience\n";
  cout << "6. Exit\n";
  cout << "Enter your choice: ";
}
// Function to print all employee names and IDs
void displayAllEmployees(employeeType employees[], int count) {
  for (int i = 0; i < count; i++) {
    employees[i].print();
  }
}

// Function to search employee by ID
// Function to search employee by ID and return index
int searchByID(employeeType employees[], int count, int id) {
  cout << "Enter Employee ID: ";
  cin >> id;

  for (int i = 0; i < count; i++) {
      if (employees[i].getEmployeeID() == id) {
          employees[i].print();
          return i; // Found, return index
      }
  }
  cout << "Employee with ID " << id << " not found.\n";
  return -1; // Not found
}

// Function to update employee salary
void updateSalary(employeeType employees[], int count, int id, double salary) {
    int index = searchByID(employees, count, id);
    if (index == -1) return; // Exit if employee not found

    cout << "Enter new salary: ";
    while (!(cin >> salary) || salary < 0) {
        cout << "Invalid input. Enter a valid salary: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    employees[index].updateSalary(salary);
     cout << "Employee with ID: " << id << " salary updated to: " << salary << endl;
}


// Function to search employee by department
void searchByDepartment(employeeType employees[], int count, string dept) {
  cout << "Enter Department Name: ";
  cin >> dept;
  
  for (int i = 0; i < count; i++) {
    if (employees[i].getDepartment() == dept) {
      employees[i].print();
    }
  }
}

// Function to search employee by minimum years of experience
void searchByExperience(employeeType employees[], int count, int exp) {
  cout << "Enter Minimum Years of Experience: ";
  cin >> exp; 

  for (int i = 0; i < count; i++) {
    if (employees[i].getYearsOfExperience() >= exp) {
      employees[i].print();
    }
  }
}
