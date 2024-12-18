#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while (t--)
    {   
        long long n;
        cin>>n;
        vector<pair<long long,long long>>ar(n);
        long long index=0;
        for(long long i=0;i<n;i++){
            long long p;
            cin>>p;
            ar[i]={p,index};
            index++;

        }
        sort(ar.begin(),ar.end());
        reverse(ar.begin(),ar.end());
        vector<long long>ans(n+1);
        ans[0]=0;
        long long sum=0;
        long long p=1;
        for(long long i=0;i<n;i++){
            sum=sum+ar[i].first*2*abs(p);
           ans[ar[i].second+1]=p;
           if(p<0){
            p=p-1;
           }
           p=p*(-1);
        }
        cout<<sum<<endl;
        for(long long i=0;i<n+1;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
}