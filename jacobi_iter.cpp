#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, iter;
    cout << "Enter number of unknowns: "; cin >> n;
    
    float a[10][10], b[10], x[10] = {0}, x_new[10];

    cout << "Enter coefficients row-wise (A matrix):\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> a[i][j];

    cout << "Enter constants (B vector):\n";
    for(int i=0; i<n; i++) cin >> b[i];

    cout << "Enter number of iterations: "; cin >> iter;

    for (int k = 0; k < iter; k++) {
        for (int i = 0; i < n; i++) {
            float sum = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) sum -= a[i][j] * x[j];
            }
            x_new[i] = sum / a[i][i];
        }
        for (int i = 0; i < n; i++) x[i] = x_new[i];
    }

    cout << "\nSolutions:\n";
    for(int i=0; i<n; i++) cout << "x" << i+1 << " = " << x[i] << endl;

    return 0;
}