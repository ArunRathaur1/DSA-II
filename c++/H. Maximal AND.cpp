#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long>ar(n);
        for(long long i=0;i<n;i++){
            cin>>ar[i];
        }
        for(long long i=30;i>0;i--){
            long long count=0;
            for(long long j=0;j<n;j++){
                if((ar[j]&(1<<i))==0){
                    count++;
                }
            }
            if(count<=k){
                for(long long j=0;j<n;j++){
                    ar[j]=ar[j]|(1<<i);
                }
                k=k-count;
            }
        }
        long long a=ar[0];
        for(long long i=1;i<n;i++){
            a=a&ar[i];
        }
        cout<<a<<endl;
    }
}