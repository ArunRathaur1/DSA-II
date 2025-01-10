#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count0=0;
        int alice=0,bob=0;
        int turn=0;
        int index=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')count0++;
        }
        if(count0==0){
            cout<<"DRAW"<<endl;
        }
        else if(s.length()%2!=0&&s[s.length()/2]=='0'){
            if(count0==1){
                cout<<"BOB"<<endl;
            }
            else{
                cout<<"ALICE"<<endl;
            }
        }
        else{
            cout<<"BOB"<<endl;
        }
    }
}