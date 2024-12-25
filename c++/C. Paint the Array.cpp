#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t; // Number of test cases
    while (t--) {
        long long n;
        cin >> n; // Size of the array
        vector<long long> tem1, tem2;

        // Input array and split long longo two groups
        for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (i % 2 == 0) {
                tem1.push_back(x); // Even indices
            } else {
                tem2.push_back(x); // Odd indices
            }
        }

        // Calculate GCD of both groups
        long long g1 = 0, g2 = 0;
        for (long long x : tem1) g1 = __gcd(g1, x);
        for (long long x : tem2) g2 = __gcd(g2, x);

        // Check conditions for g1 and g2
        bool valid_g1 = true, valid_g2 = true;
        for (long long x : tem2) {
            if (x % g1 == 0) {
                valid_g1 = false;
                break;
            }
        }
        for (long long x : tem1) {
            if (x % g2 == 0) {
                valid_g2 = false;
                break;
            }
        }

        // Output the result
        if (valid_g1) {
            cout << g1 << endl;
        } else if (valid_g2) {
            cout << g2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
