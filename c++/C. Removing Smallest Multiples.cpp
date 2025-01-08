#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<bool> is_in_T(n + 1, false); // Marks if number i is in T
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                is_in_T[i + 1] = true; // Mark the element as part of T
            }
        }

        long long cost = 0; // Total cost for this test case
        vector<bool> deleted(n + 1, false); // Tracks if a number is already deleted

        for (int k = 1; k <= n; k++) {
            for (int x = k; x <= n; x += k) { // Iterate over multiples of k
                if (deleted[x]) continue;   // Skip already deleted elements
                if (is_in_T[x]) break;     // Stop at the first element in T
                deleted[x] = true;         // Mark as deleted
                cost += k;                 // Add the cost of deletion
            }
        }

        cout << cost << endl; // Output the cost for this test case
    }

    return 0;
}
