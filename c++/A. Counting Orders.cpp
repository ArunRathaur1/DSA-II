#include<bits/stdc++.h>
using namespace std;
#define modulo 1000000007
int main(){
    long long t;
    cin>>t;
    while (t--)
    {
        
        long long n;
        cin>>n;
        vector<long long>ar(n),br(n);
        for(long long i=0;i<n;i++)cin>>ar[i];
        for(long long i=0;i<n;i++)cin>>br[i];
        vector<long long>greater(n,0);
        sort(ar.begin(),ar.end());
        sort(br.begin(),br.end());
        long long left=0;
        long long index=0;
        for(long long i=0;i<n;i++){
            while(left<n&& ar[left]<=br[i]){
                left++;
            }
            greater[index]=(n-left);
            index++;
        }
        long long ans=1;
        for(long long i=0;i<n;i++){

            ans=(ans*(greater[n-i-1]-i))%modulo;
            if(ans==0)break;
        }
        cout<<ans<<endl;
    }
    
}