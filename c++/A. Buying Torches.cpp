#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long x,y,k;
        cin>>x>>y>>k;
        long long total=k+y*k;
        long long operation=0;
        operation=operation+(((total-1)+(x-2))/(x-1));
        operation=operation+k;
        cout<<operation<<endl;

    }
    
}