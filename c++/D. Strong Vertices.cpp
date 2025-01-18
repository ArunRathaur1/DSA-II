#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>ar(n),br(n);
        for(long long i=0;i<n;i++)cin>>ar[i];
        for(long long j=0;j<n;j++)cin>>br[j];
        for(long long i=0;i<n;i++){
            ar[i]=ar[i]-br[i];
        }
        long long maxelement=INT_MIN;
        for(long long i=0;i<n;i++){
            maxelement=max(maxelement,ar[i]);
        }
        long long count=0;
        for(long long i=0;i<n;i++){
            if(ar[i]==maxelement){
                count++;
            }
        }
        cout<<count<<endl;
        for(long long i=0;i<n;i++){
            if(ar[i]==maxelement){
                cout<<i+1<<' ';
            }
        }
        cout<<endl;
    }
}