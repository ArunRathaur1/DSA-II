#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long>ar(n);
        long long p=1;
        for(long long i=0;i<n;i++){
            cin>>ar[i];
            ar[i]=ar[i]+p;
            p++;
        }
        sort(ar.begin(),ar.end());
        long long tem=0;
        long long count=0;
        for(long long i=0;i<n;i++){
            tem=tem+ar[i];
            if(tem<=k){
                count++;
            }
            else{
                break;
            }
        } 
        cout<<count<<endl;  
    }
}