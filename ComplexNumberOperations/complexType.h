/**************************************************************************************************************/
/*  Author:         Shivamani Jadi                                                                            */
/*  Major:          Computer Science                                                                          */
/*  Creation Date:  04/04/2025                                                                                */
/*  Section:        CSC 136 010                                                                               */
/*  Due Date:       04/07/2025                                                                                */
/*  Professor Name: Prof. Yong Zhang                                                                          */
/*  Assignment:     Project 4 (Complex Number Operations)                                                     */
/*  Filename:       complexType.h                                                                             */
/*  Purpose:        This file declares the complexType class, which represents a complex number in the form   */
/*                  (a + bi). It provides operator overloads for arithmetic, stream input/output, comparison, */
/*                  and increment/decrement operations.                                                       */
/**************************************************************************************************************/

#ifndef H_complex
#define H_complex

#include <iostream>
#include <cmath>

using namespace std;

/****************************************************************************************************/
/* Class Name:   complexType                                                                        */
/* Description:  Represents a complex number (a + bi). Supports:                                    */
/*               1) Construction with default parameters                                            */
/*               2) Stream insertion and extraction                                                 */
/*               3) Arithmetic operators: +, -, *, /                                                */
/*               4) Comparison operators: ==, !=, <, <=, >, >=                                      */
/*               5) Pre- and post-increment, and pre- and post-decrement                            */
/****************************************************************************************************/
class complexType
{
public:
    /*************************************************************************/
    /* Function Name: complexType                                            */
    /* Description:   Constructs a complex number with given real and        */
    /*                imaginary parts (defaults to 0.0).                     */
    /* Parameters:    r (double) - the real part                             */
    /*                i (double) - the imaginary part                        */
    /* Return Value:  none (constructor)                                     */
    /*************************************************************************/
    complexType(double r = 0.0, double i = 0.0);

    /*************************************************************************/
    /* Function Name: operator<<                                             */
    /* Description:   Overloaded stream insertion operator. Outputs the      */
    /*                complex number in the format: (a + bi).                */
    /* Parameters:    out (ostream&) - output stream                         */
    /*                c (const complexType&) - reference to complex object   */
    /* Return Value:  ostream& (reference to the output stream)              */
    /*************************************************************************/
    friend ostream& operator<<(ostream &out, const complexType &c);

    /*************************************************************************/
    /* Function Name: operator>>                                             */
    /* Description:   Overloaded stream extraction operator. Reads the       */
    /*                real and imaginary parts from the input stream.        */
    /* Parameters:    in (istream&) - input stream                           */
    /*                c (complexType&) - reference to complex object         */
    /* Return Value:  istream& (reference to the input stream)               */
    /*************************************************************************/
    friend istream& operator>>(istream &in, complexType &c);

    /*************************************************************************/
    /* Function Name: operator+                                              */
    /* Description:   Adds two complex numbers.                              */
    /* Parameters:    other (const complexType&)                             */
    /* Return Value:  complexType - sum of the two complex numbers           */
    /*************************************************************************/
    complexType operator+(const complexType &other) const;

    /*************************************************************************/
    /* Function Name: operator-                                              */
    /* Description:   Subtracts another complex number from this one.        */
    /* Parameters:    other (const complexType&)                             */
    /* Return Value:  complexType - result of the subtraction                */
    /*************************************************************************/
    complexType operator-(const complexType &other) const;

    /*************************************************************************/
    /* Function Name: operator*                                              */
    /* Description:   Multiplies two complex numbers.                        */
    /* Parameters:    other (const complexType&)                             */
    /* Return Value:  complexType - product of the two complex numbers       */
    /*************************************************************************/
    complexType operator*(const complexType &other) const;

    /*************************************************************************/
    /* Function Name: operator/                                              */
    /* Description:   Divides this complex number by another. If the         */
    /*                denominator is zero, returns the left operand.         */
    /* Parameters:    other (const complexType&)                             */
    /* Return Value:  complexType - result of the division                   */
    /*************************************************************************/
    complexType operator/(const complexType &other) const;

    /*************************************************************************/
    /* Function Name: operator==                                             */
    /* Description:   Checks if two complex numbers have equal real and      */
    /*                imaginary parts.                                       */
    /* Parameters:    other (const complexType&)                             */
    /* Return Value:  bool - true if both real and imaginary parts match,    */
    /*                false otherwise                                        */
    /*************************************************************************/
    bool operator==(const complexType &other) const;

