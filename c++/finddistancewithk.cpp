#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <bits/stdc++.h>

typedef std::pair<int, int> Edge;
typedef std::vector<std::vector<Edge>> Graph;

int shortestDistanceBetween(Graph& graph, int source, int target) {
   map<int,vector<int>>adj;
   for(int i=0;i<graph.size();i++){
    adj[graph[i]]
   }
}

int main() {
    int vertices, edges;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> vertices >> edges;

    vector<vector<int>>edges;

    std::cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    int source, target;
    std::cout << "Enter the source and target vertices: ";
    std::cin >> source >> target;

    int distance = shortestDistanceBetween(graph, source, target);

    if (distance == -1) {
        std::cout << "Target vertex " << target << " is not reachable from source vertex " << source << ".\n";
    } else {
        std::cout << "Shortest distance from vertex " << source << " to vertex " << target << ": " << distance << "\n";
    }

    return 0;
}
