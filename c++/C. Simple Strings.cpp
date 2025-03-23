#include <bits/stdc++.h>
using namespace std;

// Function to check if a given jump size `k` is possible
bool possilbe(int k, vector<vector<int>> &ar)
{
    int n = ar.size();
    int prevStart = 0;
    int prevEnd = 0;

    for (int i = 0; i < n; i++)
    {
        // Calculate the new valid range
        int newStart = max(ar[i][0], prevStart - k);
        int newEnd = min(ar[i][1], prevEnd + k);

        // If the new range is invalid, return false
        if (newStart > newEnd)
        {
            return false;
        }

        // Update the range for the next iteration
        prevStart = newStart;
        prevEnd = newEnd;
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> ar(n);

        int m = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            ar[i] = {x, y};
            m = max(m, y); // Use the maximum endpoint for binary search
        }

        int left = 0;
        int right = m;
        int ans = 0;

        // Binary search for the minimum jump size
        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (possilbe(mid, ar))
            {
                ans = mid;       // Update answer if possible
                right = mid - 1; // Try smaller jump sizes
            }
            else
            {
                left = mid + 1; // Try larger jump sizes
            }
        }

        cout << ans << endl;
    }

    return 0;
}
