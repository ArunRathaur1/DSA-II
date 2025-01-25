#include<bits/stdc++.h>
using namespace std;
vector<int> solve(){
    int n;
    cin>>n;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                n=n/i;
                for(int j=2;j<=sqrt(n);j++){
                    if(n%j==0&& n/j!=i&& j!=i && n/j!=j){
                        return {i,j,n/j};
                    }
                }
                return{-1};
            }
        }
        return {-1};
}
int main(){
    long long t;
    cin>>t;
    while(t--){
       vector<int>ans=solve();
       if(ans.size()==1){
        cout<<"NO"<<endl;
       }
       else{
        cout<<"YES"<<endl;
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
       }
    }
}
