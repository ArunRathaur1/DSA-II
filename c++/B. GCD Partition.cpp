#include<bits/stdc++.h>
using namespace std;
int_fast32_t main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long sum1=0,sum2=0;
        vector<long long>ar(n);
        for(long long i=0;i<n;i++){
            cin>>ar[i];
            sum1=sum1+ar[i];
        }
        long long maxgcd=1;
        for(long long i=0;i<n-1;i++){
            sum1=sum1-ar[i];
            sum2=sum2+ar[i];
            long long p=__gcd(sum1,sum2);
            maxgcd=max(maxgcd,p);
        }
        cout<<maxgcd<<endl;
    }
}