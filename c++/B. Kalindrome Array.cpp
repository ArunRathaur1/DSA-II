#include <bits/stdc++.h>
using namespace std;

bool isKalindrome(vector<int>& ar, int n, int ignoreValue) {
    int left = 0, right = n - 1;
    while (left < right) {
        if (ar[left] != ar[right]) {
            if (ar[left] == ignoreValue) {
                left++;
            } else if (ar[right] == ignoreValue) {
                right--;
            } else {
                return false;
            }
        } else {
            left++;
            right--;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        // Check if the array is already a palindrome
        int left = 0, right = n - 1;
        bool isPalindrome = true;
        while (left < right) {
            if (ar[left] != ar[right]) {
                isPalindrome = false;
                break;
            }
            left++;
            right--;
        }

        if (isPalindrome) {
            cout << "YES" << endl;
            continue;
        }

        // Check for kalindrome by ignoring left or right mismatch values
        int leftValue = ar[left];
        int rightValue = ar[right];

        if (isKalindrome(ar, n, leftValue) || isKalindrome(ar, n, rightValue)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
