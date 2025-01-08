#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>prices(n),money(n);
        vector<long long>ar(n);
        for(long long i=0;i<n;i++){
            cin>>prices[i];
        }
        for(long long i=0;i<n;i++){
            cin>>money[i];
            ar[i]=money[i]-prices[i];
        }
        sort(ar.begin(),ar.end());
        long long left=0;
        long long right=n-1;
        long long count=0;
        while(left<right){
            if(ar[left]+ar[right]>=0){
                count++;
                left++;
                right--;
            }
            else{
                left++;
            }
        }
        cout<<count<<endl;
    }
}