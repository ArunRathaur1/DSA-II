#include <bits/stdc++.h>
using namespace std;

// Function to rotate the matrix by 90 degrees clockwise
vector<vector<int>> rotateBy90(const vector<vector<int>>& ar) {
    int n = ar.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));

    // Perform the rotation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - i - 1] = ar[i][j];
        }
    }

    return rotated;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> ar(n, vector<int>(n, 0));
        
        // Read the matrix input
        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < n; j++) {
                ar[i][j] = row[j] - '0'; // Convert character to integer
            }
        }

        // Generate rotated matrices
        vector<vector<int>> second = rotateBy90(ar);
        vector<vector<int>> third = rotateBy90(second);
        vector<vector<int>> fourth = rotateBy90(third);

        int maxcount = 0;

        // Calculate maxcount based on conditions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                if (ar[i][j] == 0) count++;
                if (second[i][j] == 0) count++;
                if (third[i][j] == 0) count++;
                if (fourth[i][j] == 0) count++;

                if (count == 4 || count == 3 || count == 2) {
                    maxcount += (4 - count);
                } else {
                    maxcount += count;
                }
            }
        }

        cout << maxcount / 4 << endl;
    }

    return 0;
}
