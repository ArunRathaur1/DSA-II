#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, X;
        cin >> n >> X;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        // Count frequencies and store indices (positions) for each number.
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++)
        {
            freq[A[i]]++;
            pos[A[i]].push_back(i);
        }

        // Baseline answer (no operation).
        int ans = 0;
        for (auto &p : freq)
        {
            ans = max(ans, p.second);
        }

        // Special case: if X == 1, multiplication does not change any element.
        if (X == 1)
        {
            cout << ans << "\n";
            continue;
        }

        // For each distinct number w, consider converting w into candidate v = X * w.
        // Final frequency for v will be: freq(v) + max_{contiguous interval I} [ (# of w's in I) - (# of v's in I) ].
        for (auto &entry : pos)
        {
            int w = entry.first;
            // Candidate final value v = X * w (use long long for multiplication to avoid overflow).
            long long candidateLL = (long long)X * w;
            int freqV = 0;
            if (candidateLL <= INT_MAX)
            {
                int v = (int)candidateLL;
                if (freq.find(v) != freq.end())
                    freqV = freq[v];
            }

            // Build merged (sorted) list of positions for w and v.
            vector<int> merged;
            vector<int> &positionsW = entry.second; // positions where A[i] == w
            vector<int> positionsV;
            if (candidateLL <= INT_MAX)
            {
                int v = (int)candidateLL;
                if (pos.find(v) != pos.end())
                {
                    positionsV = pos[v]; // positions where A[i] == v
                }
            }

            int i = 0, j = 0;
            while (i < positionsW.size() || j < positionsV.size())
            {
                if (j >= positionsV.size() || (i < positionsW.size() && positionsW[i] < positionsV[j]))
                {
                    merged.push_back(positionsW[i]);
                    i++;
                }
                else
                {
                    merged.push_back(positionsV[j]);
                    j++;
                }
            }

            // Build the delta array: +1 if the index corresponds to a w, -1 if to a v.
            vector<int> delta;
            delta.reserve(merged.size());
            i = 0;
            j = 0;
            for (int posIdx : merged)
            {
                bool isW = false;
                if (i < positionsW.size() && positionsW[i] == posIdx)
                {
                    isW = true;
                    i++;
                }
                else
                {
                    j++; // must be from positionsV
                }
                delta.push_back(isW ? 1 : -1);
            }

            // Use Kadane's algorithm to compute the maximum subarray sum in delta.
            int best = 0, cur = 0;
            for (int d : delta)
            {
                cur = max(0, cur + d);
                best = max(best, cur);
            }

            // The candidate frequency if we choose candidate v is:
            //   freq(v) [unchanged] + (maximum gain from converting w's inside an interval)
            ans = max(ans, freqV + best);
        }

        cout << ans << "\n";
    }
    return 0;
}
