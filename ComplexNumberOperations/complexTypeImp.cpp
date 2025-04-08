/******************************************************************************************************************/
/*  Author:         Shivamani Jadi                                                                                */
/*  Major:          Computer Science                                                                              */
/*  Creation Date:  04/04/2025                                                                                    */
/*  Section:        CSC 136 010                                                                                   */
/*  Due Date:       04/07/2025                                                                                    */
/*  Professor Name: Prof. Yong Zhang                                                                              */
/*  Assignment:     Project 4 (Complex Number Operations)                                                         */
/*  Filename:       complexTypeImp.cpp                                                                            */
/*  Purpose:        This file contains the implementations of the complexType class member functions              */
/*                  declared in complexType.h. It supports arithmetic, comparisons, I/O, and increment/decrement. */
/******************************************************************************************************************/

#include "complexType.h"
#include <iomanip>

/*************************************************************************/
/* Function Name: complexType                                            */
/* Description:   Constructs a complexType object with given real        */
/*                part (r) and imaginary part (i).                       */
/* Parameters:    r (double) - the real part                             */
/*                i (double) - the imaginary part                        */
/* Return Value:  none (constructor)                                     */
/*************************************************************************/
complexType::complexType(double r, double i)
    : realPart(r), imagPart(i)
{
}

// Stream Insertion Operator
/*************************************************************************/
/* Function Name: operator<<                                             */
/* Description:   Inserts the complex number into the output stream in   */
/*                the format: (real + imag i) or (real - imag i).        */
/* Parameters:    out (ostream&) - output stream                         */
/*                c (const complexType&) - the complex number            */
/* Return Value:  ostream& (reference to the output stream)             */
/*************************************************************************/
ostream& operator<<(ostream &out, const complexType &c)
{
    out << fixed << setprecision(2);
    out << "(" << c.realPart
        << (c.imagPart >= 0 ? " + " : " - ")
        << fabs(c.imagPart) << "i)";
    return out;
}

// Stream Extraction Operator
/*************************************************************************/
/* Function Name: operator>>                                             */
/* Description:   Extracts the real part and imaginary part of a         */
/*                complex number from the input stream.                  */
/* Parameters:    in (istream&) - input stream                           */
/*                c (complexType&) - the complex number                  */
/* Return Value:  istream& (reference to the input stream)              */
/*************************************************************************/
istream& operator>>(istream &in, complexType &c)
{
    in >> c.realPart >> c.imagPart;
    return in;
}

// Addition
/*************************************************************************/
/* Function Name: operator+                                              */
/* Description:   Adds this complex number to another complex number.    */
/* Parameters:    other (const complexType&)                             */
/* Return Value:  complexType - sum of the two complex numbers           */
/*************************************************************************/
complexType complexType::operator+(const complexType &other) const
{
    return complexType(realPart + other.realPart,
                       imagPart + other.imagPart);
}

// Subtraction
/*************************************************************************/
/* Function Name: operator-                                              */
/* Description:   Subtracts another complex number from this one.        */
/* Parameters:    other (const complexType&)                             */
/* Return Value:  complexType - result of the subtraction                */
/*************************************************************************/
complexType complexType::operator-(const complexType &other) const
{
    return complexType(realPart - other.realPart,
                       imagPart - other.imagPart);
}

// Multiplication
/*************************************************************************/
/* Function Name: operator*                                              */
/* Description:   Multiplies this complex number by another.             */
/* Parameters:    other (const complexType&)                             */
/* Return Value:  complexType - product of the multiplication            */
/*************************************************************************/
complexType complexType::operator*(const complexType &other) const
{
    double r = (realPart * other.realPart) - (imagPart * other.imagPart);
    double i = (realPart * other.imagPart) + (imagPart * other.realPart);
    return complexType(r, i);
}

// Division
/*************************************************************************/
/* Function Name: operator/                                              */
/* Description:   Divides this complex number by another. If the         */
/*                denominator is 0, it returns this object (as per       */
/*                the unit test's requirement).                          */
/* Parameters:    other (const complexType&)                             */
/* Return Value:  complexType - result of the division                   */
/*************************************************************************/
complexType complexType::operator/(const complexType &other) const
{
    double denominator = (other.realPart * other.realPart) + (other.imagPart * other.imagPart);
    if (denominator == 0.0)
    {
        // Return the left operand if dividing by zero
        return *this;
    }

    double r = ((realPart * other.realPart) + (imagPart * other.imagPart)) / denominator;
    double i = ((imagPart * other.realPart) - (realPart * other.imagPart)) / denominator;
    return complexType(r, i);
}

