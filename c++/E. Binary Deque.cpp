#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;
        vector<long long> ar(n);
        long long k=0;
        for (long long i = 0; i < n; i++){

        cin >> ar[i];
        k=k+ar[i];
        }
        if(k<s){
            cout<<-1<<endl;
            continue;
        } 
        long long left = 0, right = 0;
        long long sum = 0;
        long long length = 0;

        while (right < n) {
            sum += ar[right];
            right++;

            // Shrink the window from the left if the sum exceeds s
            while (sum > s && left < right) {
                sum -= ar[left];
                left++;
            }

            // Check if the current window is valid
            if (sum <= s) {
                length = max(length, right - left);
            }
        }

        cout <<n- length << endl;
    }
}
