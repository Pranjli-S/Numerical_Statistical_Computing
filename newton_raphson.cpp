#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// function
double f(double x) {
    return x * x - 3 * x + 2;
}

// derivative
double df(double x) {
    return 2 * x - 3;
}

int main() {
    double x0, x1, tol;
    int iter = 0, max_iter = 100;

    cout << "enter initial guess & tol: ";
    cin >> x0 >> tol;

    while (iter < max_iter) {
        // Check if derivative is too small to avoid division by zero
        if (fabs(df(x0)) < 1e-9) {
            cout << "derivative is 0, Method fails" << endl;
            return 0;
        }

        // Newton-Raphson Formula
        x1 = x0 - f(x0) / df(x0);

        // Check for convergence
        if (fabs(x1 - x0) < tol) {
            break;
        }

        x0 = x1;
        iter++;
    }

    cout << fixed << setprecision(6);
    cout << "Root = " << x1 << endl;

    return 0;
}