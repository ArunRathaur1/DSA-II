#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>edges={{3,1,2},{1,0,5},{3,2,6},{1,2,9},{2,0,8}};
    vector<int>distance(4,INT_MAX);
    map<int,vector<pair<int,int>>>adj;
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j: i.second){
            cout<<j.first<<' '<<j.second<<"     ";
        }
        cout<<endl;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    distance[0]=0;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int>x=q.top();
        q.pop();
        int nodevalue=x.second;
        for(auto i: adj[nodevalue]){
            if(distance[i.first]>distance[nodevalue]+i.second){
                distance[i.first]=distance[nodevalue]+i.second;
                q.push({distance[i.first],i.first});
            }
        }
    }
    for(auto i: distance){
        cout<<i<<" ";
    }
    cout<<endl;
}