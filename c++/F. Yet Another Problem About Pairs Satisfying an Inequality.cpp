#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>ar(n+1);
        for(long long i=1;i<n+1;i++){
            cin>>ar[i];
        }
        vector<long long>prefix(n+1,0);
        for(long long i=1;i<n+1;i++){
            prefix[i]=prefix[i-1];
            if(ar[i]<(i)){
                prefix[i]++;
            }
        }
        long long count=0;
        for(long long i=1;i<n+1;i++){
            if(ar[i]<i){
                long long tem=ar[i];
                if(tem>1){
                    count=count+prefix[tem-1];
                }
            }
        }
        cout<<count<<endl;
    }
}