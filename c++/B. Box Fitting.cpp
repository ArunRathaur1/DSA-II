#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, w;
        cin >> n >> w;
        map<long long, long long> ar;

        for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            ar[x]++;
        }

        long long height = 0;

        while (!ar.empty()) {
            long long v = w;

            // Use a reverse iterator to traverse the map from largest to smallest
            vector<long long> toErase; // Store keys to erase later
            for (auto it = ar.rbegin(); it != ar.rend(); ++it) {
                long long x = v / it->first;
                long long p = min(x, it->second); 
                v -= p * it->first;
                ar[it->first] -= p;

                if (ar[it->first] == 0) {
                    toErase.push_back(it->first); // Mark for erasure
                }
            }


            for (long long key : toErase) {
                ar.erase(key);
            }

            height++;
        }

        cout << height << endl;
    }

    return 0;
}
