#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m1,m2;
        cin>>n>>m1>>m2;
        set<pair<int,int>>st;
        for(int i=0;i<m1;i++){
            int x,y;
            cin>>x>>y;
            st.insert({x,y});
        }
        int count=0;
        for(int i=0;i<m2;i++){
            int x,y;
            cin>>x>>y;
            if(st.find({x,y})!=st.end()||st.find({y,x})!=st.end()){
            count++;
            }
        }
        int total=m1-count+m2-count;
        cout<<total<<endl;
    }
}