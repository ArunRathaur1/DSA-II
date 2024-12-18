#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        int ans=INT_MAX;
        for(int i=0;i<10;i++){
          int turn=i;
          int tem=b+i;
          int x=a;
          if(tem>=2){
            while(x!=0){
                x=x/tem;
                turn++;
            }
            ans=min(ans,turn);
          }  
        }
        cout<<ans<<endl;
    }
}