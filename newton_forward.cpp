#include <iostream>
using namespace std;

int main() {
    float x[10], y[10][10], val, u, ans;
    int n;
    cout << "Enter n: "; cin >> n;
    for(int i=0; i<n; i++) cin >> x[i] >> y[i][0];
    cout << "Enter value to interpolate: "; cin >> val;

    for(int j=1; j<n; j++)
        for(int i=0; i<n-j; i++)
            y[i][j] = y[i+1][j-1] - y[i][j-1];

    ans = y[0][0];
    u = (val - x[0]) / (x[1] - x[0]);
    float temp_u = u;
    int fact = 1;

    for(int i=1; i<n; i++) {
        ans += (temp_u * y[0][i]) / fact;
        fact *= (i + 1);
        temp_u *= (u - i);
    }
    cout << "Result: " << ans;
    return 0;
}