#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int curr=0;
        int flag=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(curr>x){
                flag=1;
            }
            curr=x-curr;
        }
        if(flag==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}