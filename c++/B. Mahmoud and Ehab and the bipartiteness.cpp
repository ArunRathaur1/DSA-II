#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    map<int,vector<int>>adj;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>color(n,0);
    vector<int>color1,color2;
    queue<int>q;
    while (!q.empty())
    {
        int node=q.front();
        for(auto i: m[node]){

        }
    }
    
}
