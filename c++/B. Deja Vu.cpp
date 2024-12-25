#include<bits/stdc++.h>
using namespace std;
vector<long long> power2(){
    long long tem=1;
    vector<long long>ans;
    for(long long i=0;i<31;i++){
        tem=pow(2,i);
        ans.push_back(tem);
    }
    return ans;
}
int main(){
    vector<long long>powers=power2();
    long long t;
    cin>>t;
    while(t--){
        long long n,q;
        cin>>n>>q;
        vector<long long>ar(n);
        vector<long long>p(q);
        for(long long i=0;i<n;i++)cin>>ar[i];
        for(long long i=0;i<q;i++)cin>>p[i];
        unordered_set<long long>numbers;
        for(long long i=0;i<q;i++){
           if(numbers.find(p[i])==numbers.end()){
                for(long long j=0;j<n;j++){
                    if(ar[j]%powers[p[i]]==0){
                        ar[j]=ar[j]+powers[p[i]-1];
                    }
                }
                numbers.insert(p[i]);
           }
        }
        for(long long i=0;i<n;i++){
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }
}