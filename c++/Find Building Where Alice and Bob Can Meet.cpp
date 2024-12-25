#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        map<int,vector<pair<int,int>>>m;
        int x=queries.size();
        vector<int>ans(x,-1);
        for(int i=0;i<x;i++){
            if(queries[i][0]==queries[i][1]){
                ans[i]=i;
            }
            int mvalue=max(queries[i][0],queries[i][1]);
            int p=max(heights[queries[i][0]],heights[queries[i][1]]);
            m[mvalue].push_back({p,i});
        }
        int y=heights.size();
        for(int i=0;i<y;i++){
            for(auto j: m){
                if(j.first<=i){
                    for(auto p:j.second){
                        q.push(p);
                    }
                }
            }
        }
    }
};
int main(){
}