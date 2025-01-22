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
        long long gcdvalue=0;
        for(long long i=0;i<30;i++){
            long long temcount=0;
            for(long long j=0;j<n;j++){
                if((ar[j]&(1<<i))!=0)temcount++;
            }
            gcdvalue=__gcd(temcount,gcdvalue);
        }
        if(gcdvalue==0){
            for(long long i=0;i<n;i++){
                cout<<i+1<<" ";
            }
        }
        else{
             for(long long i=1;i<=gcdvalue;i++){
                if(gcdvalue%i==0){
                    cout<<i<<" ";
                }
            }
        }
        cout<<endl;
    }
}