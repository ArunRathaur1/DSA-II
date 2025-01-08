#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<long long>ar(m);
        for(long long i=0;i<m;i++)cin>>ar[i];
        vector<long long>diff;
        sort(ar.begin(),ar.end());
        for(long long i=1;i<m;i++){
            diff.push_back(ar[i]-ar[i-1]-1);
        }
        diff.push_back(n-ar[m-1]+ar[0]-1);
        sort(diff.begin(),diff.end(),greater<>());
        long long count=0;
        long long tem=0;
        for(long long i=0;i<m;i++){
            if(diff[i]-tem==1){
                count++;
                tem=tem+4;
            }
            else if(diff[i]-tem>1){
                count=count+diff[i]-tem-1;
                tem=tem+4;
            }
            else{
                break;
            }
        }
        cout<<n-count<<endl;
    }
}