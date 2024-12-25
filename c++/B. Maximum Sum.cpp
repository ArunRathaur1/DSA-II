#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while (t--)
    {
        long long n,k;
        cin>>n>>k;
        vector<long long>ar(n);
        long long sum=0;
        for(long long i=0;i<n;i++){
            cin>>ar[i];
            sum=sum+ar[i];
        }
        sort(ar.begin(),ar.end());
        long long tem=k;
        long long left=0;
        while(tem--){
            sum=sum-ar[left]-ar[left+1];
            left=left+2;
        }
        long long currmax=sum;
        long long right=n-1;
        while(k--){
            sum=sum-ar[right]+ar[left-1]+ar[left-2];
            left=left-2;
            right--;
            currmax=max(currmax,sum);
        }
        cout<<currmax<<endl;
    }
    
}