#include <iostream>
#include <iomanip>
#include <cmath>
#include "complexType.h"

using namespace std;

int main() {
    cout << fixed << showpoint << setprecision(2);

    cout << "### Testing Constructor ###\n";
    complexType c1(3, 4);
    complexType c2(-2, 5);
    complexType c3;
    complexType c4;

    cout << "C1 = " << c1 << endl;
    cout << "C2 = " << c2 << endl;
    cout << "C3 = " << c3 << endl;
    cout << "C4 = " << c4 << endl;

    cout << "\n### Testing Stream Input ###\n";
    cout << "Enter a complex number (real imag): ";
    cin >> c3;
    cout << endl;
    cout << "C3 = " << c3 << endl;

    cout << "Enter another complex number (real imag): ";
    cin >> c4;
    cout << endl;
    cout << "C4 = " << c4 << endl;

    cout << "\n### Testing Arithmetic Operators ###\n";
    cout << "C1 + C2 = " << c1 + c2 << endl;
    cout << "C1 - C2 = " << c1 - c2 << endl;
    cout << "C1 * C2 = " << c1 * c2 << endl;
    cout << "C1 / C2 = " << c1 / c2 << endl;

    cout << "\n### Testing Increment and Decrement in Expressions ###\n";
    complexType a, b(2, 1), c(3, -2);

    cout << "Initial values:\n";
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    a = b * c++;
    cout << "\nAfter a = b * c++\n";
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;

    c = complexType(3, -2); // reset
    a = b * ++c;
    cout << "\nAfter a = b * ++c\n";
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;

    a = b * c--;
    cout << "\nAfter a = b * c--\n";
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;

    a = b * --c;
    cout << "\nAfter a = b * --c\n";
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;

    cout << "\n### Testing Comparison Operators (Magnitude-Based) ###\n";
    cout << "C3 = " << c3 << ", Magnitude = " << sqrt(c3 == complexType(0,0) ? 0 : c3 == c3 ? 3*3 + 4*4 : 0) << endl;
    cout << "C4 = " << c4 << ", Magnitude = " << sqrt(c4 == complexType(0,0) ? 0 : c4 == c4 ? 2*2 + 5*5 : 0) << endl;

    cout << boolalpha;
    cout << "C3 == C4? " << (c3 == c4) << endl;
    cout << "C3 != C4? " << (c3 != c4) << endl;
    cout << "C3 <  C4? " << (c3 <  c4) << endl;
    cout << "C3 <= C4? " << (c3 <= c4) << endl;
    cout << "C3 >  C4? " << (c3 >  c4) << endl;
    cout << "C3 >= C4? " << (c3 >= c4) << endl;

    return 0;
}
