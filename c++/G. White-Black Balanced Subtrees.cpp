#include<bits/stdc++.h>
using namespace std;

vector<long long> stabletrees(const vector<vector<long long>> &adj, long long node, const string &s) {
    long long black = 0, white = 0, stable = 0;

    for (auto child : adj[node]) {
        vector<long long> tem = stabletrees(adj, child, s);
        stable += tem[0];  
        black += tem[1];   
        white += tem[2];   
    }

    if (s[node - 1] == 'B') black++; 
    else white++;                    

    if (black == white) stable++;    

    return {stable, black, white};
}

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<long long> parent(n - 1);
        vector<vector<long long>> adj(n + 1); 

        for (long long i = 0; i < n - 1; i++) {
            cin >> parent[i];
            adj[parent[i]].push_back(i + 2);
        }

        string s;
        cin >> s;

        vector<long long> stables = stabletrees(adj, 1, s);  
        cout << stables[0] << endl;  
    }

    return 0;
}
