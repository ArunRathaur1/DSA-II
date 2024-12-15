#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k,b,s;
        cin>>n>>k>>b>>s;
        long long x=k*b;
        long long maxsum=x+n*(k-1);
        if(s<x||s>maxsum){
            cout<<-1<<endl;
            continue;
        }
        else{
            vector<long long>ans(n,0);
            ans[0]=k*b;
            long long sum=s-k*b;
            for(int i=0;i<n;i++){
                if(sum>k-1){
                    ans[i]=ans[i]+k-1;
                    sum=sum-(k-1);
                }
            }
            if(sum>0){
                ans[n-1]=sum;
            }
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
     }
}