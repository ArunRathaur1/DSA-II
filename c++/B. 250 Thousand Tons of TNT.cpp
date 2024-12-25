#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<int>ar(n);
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
                cin>>ar[i];
                prefix[i+1]=prefix[i]+ar[i];
        }
        int absdiff=0;
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                int maxdiff=INT_MIN;
                int mindff=INT_MAX;
                for(int j=i;j<=n;j=j+i){
                    maxdiff=max(maxdiff,prefix[j]-prefix[j-i]);
                    mindff=min(mindff,prefix[j]-prefix[j-i]);
                }
                absdiff=max(absdiff,maxdiff-mindff);
            }
        }
    cout<<absdiff<<endl;
}
}