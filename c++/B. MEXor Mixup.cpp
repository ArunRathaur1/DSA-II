#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    const int size=3e5+10;
    vector<int>xors(size,0);
    for(int i=1;i<size;i++){
        xors[i]=xors[i-1]^i;
    }
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        int x=xors[a-1];
        if(x==b){
            cout<<a<<endl;
        }
        else{
            x=x^b;
            if(x==a){
                cout<<a+2<<endl;
            }
            else{
                cout<<a+1<<endl;
            }
        }
    }
    
}