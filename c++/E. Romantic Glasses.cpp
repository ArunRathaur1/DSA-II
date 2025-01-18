#include<bits/stdc++.h>
using namespace std;
bool solve(){
    long long n;
    cin>>n;
    vector<long long>ar(n);
    for(long long i=0;i<n;i++)cin>>ar[i];
    set<long long>st;
    vector<long long>prefix(n+1,0);
    for(long long i=0;i<n;i++){
        if(i%2==0){
            prefix[i+1]=prefix[i]+ar[i];
        }
        else{
            prefix[i+1]=prefix[i]-ar[i];
        }
    } 
    for(long long i=0;i<n+1;i++){
        if(st.find(prefix[i])==st.end())
            st.insert(prefix[i]);
        else{
            return true;
        }
    }
    return false;
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        bool ans=solve();
        cout<<(ans==1?"YES":"NO")<<endl;
    }
}