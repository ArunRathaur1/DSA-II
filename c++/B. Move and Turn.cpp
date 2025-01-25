#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; // Number of test cases
    cin >> t;

    while (t--) {
        long long n, l, r; // Array size, segment [l, r]
        cin >> n >> l >> r;
        vector<long long> a(n);

        // Input array elements
        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Split the array long longo three sections:
        vector<long long> left(a.begin(), a.begin() + l - 1);  // Elements before the segment
        vector<long long> segment(a.begin() + l - 1, a.begin() + r);  // Elements in the segment
        vector<long long> right(a.begin() + r, a.end());  // Elements after the segment

        // Sort the first and third sections in ascending order
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        // Sort the segment in descending order
        sort(segment.begin(), segment.end(), greater<long long>());

        // Calculate the initial sum of the segment
        long long initial_sum = accumulate(segment.begin(), segment.end(), 0LL);

        long long min_sum = initial_sum; // Track the minimum sum
        long long curr_sum = initial_sum; // Current working sum

        // Two polong longers to iterate over the left and right sections
        long long i = 0, j = 0;

        while (i < left.size() && j < segment.size()) {
            // If the current segment element is greater than the element from the left section, update the sum
            if (segment[j] > left[i]) {
                curr_sum = curr_sum - segment[j] + left[i];
                min_sum = min(min_sum, curr_sum);
                i++;
                j++;
            } else {
                break;
            }
        }

        i = 0; // Reset the polong longer for the left section
        j = 0; // Reset the polong longer for the segment
        curr_sum=initial_sum;
        // Now handle the right section
        while (i < right.size() && j < segment.size()) {
            // If the current segment element is greater than the element from the right section, update the sum
            if (segment[j] > right[i]) {
                curr_sum = curr_sum - segment[j] + right[i];
                min_sum = min(min_sum, curr_sum);
                i++;
                j++;
            } else {
               break;
            }
        }

        // Output the minimum sum after the best replacements
        cout << min_sum << endl;
    }

    return 0;
}
