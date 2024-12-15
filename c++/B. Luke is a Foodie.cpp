#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        int count=0;
        int currmin=ar[0];
        int currmax=ar[0];
        for(int i=0;i<n;i++){
            currmin=min(ar[i],currmin);
            currmax=max(ar[i],currmax);
            if(currmax-currmin>2*x){
                count++;
                currmin=ar[i];
                currmax=ar[i];
            }
        }
        cout<<count<<endl;
    }
    
}