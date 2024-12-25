#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        sort(ar.begin(),ar.end());
        int left=0;
        int right=1;
        int flag=0;
        while(right<n){
            if(ar[right]-ar[left]>k){
                left++;
            }
            else if(ar[right]-ar[left]<k){
                right++;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
}