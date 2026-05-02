#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x*x*x - 2*x - 5;
}

int main() {
    double a, b, tol, c;
    cout << "Enter a, b and tolerance: ";
    cin >> a >> b >> tol;

    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) * f(a) < 0) b = c;
        else a = c;
    } while (abs(f(c)) > tol);

    cout << "Root: " << c << endl;
    return 0;
}