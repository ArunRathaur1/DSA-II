#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,x;
        cin>>n>>x;
        vector<long long>ar(n);
        long long sum=0;
        for(long long i=0;i<n;i++){
            cin>>ar[i];
            sum=sum+ar[i];
        }
        sort(ar.begin(),ar.end());
        vector<long long>prefixsum(n);
        prefixsum[0]=ar[0];
        for(long long i=1;i<n;i++)prefixsum[i]=prefixsum[i-1]+ar[i];
        long long day=0;
        long long ans=0;
        for(long long i=n-1;i>=0;i--){
            long long price=prefixsum[i]+day*(i+1);
            if(x>=price){
                long long days=(x-price)/(i+1)+1;
                ans=ans+days*(i+1);
                day=day+days;
            }
        }
        cout<<ans<<endl;
    }
}