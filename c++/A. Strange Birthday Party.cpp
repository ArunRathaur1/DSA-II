#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<long long>number(n),cost(m);
        for(long long i=0;i<n;i++)cin>>number[i];
        for(long long i=0;i<m;i++)cin>>cost[i];
        sort(number.begin(),number.end(),greater<long long>());
        sort(cost.begin(),cost.end());
        long long index=0;
        long long currsum=0;
        for(long long i=0;i<n;i++){
            if(index<m && cost[number[i]-1]>cost[index]){
                currsum=currsum+cost[index];
                index++;
            }
            else{
                currsum=currsum+cost[number[i]-1];
            }
        }
        cout<<currsum<<endl;
    }
}