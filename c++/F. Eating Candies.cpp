#include<bits/stdc++.h>
using namespace std;
int  main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>ar(n);
        for(long long i=0;i<n;i++)cin>>ar[i];
        long long alice=0;
        long long bob=0;
        long long left=0;
        long long right=n-1;
        long long ans=0;
        long long currcount=0;
        while(left<right){
            if(alice+ar[left]>bob+ar[right]){
                bob=bob+ar[right];
                currcount++;
                right--;
            }
            else if(alice+ar[left]<bob+ar[right]){
                alice=alice+ar[left];
                currcount++;
                left++;
            }
            else{
                currcount=currcount+2;
                alice=alice+ar[left];
                bob=bob+ar[right];
                ans=max(ans,currcount);
                left++;
                right--;
            }
        }
        cout<<ans<<endl;
    }
}