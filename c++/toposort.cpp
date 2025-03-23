#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int nodes=adj.size();
        vector<int>indegree(nodes,0);
        for(int i=0;i<nodes;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        for(int i=0;i<nodes;i++){
            cout<<indegree[i]<<" ";
        }
        return {};
    }
};
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    // Creating an adjacency list representation of the graph
    vector<vector<int>> adj(nodes);

    // Input edges
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v; // edge from u to v
        adj[u].push_back(v);
    }

    Solution obj;
    vector<int> result = obj.topologicalSort(adj);


    return 0;
}