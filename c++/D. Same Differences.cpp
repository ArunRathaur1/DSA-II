#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>ar(n);
        map<long long,long long>freq;
        for(long long i=0;i<n;i++)cin>>ar[i];
        for(long long i=0;i<n;i++){
            freq[ar[i]-i]++;
        }
        long long count=0;
        for(long long i=0;i<n;i++){
            long long x=freq[ar[i]-i];
            if(x>1){
                count=count+x-1;
                freq[ar[i]-i]--;
            }
        }
        cout<<count<<endl;
    }
}