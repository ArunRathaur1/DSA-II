#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        
        int n,r,b;
        cin>>n>>r>>b;
        string s="";
        int count=0;
        if(r>b){
            int p=(r/(1+b));
            int q=(r%(1+b));
            int index=0;
            int tem=q;
            for(int i=0;i<r-tem;i++){
                s=s+'R';
                index++;
                if(index==p&& count<b){
                    if(q>0){
                    s=s+'R';
                        q--;
                    }
                    s=s+'B';
                    index=0;
                    count++;
                }
            }
        }
        else if(b>r){
             int p=(b/(1+r));
             int rem=(b%(1+r));
             int index=0;
             int tem=rem;
            for(int i=0;i<b-tem;i++){
                s=s+'B';
                index++;
                if(index==p&& count<r){
                    if(rem>0){
                        rem--;
                        s=s+'B';
                    }
                    s=s+'R';
                    index=0;
                    count++;
                }
            }
        }
        else{
            for(int i=0;i<r;i++){
                cout<<"RB";
            }
            cout<<endl;
        }
        cout<<s<<endl;
    }

    
}