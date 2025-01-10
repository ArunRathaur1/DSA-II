#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int c0=0,c1=0;
        for(int i=0;i<n;i++){
            if(a[i]=='0'){
                c0++;
            }
            else{
                c1++;
            }
        }
        int flag=0;
        int turn=0;
        for(int i=n-1;i>=0;i--){
            if(a[i]==b[i]&& turn%2==0){
                if(a[i]=='0'){
                    c0--;
                }
                else{
                    c1--;
                }
            }
            else if(a[i]!=b[i]&& turn%2==1){
                if(a[i]=='0'){
                    c1--;
                }
                else{
                    c0--;
                }
            }
            else{
                if(c0==c1){
                        if(b[i]=='0'){
                        c0--;
                        }
                        else{
                            c1--;
                        }
                        turn++;
                }
                else{
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}