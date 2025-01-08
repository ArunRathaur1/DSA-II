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
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        
        int count = 0;
        int dir = 0;
        
        
        // Traverse the array to count transitions
        for (int i = 1; i < n; i++) {
            if (ar[i] > ar[i - 1] && dir!=- 1) {
                count++;
                dir = -1; // Switch to increasing
            } else if (ar[i] < ar[i - 1] && dir != 1) {
                count++;
                dir = 1; // Switch to decreasing
            }
        }
        
        cout << count+1 << endl;
    }
}
