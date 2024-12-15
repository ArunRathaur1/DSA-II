#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        double bits=floor(log2(n-1))+1;
        int value=pow(2,bits-1);
        for(int i=n-1;i>=value;i--){
        cout<<i<<" ";
        }
        for(int i=0;i<value;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
}