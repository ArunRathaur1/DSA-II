#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int,vector<int>> adjlist(vector<vector<int>>edges){
        map<int,vector<int>>adj;
        int n=edges.size();
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return adj;
    }
    int findmaxnode(map<int,vector<int>>adj){
        queue<int>q;
        vector<bool>visited(adj.size(),false);
        int firstnode=adj.begin()->first;
        q.push(firstnode);
        int node=0;
        while (!q.empty())
        {   
           int t=q.front();
           q.pop();
           for(auto i: adj[t]){
                if(visited[i]==false){
                    q.push(i);
                    visited[i]==true;
                    node=i;
                }
           } 
        }
        return node;
        
    }
    int finddiameter(map<int,vector<int>>adj){
        int distance=0;
        int node=findmaxnode(adj);
        vector<bool>visited(adj.size(),false);
        map<int,int>dis;
        dis[node]=0;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            visited[node]=true;
            for(auto i: adj[t]){
                if(visited[i]==false){
                    dis[i]=dis[t]+1;
                    visited[i]==true;
                }
            }
        }
        for(auto i: dis){
            cout<<i.first<<" "<<i.second<<endl;
        }
        return distance;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        map<int,vector<int>>adj1=adjlist(edges1);
        map<int,vector<int>>adj2=adjlist(edges2);
        int d1=finddiameter(adj1);
        int d2=finddiameter(adj2);
        int merged_diameter = 0;
        if (d1 % 2 == 0 && d2 % 2 == 0) {
            merged_diameter = d1 / 2 + d2 / 2 + 1;
        } else if (d1 % 2 == 0 || d2 % 2 == 0) {
            merged_diameter = d1 / 2 + d2 / 2 + 2;
        } else {
            merged_diameter = d1 / 2 + d2 / 2 + 3;
        }
    }
};