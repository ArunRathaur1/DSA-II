#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,q;
        cin>>n>>q;
        vector<long long>ar(n);
        vector<long long>qr(q);
        for(long long i=0;i<n;i++)cin>>ar[i];
        for(long long i=0;i<q;i++)cin>>qr[i];
        vector<long long>prefix(n+1,0);
        for(long long i=0;i<n;i++){
            prefix[i+1]=prefix[i]+ar[i];
        }
        vector<long long>currmax(n);
        currmax[0]=ar[0];
        for(long long i=1;i<n;i++){
            currmax[i]=max(currmax[i-1],ar[i]);
        }
        vector<long long>ans(q);
        for(long long i=0;i<q;i++){
            auto tem=upper_bound(currmax.begin(),currmax.end(),qr[i]);
            long long index=tem-currmax.begin();
            ans[i]=prefix[index];
        } 
        for(long long i=0;i<q;i++){
            cout<<ans[i]<<" ";
        }  
        cout<<endl;
    }
}