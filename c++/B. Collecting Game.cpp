#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        unordered_map<int,int>mapping;
        vector<long long>ar(n);
        vector<long long>cumsum(n);
        for(long long i=0;i<n;i++){
            cin>>ar[i];
        }
        vector<long long>sorted=ar;
        sort(sorted.begin(),sorted.end());
        cumsum[0]=sorted[0];
        for(long long i=1;i<n;i++){
            cumsum[i]=cumsum[i-1]+sorted[i];
        }
        for(long long i=n-1;i>=0;i--){
            if(mapping.find(sorted[i])!=mapping.end()){
                continue;
            }
            int tem=i;
            long long total=cumsum[i];
            long long next=0;
            if(i+1<n&&sorted[i+1]<=total){
                tem=mapping[sorted[i+1]];
            } 
            mapping[sorted[i]]=tem;
        }
        for(int i=0;i<n;i++){
            ar[i]=mapping[ar[i]];
        }
        for(int i=0;i<n;i++){
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }
}