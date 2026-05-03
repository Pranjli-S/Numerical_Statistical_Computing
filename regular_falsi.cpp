#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// define func
double f(double x) {
    return x * x * x - 2 * x - 5;
}

int main() {
    double a, b, c, tol;

    cout << "enter interval [a, b] & tol: ";
    cin >> a >> b >> tol;

    // check validity
    if (f(a) * f(b) >= 0) {
        cout << "invalid interval";
        return 0;
    }

    // regular falsi 
    do {
        // Formula for False Position
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    } while (fabs(f(c)) > tol);

    cout << fixed << setprecision(6);
    cout << "Root = " << c << endl;

    return 0;
}