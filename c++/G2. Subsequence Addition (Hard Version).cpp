#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>ar(n);
        for(long long i=0;i<n;i++)cin>>ar[i];
        long long max=1;
        sort(ar.begin(),ar.end());
        long long index=0;
        if(ar[0]!=1){
            cout<<"NO"<<endl;
            continue;
        }
        for(long long i=1;i<n;i++){
            if(ar[i]<=max){
                max=max+ar[i];
                index++;
            }
            else{
                break;
            }
        }
        if(index==n-1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}