// Equality
/*************************************************************************/
/* Function Name: operator==                                             */
/* Description:   Checks if two complex numbers have exactly matching    */
/*                real and imaginary parts.                              */
/* Parameters:    other (const complexType&)                             */
/* Return Value:  bool - true if both parts match, false otherwise       */
/*************************************************************************/
bool complexType::operator==(const complexType &other) const
{
    return (realPart == other.realPart) && (imagPart == other.imagPart);
}

// Inequality
/*************************************************************************/
/* Function Name: operator!=                                             */
/* Description:   Checks if two complex numbers differ in their real or  */
/*                imaginary parts.                                       */
/* Parameters:    other (const complexType&)                             */
/* Return Value:  bool - true if they differ, false otherwise            */
/*************************************************************************/
bool complexType::operator!=(const complexType &other) const
{
    return !(*this == other);
}

// Less-than
/*************************************************************************/
/* Function Name: operator<                                              */
/* Description:   Compares the magnitude of this complex number to       */
/*                another's magnitude to see if this is smaller.         */
/* Parameters:    other (const complexType&)                             */
/* Return Value:  bool - true if this < other based on magnitude         */
/*************************************************************************/
bool complexType::operator<(const complexType &other) const
{
    return magnitude() < other.magnitude();
}

// Less-than or equal
/*************************************************************************/
/* Function Name: operator<=                                             */
/* Description:   Compares the magnitude of this complex number to       */
/*                another's magnitude to see if this <= other.           */
/* Parameters:    other (const complexType&)                             */
/* Return Value:  bool - true if this <= other based on magnitude        */
/*************************************************************************/
bool complexType::operator<=(const complexType &other) const
{
    return magnitude() <= other.magnitude();
}

// Greater-than
/*************************************************************************/
/* Function Name: operator>                                              */
/* Description:   Compares the magnitude of this complex number to       */
/*                another's magnitude to see if this is larger.          */
/* Parameters:    other (const complexType&)                             */
/* Return Value:  bool - true if this > other based on magnitude         */
/*************************************************************************/
bool complexType::operator>(const complexType &other) const
{
    return magnitude() > other.magnitude();
}

// Greater-than or equal
/*************************************************************************/
/* Function Name: operator>=                                             */
/* Description:   Compares the magnitude of this complex number to       */
/*                another's magnitude to see if this >= other.           */
/* Parameters:    other (const complexType&)                             */
/* Return Value:  bool - true if this >= other based on magnitude        */
/*************************************************************************/
bool complexType::operator>=(const complexType &other) const
{
    return magnitude() >= other.magnitude();
}

// Pre-increment
/*************************************************************************/
/* Function Name: operator++                                             */
/* Description:   Pre-increments the real part of the complex number.    */
/*                Returns the updated object reference.                  */
/* Parameters:    none                                                   */
/* Return Value:  complexType& (reference to updated object)             */
/*************************************************************************/
complexType& complexType::operator++()
{
    ++realPart;
    return *this;
}

// Post-increment
/*************************************************************************/
/* Function Name: operator++(int)                                        */
/* Description:   Post-increments the real part. Returns the original    */
/*                value before incrementing.                             */
/* Parameters:    int (unused) - indicates post-increment                */
/* Return Value:  complexType (the original object before increment)     */
/*************************************************************************/
complexType complexType::operator++(int)
{
    complexType temp = *this;
    realPart++;
    return temp;
}

// Pre-decrement
/*************************************************************************/
/* Function Name: operator--                                             */
/* Description:   Pre-decrements the real part of the complex number.    */
/*                Returns the updated object reference.                  */
/* Parameters:    none                                                   */
/* Return Value:  complexType& (reference to updated object)             */
/*************************************************************************/
complexType& complexType::operator--()
{
    --realPart;
    return *this;
}

// Post-decrement
/*************************************************************************/
/* Function Name: operator--(int)                                        */
/* Description:   Post-decrements the real part. Returns the original    */
/*                value before decrementing.                             */
/* Parameters:    int (unused) - indicates post-decrement                */
/* Return Value:  complexType (the original object before decrement)     */
/*************************************************************************/
complexType complexType::operator--(int)
{
    complexType temp = *this;
    realPart--;
    return temp;
}
