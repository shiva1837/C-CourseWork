
# Complex Number Operations Project

## Overview
Hey there! Welcome to the Complex Number Operations project—a cool C++ playground where complex numbers (think: `a + bi`) get the star treatment. This project brings together traditional C++ techniques with a modern twist, showing off operator overloading in all its glory. Whether you're a seasoned coder or just curious about how complex arithmetic works, you're in the right place.

## Files Included
- **complexType.h**  
  Declares the `complexType` class for representing complex numbers. It overloads arithmetic, comparison, increment/decrement, and I/O operators.

- **complexTypeImp.cpp**  
  Contains the implementation of the functions declared in `complexType.h`. This file is where the mathematical magic happens.

- **main.cpp**  
  Demonstrates how to use the `complexType` class. Run this to see examples of creating, manipulating, and displaying complex numbers.

- **unitTest.cpp**  
  A suite of unit tests built with Catch2 to ensure that all our operations behave as expected. Test-driven development never looked so good!

- **Makefile**  
  Used to build all the source files smoothly.

- **input1**  
  An extra input file used for testing.

## Features
- **Arithmetic Operators:**  
  Easily add, subtract, multiply, and even divide your complex numbers. (Warning: Division by zero? It just returns the original number, a bit like how some things in life never change.)

- **Comparison Operators:**  
  Compare complex numbers based on their magnitudes—because sometimes size does matter!

- **Increment & Decrement Operators:**  
  Both pre- and post- versions allow you to tweak the real part of your numbers, giving you a little extra control over your operations.

- **Stream I/O Overloads:**  
  Custom `<<` and `>>` operators make sure your complex numbers always look fresh, formatted to two decimal places.

## Getting Started

### Dependencies
- A C++ compiler with support for C++11 (or later).
- [Catch2](https://github.com/catchorg/Catch2) for unit testing.

### Installation & Compilation
1. **Clone the Repository:**
   ```bash
   git clone https://github.com/<your-username>/<repository-name>.git
   cd <repository-name>
   ```
2. **Build the Project:**
   Use the provided Makefile:
   ```bash
   make
   ```

## Running the Project
- **Example Program:**
  Simply run the output binary:
  ```bash
  ./main
  ```

## Running Unit Tests
- **Using Makefile (if available):**
  ```bash
  make test
  ```
- **Manual Compilation:**
  Compile the unit test file along with your implementation using Catch2:
  ```bash
  g++ -std=c++11 -o test unitTest.cpp complexTypeImp.cpp -I/path/to/catch2
  ./test
  ```

## Project Details & Credits
- **Author:** Shivamani Jadi
- **Course:** CSC 136 010
- **Professor:** Prof. Yong Zhang
- **Assignment:** Project 4 (Complex Number Operations)
- **Due Date:** 04/07/2025

## Contributing
Pull requests are welcome! Fork it, tweak it, and make a PR. Keep the vibe traditional, but the thinking futuristic.

## License
MIT License

## Final Thoughts
At the end of the day, programming—much like complex numbers—is all about finding balance in chaos. So dive in, experiment, and most importantly, have fun while learning.

Happy coding!
