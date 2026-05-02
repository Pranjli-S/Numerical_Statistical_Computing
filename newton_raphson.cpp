#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { return x*x - 3*x + 2; }
double df(double x) { return 2*x - 3; }

int main() {
    double x0, x1, tol;
    cout << "Enter initial guess and tolerance: ";
    cin >> x0 >> tol;

    while (true) {
        x1 = x0 - f(x0) / df(x0);
        if (abs(x1 - x0) < tol) break;
        x0 = x1;
    }

    cout << "Root: " << x1 << endl;
    return 0;
}