#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int mod=1e9+7;
        int n,k;
        cin>>n>>k;
        long long ans=1;
        for(int i=0;i<k;i++){
            ans=(ans*n)%(mod);
        }
        cout<<ans<<endl;;
    }
}