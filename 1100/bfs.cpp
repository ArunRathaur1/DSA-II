#include <bits/stdc++.h>
using namespace std;

void myBFSFunction(vector<vector<int>> edges)
{
    map<int,vector<int>>adj;
    for(auto i: edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    int nodes=adj.size();
    vector<int>level(nodes+1,0);
    vector<bool>visited(nodes+1,false);
    vector<int>color(nodes+1,2);
    queue<int>q;
    //0->balck
    //1->gray
    //2->white
    q.push(1);
    level[1]=0;
    while (!q.empty())
    {
        int t=q.front();
        q.pop();
        color[t]=0;
        visited[t]=true;
        for(auto i: adj[t]){
            if(visited[i]==false){
                color[i]=1;
                level[i]=level[t]+1;
                q.push(i);
            }
        }
        for(auto i:color){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(auto i: level){
        cout<<i<<" ";
    }
    
}

int main()
{
    vector<vector<int>> edges = {
        {1, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 6}, {6, 7}};

    myBFSFunction(edges);

    return 0;
}
