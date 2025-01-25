#include<bits/stdc++.h>
using namespace std;
long long maxsum(vector<long long>ar,long long left,long long right){
    long long sum=0;
    long long maxsum=LONG_MIN;
    for(long long i=left;i<=right;i++){
        if(sum<=0){
            sum=0;
        }
        sum=sum+ar[i];
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}
int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long n;
        long long ya=0;
        cin>>n;
        vector<long long>ar(n);
        for(long long i=0;i<n;i++){
            cin>>ar[i];
            ya=ya+ar[i];
        }
        long long leftpart=maxsum(ar,0,n-2);
        long long rightpart=maxsum(ar,1,n-1);
        long long m=max(leftpart,rightpart);
        if(ya>m){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}