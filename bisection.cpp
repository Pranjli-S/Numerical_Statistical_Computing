#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Define function
double f(double x) {
    return x * x * x - 4 * x - 9;
}

int main() {
    double a, b, c, tol;
    
    cout << "Enter interval [a, b] & tolerance: ";
    cin >> a >> b >> tol;

    // Check validity of interval
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. f(a) & f(b) must have opposite signs." << endl;
        return 0;
    }

    // Bisection method
    while ((b - a) >= tol) {
        c = (a + b) / 2;

        if (fabs(f(c)) < tol) {
            break;
        }

        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    // Final root
    c = (a + b) / 2;
    cout << fixed << setprecision(6);
    cout << "Root = " << c << endl;

    return 0;
}