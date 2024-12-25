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
        vector<long long>tem;
        long long left=0;
        long long right=n-1;
        while(left<right){
            tem.push_back(abs(ar[left]-ar[right]));
            left++;
            right--;
        }
        long long g=0;
        for(long long i=0;i<tem.size();i++){
            g=__gcd(g,tem[i]);
        }
        cout<<g<<endl;
    }
}