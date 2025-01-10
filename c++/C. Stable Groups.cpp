#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k, x;
    cin >> n >> k >> x;

    vector<long long> ar(n);
    for (long long i = 0; i < n; i++) cin >> ar[i];

    // Sort student levels
    sort(ar.begin(), ar.end());

    // Calculate differences between consecutive elements
    vector<long long> diff;
    for (long long i = 1; i < n; i++) {
        long long gap = ar[i] - ar[i - 1];
        if (gap > x) diff.push_back(gap);
    }

    // Sort gaps in ascending order
    sort(diff.begin(), diff.end());
    long long p=diff.size();
    long long count = 1; // At least one group exists
    for (long long gap : diff) {
        if(gap<x)continue;
        long long students_needed = (gap-1 ) / x; // Equivalent to ceil(gap / x)
        
        if (k >= students_needed) {
            // Use available additional students to bridge the gap
            k -= students_needed;
        } else {
            // Not enough students to bridge this gap, form a new group
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
