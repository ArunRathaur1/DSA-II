#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>ar(n),br(n);
        int bmax=INT_MIN;
        int index=0;
        for(int i=0;i<n;i++)cin>>ar[i];
        for(int i=0;i<n;i++)cin>>br[i];
        int currmax=0;
        int totalsum=0;
        int currsum=0;
        for(int i=0;i<n;i++){
            if(i>k-1){
                break;
            }
            currsum=currsum+ar[i];
            currmax=max(currmax,br[i]);
            int total=currsum+(k-i-1)*currmax;
            totalsum=max(total,totalsum);
        }
        cout<<totalsum<<endl;
    }
}