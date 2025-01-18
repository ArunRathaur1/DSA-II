#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

long long factoraial(long long n){
    long long x=1;
    for(long long i=1;i<=n;i++)x=(x*i)%mod;
    return x;
}
// Main function to process the test cases
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Read number of test cases
    long long t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        long long min_operations = 0; // Minimum deletions
        long long ways = 1;          // Number of ways

        // Traverse the string and process blocks
        char prev = s[0];
        long long block_size = 1;
        for (long long i = 1; i < s.size(); i++) {
            if (s[i] == prev) {
                block_size++;
            } else {
                // Process the current block
                min_operations += (block_size - 1);
                ways = (ways * block_size) % mod;

                // Start a new block
                prev = s[i];
                block_size = 1;
            }
        }

        // Process the last block
        min_operations += (block_size - 1);
        ways = (ways * block_size) % mod;
        ways=(ways*factoraial(min_operations))%mod;

        // Output the result for this test case
        cout << min_operations << " " << ways << "\n";
    }

    return 0;
}
