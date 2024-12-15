#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool detectCycleBFS(vector<vector<int>>edges,int n,int source){
    map<int,vector<int>>adj;
    for(auto i:edges){
        adj[i[0]].push_back(i[1]);
    }
    queue<int>q;
    vector<bool>visited(n,false);
    vector<int>parent(n,-1);
    q.push(source);
    while (!q.empty())
    {
       int tem=q.front();
       visited[tem]=true;
       q.pop();
       for(auto i:adj[tem]){
        if(visited[i]==false){
            visited[i]=true;
            parent[i]=tem;
            q.push(i);
        }
        else if(i!=parent[tem]){
            return true;
        }
       }
    }
    return false;

}
int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}
    };

    vector<bool> visited(n, false);
    bool hasCycle = false;

    // Check for cycles in all components
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (detectCycleBFS(edges, n, i)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle in the graph." << endl;
    }

    return 0;
}