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
        vector<int>diff(k+1,INT_MIN);
        map<int,int>pre;
        for(int i=0;i<n;i++){
            if(pre.find(ar[i])==pre.end()){
                diff[ar[i]]=i;
                pre[ar[i]]=i;
            }
            else{
                diff[ar[i]]=max(diff[ar[i]],i-pre[ar[i]]-1);
                pre[ar[i]]=i;
            }
        }
        for(int i=0;i<k+1;i++){
            diff[i]=max(diff[i],n-pre[i]-1);
        }
        for(int i=1;i<k+1;i++){
            cout<<diff[i]<<" ";
        }
        cout<<endl;
        int p=INT_MAX;
        for(int i=1;i<k+1;i++){
                p=min(p,diff[i]/2);
        }
        cout<<(p<0?0:p)<<endl;
    }
}