#include <bits/stdc++.h>
using namespace std;

// Function to determine if the pattern can be made symmetrical
bool canMakeSymmetrical(vector<vector<int>> &ar, int n, int k) {
    int mismatchCount = 0;

    // Count mismatches between the matrix and its 180-degree rotated version
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ar[i][j] != ar[n - i - 1][n - j - 1]) {
                mismatchCount++;
            }
        }
    }
    int requiredOps = mismatchCount / 2;

    if(requiredOps>k)return false;
    if(requiredOps==k)return true;
    else{
        if(n%2==1)return true;
        else if((k-requiredOps)%2==0)return true;
        return false;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> ar(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> ar[i][j];
            }
        }

        // Output the result for the current test case
        if (canMakeSymmetrical(ar, n, k)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
