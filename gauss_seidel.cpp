#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Initializing variables as seen in your previous logic
    double x = 0, y = 0, z = 0;
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
        /* In Gauss-Seidel, we update the variables directly.
           The values of 'x' updated in the first line are 
           immediately used to calculate 'y' and 'z'.
        */
        
        x = (17 - y + (2 * z)) / 20.0;
        y = (-18 - (3 * x) + z) / 20.0;
        z = (25 - (2 * x) + (3 * y)) / 20.0;

        // Output current iteration results
        cout << setw(4) << i << " | " << setw(10) << x 
             << " | " << setw(10) << y 
             << " | " << setw(10) << z << endl;
    }

    return 0;
}