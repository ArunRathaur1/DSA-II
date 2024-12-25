#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        vector<int>br=ar;
        sort(ar.begin(),ar.end());
        int ans=~0;
        for(int i=0;i<n;i++){
            if(ar[i]!=br[i]){
                ans=ans&ar[i];
            }
        }
        cout<<ans<<endl;
    }
}