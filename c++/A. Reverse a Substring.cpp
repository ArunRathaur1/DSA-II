#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int flag=0;
        int l=0;
        int r=0;
        for(int i=0;i<n-1;i++){
            if(s[i]>s[i+1]){
                flag=1;
                l=i;
                r=i+1;
                break;
            }
        }
        if(flag==0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<l+1<<" "<<r+1<<endl;
        }
    
}