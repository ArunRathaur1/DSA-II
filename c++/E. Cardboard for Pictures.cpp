#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        vector<int> stabilizationTime(N, 0);
        stack<int> stk;

        // Traverse the array from right to left
        for (int i = N - 1; i >= 0; --i) {
            while (!stk.empty() && A[i] < A[stk.top()]) {
                stabilizationTime[i] = max(stabilizationTime[i], stabilizationTime[stk.top()] + 1);
                A[i]=A[stk.top()];
                stk.pop();
            }
            stk.push(i);
        }
        // The result is the maximum stabilization time
        int result = *max_element(stabilizationTime.begin(), stabilizationTime.end());
        cout << result << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
