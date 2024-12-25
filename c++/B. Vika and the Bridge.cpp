#include <bits/stdc++.h>
using namespace std;

void findLargestContiguousBlock(const vector<long long>& arr, long long start, long long end, long long& maxPos, long long& maxNeg) {
    long long countPos = 0, countNeg = 0;
    maxPos = 0;
    maxNeg = 0;

    for (long long i = start; i < end; ++i) {
        if (arr[i] == 1) {
            countPos++;
            maxPos = max(maxPos, countPos);
            countNeg = 0;
        } else if (arr[i] == -1) {
            countNeg++;
            maxNeg = max(maxNeg, countNeg);
            countPos = 0;
        } else {
            countPos = 0;
            countNeg = 0;
        }
    }
}

void includeSpecialElementSubarrays(const vector<long long>& arr, long long specialElementIndex, long long specialElement, set<long long>& distinctSums) {
    long long n = arr.size();

    // Right side
    long long currentSum = specialElement;
    distinctSums.insert(currentSum);
    for (long long i = specialElementIndex + 1; i < n; ++i) {
        currentSum += arr[i];
        distinctSums.insert(currentSum);
    }

    // Left side
    currentSum = specialElement;
    for (long long i = specialElementIndex - 1; i >= 0; --i) {
        currentSum += arr[i];
        distinctSums.insert(currentSum);
    }

    // Two-pointer approach for both sides
    long long leftSum = 0, rightSum = 0;
    for (long long left = specialElementIndex, right = specialElementIndex; left >= 0 || right < n;) {
        if (left >= 0) {
            leftSum += arr[left];
            distinctSums.insert(leftSum + specialElement);
            --left;
        }
        if (right < n) {
            rightSum += arr[right];
            distinctSums.insert(rightSum + specialElement);
            ++right;
        }
    }
}

void solve() {
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        long long specialElement = 0;
        long long specialElementIndex = -1;

        // Read the array and identify the special element (if any)
        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] != -1 && a[i] != 1) {
                specialElement = a[i];
                specialElementIndex = i;
            }
        }

        // Part 1: Before special element
        long long maxPos1 = 0, maxNeg1 = 0;
        findLargestContiguousBlock(a, 0, specialElementIndex, maxPos1, maxNeg1);

        // Part 2: After special element
        long long maxPos2 = 0, maxNeg2 = 0;
        findLargestContiguousBlock(a, specialElementIndex + 1, n, maxPos2, maxNeg2);

        // Combine the results from the contiguous blocks of 1's and -1's
        long long p1 = max(maxPos1, maxPos2); // Maximum count of contiguous 1's
        long long p2 = max(maxNeg1, maxNeg2); // Maximum count of contiguous -1's

        // To store all possible sums
        set<long long> distinctSums;

        // Generate sums from 1's (0 to p1)
        for (long long i = 0; i <= p1; ++i) {
            distinctSums.insert(i); // Adding 1's sums: 0 to p1
        }

        // Generate sums from -1's (0 to p2)
        for (long long j = 0; j <= p2; ++j) {
            distinctSums.insert(-j); // Adding -1's sums: 0 to -p2
        }

        // Include all subarrays containing the special element
        if (specialElementIndex != -1) {
            includeSpecialElementSubarrays(a, specialElementIndex, specialElement, distinctSums);
        }

        // Output the distinct sums in sorted order
        cout << distinctSums.size() << endl;  // Number of distinct sums
        for (auto sum : distinctSums) {
            cout << sum << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
