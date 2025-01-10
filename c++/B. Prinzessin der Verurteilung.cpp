#include <bits/stdc++.h>
using namespace std;

string solve(int n, string s) {
    // Check for single-letter strings
    for (int i = 0; i < 26; i++) {
        char ch = char(i + 'a');
        if (s.find(ch) == string::npos) {
            return string(1, ch);
        }
    }

    // Check for two-letter strings
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            string t = string(1, char('a' + i)) + char('a' + j);
            if (s.find(t) == string::npos) {
                return t;
            }
        }
    }

    // Check for three-letter strings
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                string t = string(1, char('a' + i)) + char('a' + j) + char('a' + k);
                if (s.find(t) == string::npos) {
                    return t;
                }
            }
        }
    }

    return "";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(n, s) << endl;
    }
}
