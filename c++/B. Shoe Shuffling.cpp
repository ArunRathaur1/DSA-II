#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) cin >> ar[i];

        map<int, vector<int>> frq;  // Map to store indices of each element
        for (int i = 0; i < n; i++) {
            frq[ar[i]].push_back(i + 1);  // Store 1-based index
        }

        bool hasSingles = false;
        for (auto &i : frq) {
            if (i.second.size() == 1) {
                hasSingles = true;  // Check if any element occurs only once
                break;
            }
        }

        if (hasSingles) {
            cout << -1 << endl;  
        } else {
            vector<int> result(n);
            for (auto &group : frq) {
                vector<int> indices = group.second;
                int groupSize = indices.size();
                for (int i = 0; i < groupSize; i++) {
                    result[indices[i] - 1] = indices[(i + 1) % groupSize];
                }
            }

            for (int i = 0; i < n; i++) {
                cout << result[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
