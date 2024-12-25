#include<bits/stdc++.h>
using namespace std;
bool fill(long long mid,vector<long long>ar,long long w,long long n){
    long long currwater=0;
    for(long long i=0;i<n;i++){

        if(mid>ar[i])
        currwater=currwater+mid-ar[i];

        if(currwater>w)return false;
    }
   return true;
}
int main(){
    long long t;
    cin>>t;
    while (t--)
    {
       long long n,w;
       cin>>n>>w;
        vector<long long>ar(n);
        vector<long long>rock(n+1,0);
       for(long long i=0;i<n;i++){
            cin>>ar[i];
       }
       sort(ar.begin(),ar.end());
        long long left=0;
        long long right=w+*max_element(ar.begin(),ar.end());
        long long ans=0; 
        while(left<=right){
            long long mid=(right+left)/2;
            if(fill(mid,ar,w,n)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    
}