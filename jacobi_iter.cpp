#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x = 0, y = 0, z = 0;
    double x_new, y_new, z_new;
    int iterations;

    cout << "Enter number of iterations: ";
    cin >> iterations;

    // Header for the output table
    cout << setw(4) << "i" << " | " << fixed << setprecision(4) 
         << setw(10) << "x" << " | " 
         << setw(10) << "y" << " | " 
         << setw(10) << "z" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 1; i <= iterations; i++) {
        // Jacobi formulas from the notes
        x_new = (17 - y + (2 * z)) / 20.0;
        y_new = (-18 - (3 * x) + z) / 20.0;
        z_new = (25 - (2 * x) + (3 * y)) / 20.0;

        // Update values after all new values are calculated
        x = x_new;
        y = y_new;
        z = z_new;

        // Output current iteration results
        cout << setw(4) << i << " | " << setw(10) << x 
             << " | " << setw(10) << y 
             << " | " << setw(10) << z << endl;
    }

    return 0;
}