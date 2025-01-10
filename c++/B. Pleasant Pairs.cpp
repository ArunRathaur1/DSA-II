#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back({x,i+1});
        }
        sort(arr.begin(),arr.end());
        //{vlaue,index}
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i].first*arr[j].first>2*n)break;
                if(arr[i].first*arr[j].first==arr[i].second+arr[j].second){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}