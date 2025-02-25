
# Employee Management System

This repository contains the implementation of an **Employee Management System** project. It includes functionality to manage employee records, such as updating their salary, searching by experience, and more. The system also includes unit tests and demo files for testing purposes.

## Files Included

The following files are included in the project:

- **Makefile**: The build script for compiling and testing the project.
- **employee.dat**: Sample employee data file used for testing the system.
- **employeeType.h**: Header file containing the `employeeType` class declaration and method prototypes.
- **employeeTypeImp.cpp**: Implementation file for the `employeeType` class methods.
- **input**: Sample input data file used in the program.
- **project2.cpp**: Main application file where user interaction and employee management functions are implemented.
- **project2Demo**: Demo file to execute the program. You can run the file using `./project2Demo`.
- **unitTest**: Directory containing unit testing files.
- **unitTest.cpp**: File containing unit test cases for testing the functionality of the employee management system.

## Project Overview

The Employee Management System provides a simple way to store, manage, and update employee records. The system supports the following functionalities:

- Adding new employees
- Displaying all employees
- Modifying employee information (such as salary)
- Searching for employees based on different criteria (e.g., ID, experience)
  
### Demo File (`project2Demo`)

The **project2Demo** file contains the executable for running the program. To run the program, use the following command in the terminal:

```bash
./project2Demo
```

### Makefile Instructions

You can compile and test the project using the following make commands:

- **Compiling the Program**:
  To compile the program, use:
  
  ```bash
  make
  ```

  This is equivalent to running:
  
  ```bash
  g++ project2.cpp employeeTypeImp.cpp
  ```

  This will generate an `a.out` file.

- **Unit Test for `employeeTypeImp.cpp`**:
  To run the unit tests on the `employeeTypeImp.cpp` file, use:
  
  ```bash
  make test1
  ```

  The output should look like this:
  
  ```
  =================================================
  All tests passed (22 assertions in 3 test cases)
  ```

- **Unit Test for `project2.cpp`**:
  To run the unit tests on the `project2.cpp` file, use:
  
  ```bash
  make test2
  ```

## Setting Up the Project

1. Clone the repository to your local machine:
   
   ```bash
   git clone https://github.com/your-username/employeeManagementSystem.git
   ```

2. Navigate to the project directory:
   
   ```bash
   cd employeeManagementSystem
   ```

3. Compile the program using the `make` command:
   
   ```bash
   make
   ```

4. Run the demo:
   
   ```bash
   ./project2Demo
   ```

## Contribution Guidelines

If you would like to contribute to the project, feel free to fork the repository and create a pull request. Please ensure that your changes are well-documented and include unit tests for any new functionality.
