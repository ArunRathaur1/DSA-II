#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;

        // Check if all characters are already equal to c
        bool all_equal = true;
        for (char ch : s) {
            if (ch != c) {
                all_equal = false;
                break;
            }
        }

        if (all_equal) {
            cout << 0 << "\n"; // No operation needed
            continue;
        }

        // Check for positions that can be used in one operation
        int pos = -1;
        for (int i = n; i >= 1; i--) {
            bool valid = true;
            for (int j = i; j <= n; j += i) {
                if (s[j - 1] != c) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                pos = i;
                break;
            }
        }

        if (pos != -1) {
            cout << 1 << "\n";
            cout << pos << "\n";
        } else {
            // If no single position works, use two operations
            cout << 2 << "\n";
            cout << n << " " << n - 1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
