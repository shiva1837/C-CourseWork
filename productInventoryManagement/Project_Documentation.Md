# Product Inventory Management System

## Project Description
The **Product Inventory Management System** is a C++ program that reads product data from a file, stores it in a structured array, and performs various operations such as:
- Displaying all product details
- Identifying the most expensive product
- Finding products with the lowest stock level

## Features
- Reads product information from an external file (`productData.txt`)
- Stores product details using a structured data type
- Displays product inventory in a formatted table
- Identifies and displays the most expensive product
- Finds and lists products with the lowest stock availability

## Installation & Setup
1. Ensure you have a C++ compiler installed (e.g., GCC, Clang, MSVC).
2. Place `productData.txt` in the same directory as the executable.
3. Compile the program using two Methods: 
   ### Method: 01 (Using the MakeFile)
         Follow these steps to compile and run the program using the `Makefile`:
         Step: 01 makesure 'MakeFile' is in the same directory as the executable.
         Step: 02 Compile the Porgram: 
                  make
                  
         Step: 03 Run the program: 
                  make test
                  
         Step: 04 Remove the compile a.out file: 
                  rm a.out
      
   ### Method: 02 (using Manual Commands) 
         Alternatively, you can compile and run the program manually using the following steps:
         Step: 01 Compile the Porgram: 
                  g++ project1.cpp -o inventory_manager
   
         Step: 02 Run the program:
                  ./inventory_manager
                  

## File Structure
```
|-- MakeFile                         # File comiles Program
|-- project1.cpp                     # Main program file
|-- productData.txt                  # Input file containing product data
```

## Usage
Upon execution, the program will:
1. Load product data from `productData.txt`.
2. Display a list of products with their details.
3. Identify and show the most expensive product.
4. Display products with the lowest stock.

## License
This project is licensed under the MIT License. See '[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)` file for details.

## Author
**Shivamani Jadi**
- Computer Science Major
- Kutztown University of Pennsylvania
