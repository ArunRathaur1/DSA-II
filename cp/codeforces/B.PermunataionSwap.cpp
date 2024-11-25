#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        for(int i=0;i<n;i++){
            ar[i]=abs(ar[i]-i-1);
        }
        int g=ar[0];
        for(int i=0;i<n;i++){
            g=__gcd(ar[i],g);
        }
        cout<<g<<endl;
    }
    
}