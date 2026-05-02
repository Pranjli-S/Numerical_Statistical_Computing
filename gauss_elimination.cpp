#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter number of unknowns: "; cin >> n;
    float a[n][n+1], x[n];

    cout << "Enter augmented matrix:\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<=n; j++) cin >> a[i][j];

    for(int i=0; i<n-1; i++) {
        for(int k=i+1; k<n; k++) {
            float t = a[k][i] / a[i][i];
            for(int j=0; j<=n; j++) a[k][j] -= t * a[i][j];
        }
    }

    for(int i=n-1; i>=0; i--) {
        x[i] = a[i][n];
        for(int j=i+1; j<n; j++) x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    for(int i=0; i<n; i++) cout << "x" << i << " = " << x[i] << endl;
    return 0;
}