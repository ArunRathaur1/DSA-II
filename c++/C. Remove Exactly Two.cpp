#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Length of array
        vector<int> ar(n);
        for (int i = 0; i < n; i++) cin >> ar[i];

        sort(ar.begin(), ar.end()); // Sort array for easier calculation

        long long max_sum = n * n; // Initial assumption: all elements are converted to n
        long long current_sum = 0; // Tracks the current sum dynamically

        for (int i = n - 1; i >= 0; i--) {
            // Update current sum by adding the current element
            current_sum += ar[i];

            // Compute potential sum if all elements from i to n-1 are converted
            long long potential_sum = current_sum + (i * i);

            // Update the maximum sum
            max_sum = max(max_sum, potential_sum);
        }

        cout << max_sum << endl; // Output the maximum sum
    }

    return 0;
}
