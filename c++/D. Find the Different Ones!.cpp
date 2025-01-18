#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        vector<pair<int,int>>diff(n);
        for(auto& i: diff){
            i.first=-1;
            i.second=-1;
        }
        for(int i=1;i<n;i++){
            if(ar[i]!=ar[i-1]){
                diff[i].first=i-1;
            }
            else{
                diff[i].first=diff[i-1].first;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ar[i]!=ar[i+1]){
                diff[i].second=i+1;
            }
            else{
                diff[i].second=diff[i+1].second;
            }
        }
        int q;
        cin>>q;
        while(q--){
            int left,right;
            cin>>left>>right;
            // cout<<diff[left-1].first<<" "<<diff[left-1].second<<endl;
            // cout<<diff[right-1].first<<" "<<diff[right-1].second<<endl;
            if(diff[left-1].second<=right-1&& diff[left-1].second!=-1){
                cout<<left<<" "<<diff[left-1].second+1<<endl;
            }
            else if(diff[right-1].first>=left-1) {
                cout<<diff[right-1].first+1<<" "<<right<<endl;
            }
            else{
                cout<<"-1"<<" "<<"-1"<<endl;
            }
        }
        cout<<endl;
        
    }
}