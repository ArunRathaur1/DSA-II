#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>ar(n);
        for(long long i=0;i<n;i++)cin>>ar[i];
        vector<long long>ans(n);
        long long count=1;
        long long index=n-1;
        for(long long i=n-1;i>=0;i--){
            while(index>=0&& count<=ar[index]){
                index--;
                count++;
            }
            count--;
            ans[i]=count;
        }
        for(long long i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}