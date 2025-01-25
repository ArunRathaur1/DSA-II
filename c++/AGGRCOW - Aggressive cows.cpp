#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int>ar,int x,int mindis,int size){
    int curr=ar[0];
    int p=x-1;
    for(int i=1;i<size;i++){
        int currdis=ar[i]-curr;
        if(currdis>=mindis){
            p--;
            curr=ar[i];
        }
    }
    if(p>0)return false;
    return true;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        if(c==2){
            cout<<ar[n-1]-ar[0]<<endl;
            continue;
        }
        sort(ar.begin(),ar.end());
        int left=1;
        int right=ar[n-1];
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(possible(ar,c,mid,n)){
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