    /*************************************************************************/
    /* Function Name: operator!=                                             */
    /* Description:   Checks if two complex numbers are not equal.           */
    /* Parameters:    other (const complexType&)                             */
    /* Return Value:  bool - true if real or imaginary parts differ,         */
    /*                false otherwise                                        */
    /*************************************************************************/
    bool operator!=(const complexType &other) const;

    /*************************************************************************/
    /* Function Name: operator<                                              */
    /* Description:   Compares the magnitudes (absolute values) of two       */
    /*                complex numbers and checks if this < other.            */
    /* Parameters:    other (const complexType&)                             */
    /* Return Value:  bool - true if magnitude of this is less, false        */
    /*                otherwise                                              */
    /*************************************************************************/
    bool operator<(const complexType &other) const;

    /*************************************************************************/
    /* Function Name: operator<=                                             */
    /* Description:   Compares the magnitudes (absolute values) of two       */
    /*                complex numbers and checks if this <= other.           */
    /* Parameters:    other (const complexType&)                             */
    /* Return Value:  bool - true if magnitude of this is <= other's,        */
    /*                false otherwise                                        */
    /*************************************************************************/
    bool operator<=(const complexType &other) const;

    /*************************************************************************/
    /* Function Name: operator>                                              */
    /* Description:   Compares the magnitudes (absolute values) of two       */
    /*                complex numbers and checks if this > other.            */
    /* Parameters:    other (const complexType&)                             */
    /* Return Value:  bool - true if magnitude of this is greater, false     */
    /*                otherwise                                              */
    /*************************************************************************/
    bool operator>(const complexType &other) const;

    /*************************************************************************/
    /* Function Name: operator>=                                             */
    /* Description:   Compares the magnitudes (absolute values) of two       */
    /*                complex numbers and checks if this >= other.           */
    /* Parameters:    other (const complexType&)                             */
    /* Return Value:  bool - true if magnitude of this is >= other's,        */
    /*                false otherwise                                        */
    /*************************************************************************/
    bool operator>=(const complexType &other) const;

    /*************************************************************************/
    /* Function Name: operator++                                             */
    /* Description:   Pre-increment: increments the real part of the         */
    /*                complex number by 1, then returns *this.               */
    /* Parameters:    none                                                   */
    /* Return Value:  complexType& (reference to the updated object)         */
    /*************************************************************************/
    complexType& operator++();    // Pre-increment

    /*************************************************************************/
    /* Function Name: operator++(int)                                        */
    /* Description:   Post-increment: returns a copy of the current object,  */
    /*                then increments the real part of the complex number    */
    /*                by 1.                                                  */
    /* Parameters:    int (dummy parameter to differentiate post-increment)  */
    /* Return Value:  complexType - the original value before increment      */
    /*************************************************************************/
    complexType operator++(int);  // Post-increment

    /*************************************************************************/
    /* Function Name: operator--                                             */
    /* Description:   Pre-decrement: decrements the real part of the         */
    /*                complex number by 1, then returns *this.               */
    /* Parameters:    none                                                   */
    /* Return Value:  complexType& (reference to the updated object)         */
    /*************************************************************************/
    complexType& operator--();    // Pre-decrement

    /*************************************************************************/
    /* Function Name: operator--(int)                                        */
    /* Description:   Post-decrement: returns a copy of the current object,  */
    /*                then decrements the real part of the complex number    */
    /*                by 1.                                                  */
    /* Parameters:    int (dummy parameter to differentiate post-decrement)  */
    /* Return Value:  complexType - the original value before decrement      */
    /*************************************************************************/
    complexType operator--(int);  // Post-decrement

private:
    double realPart; // Real part of the complex number
    double imagPart; // Imaginary part of the complex number

    /*************************************************************************/
    /* Function Name: magnitude                                              */
    /* Description:   Computes the magnitude (absolute value) of the         */
    /*                complex number.                                        */
    /* Parameters:    none                                                   */
    /* Return Value:  double - the magnitude (sqrt(real^2 + imag^2))         */
    /*************************************************************************/
    double magnitude() const { return sqrt((realPart * realPart) + (imagPart * imagPart)); }
};

#endif
