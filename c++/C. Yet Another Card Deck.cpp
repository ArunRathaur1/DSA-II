#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,q;
        cin>>n>>q;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        vector<int>qr(q);
        for(int i=0;i<q;i++)cin>>qr[i];
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.find(ar[i])==m.end()){
                m[ar[i]]=i+1;
            }
        }
        for(int i=0;i<q;i++){
            int p=m[qr[i]];
            cout<<p<<" ";
            for(auto& it: m){
                if(it.second<p){
                   it.second++;
                }
            }
            m[qr[i]]=1;
        }
        cout<<endl;
    }