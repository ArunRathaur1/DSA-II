#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        if (k == 2) {
            // Check if there's at least one even number
            bool hasEven = false;
            for (int i = 0; i < n; i++) {
                if (ar[i] % 2 == 0) {
                    hasEven = true;
                    break;
                }
            }
            cout << (hasEven ? 0 : 1) << endl;
        } else if (k == 4) {
            // Special method
            int countEven = 0;
            bool hasDivBy4 = false;
            for (int i = 0; i < n; i++) {
                if (ar[i] % 4 == 0) {
                    hasDivBy4 = true;
                }
                if (ar[i] % 2 == 0) {
                    countEven++;
                }
            }
            int specialCost;
            if (hasDivBy4 || countEven >= 2) {
                specialCost = 0;
            } else if (countEven == 1) {
                specialCost = 1;
            } else {
                specialCost = 2;
            }

            // General method
            int generalCost = INT_MAX;
            for (int i = 0; i < n; i++) {
                int remainder = ar[i] % 4;
                int adjustment = (remainder == 0) ? 0 : 4 - remainder;
                generalCost = min(generalCost, adjustment);
            }

            // Take the minimum of both methods
            cout << min(specialCost, generalCost) << endl;
        } else { // General case for k = 3 or k = 5
            int minAdjust = INT_MAX;
            for (int i = 0; i < n; i++) {
                int remainder = ar[i] % k;
                int adjustment = (remainder == 0) ? 0 : k - remainder;
                minAdjust = min(minAdjust, adjustment);
            }
            cout << minAdjust << endl;
        }
    }
    return 0;
}
