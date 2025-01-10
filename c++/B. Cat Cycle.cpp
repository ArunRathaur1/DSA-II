#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n%2==0){
            cout<<(k%n==0?n:k%n)<<endl;
        }
        else{
            int loops=k/(n/2+1);
           if(loops%2==0){
            int range=n-n/2-1;
            int x=loops/range;
            int count=loops%range;
            int cata=x+
           }
        }
    }
}