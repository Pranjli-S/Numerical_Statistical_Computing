#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x*x*x - 4*x - 9; // Example function
}

int main() {
    double a, b, tol, c;
    cout << "Enter interval [a, b] and tolerance: ";
    cin >> a >> b >> tol;

    if (f(a) * f(b) >= 0) {
        cout << "Bisection method fails. f(a) and f(b) must have opposite signs.";
        return 0;
    }

    while ((b - a) >= tol) {
        c = (a + b) / 2;
        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }

    cout << fixed << setprecision(4) << "Root: " << c << endl;
    return 0;
}