#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n, iterations;
    float a[10][10], b[10], x[10] = {0}; // Initialize guesses to 0

    cout << "Enter number of unknowns (n): ";
    cin >> n;

    cout << "Enter coefficients row-wise (A matrix):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter constants (B vector):\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << "Enter number of iterations: ";
    cin >> iterations;

    // Gauss-Seidel Logic
    for (int k = 1; k <= iterations; k++) {
        for (int i = 0; i < n; i++) {
            float sum = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            // In Gauss-Seidel, we update x[i] and use it immediately for the next variable
            x[i] = sum / a[i][i];
        }
    }

    cout << fixed << setprecision(6) << "\nSolutions after " << iterations << " iterations:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}