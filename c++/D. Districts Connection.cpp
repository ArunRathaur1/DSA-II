#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            m[x].push_back(i+1);
        }
        if(m.size()==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            auto x=m.begin();
            int first=x->second[0];
            auto p=++m.begin();
            int sec=p->second[0];
            for(auto i=p;i!=m.end();i++){
                    for(int second:i->second){
                        cout<<first<<" "<<second<<endl;
                    }
            }
            if(sec==-1){
                continue;
            }
            for(int second:x->second){
                if(second==first)continue;
                cout<<sec<<" "<<second<<endl;
            }
        }
    }
}