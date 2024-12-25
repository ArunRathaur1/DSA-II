#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>ar(n),br(n);
        for(long long i=0;i<n;i++)cin>>ar[i];
        for(long long i=0;i<n;i++)cin>>br[i];
        long long left=0;
        long long right=n-1;
        while(left<right){
            if(ar[left]==br[left]){
                left++;
            }
            else if(ar[right]==br[right]){
                right--;
            }
            else{
                break;
            }
        }
        while(left-1>=0&& br[left]>=br[left-1]){
            left--;
        }
        while(right+1<n &&br[right]<=br[right+1]){
            right++;
        }
        cout<<left+1<<" "<<right+1<<endl;
    }
}