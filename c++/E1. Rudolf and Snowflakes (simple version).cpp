#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
       cin>>n;
       if(n<6){
        cout<<"NO"<<endl;
        return;
       }
       for(int r=2;r<1000;r++){
        long long sum=1+r;
        long long power=r;
            for(int p=2;p<20;p++){
                power=power*r;
                sum=sum+power;
                if(sum==n){
                    cout<<"YES"<<endl;
                    return;
                }
                if(sum>n)break;
            }
       }
       cout<<"NO"<<endl;
       return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}