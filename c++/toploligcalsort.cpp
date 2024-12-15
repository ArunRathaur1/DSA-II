#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 6; // Number of nodes
    vector<vector<int>> edges = {
       {0,1,5},{0,2,3},{2,5,2},{4,5,-2},{3,4,-1},{1,3,6},{1,2,2},{2,3,7},{2,4,4}
    };
    map<int,vector<pair<int,int>>>ar;
    for(auto node: edges){
        ar[node[0]].push_back({node[1],node[2]});
    }
    for(auto i: ar){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<"["<<j.first<<","<<j.second<<"]"<<" ";
        }
        cout<<endl;
    }
    vector<int>distance(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
    q.push({0,0});
    distance[0]=0;
    while (!q.empty())
    {
        pair<int,int>x=q.top();
        q.pop();
        int node=x.second;
        int currdis=x.first;
        if(currdis>distance[node])continue;
        for(auto neighbor:ar[node]){
            int n=neighbor.first;
            int weight=neighbor.second;
            if(currdis+weight<distance[n]){
                distance[n]=currdis+weight;
                q.push({distance[n],n});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<distance[i]<<" ";
    }
    return 0;
}