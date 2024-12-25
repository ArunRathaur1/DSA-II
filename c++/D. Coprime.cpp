#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ar(n);
        unordered_map<int,int>arr;
        for(int i=0;i<n;i++){
            cin>>ar[i];
            arr[ar[i]]=i+1;
        }
        int r=-1;
        int flag=0;
        for(auto p:arr){
            for(auto q:arr){
                if(__gcd(p.first,q.first)==1&&(p.second+q.second)>r){
                    r=p.second+q.second;
                }
            }
        }
        cout<<r<<endl;
    }
}