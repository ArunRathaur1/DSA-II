#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        map<long long,long long>m;
        for(long long i=0;i<n;i++){
            long long x;
            cin>>x;
            m[x]++;
        }
        long long count=0;
        auto it=m.begin();
        while(it!=m.end()){
            if(it->second!=0){
                count++;
                auto tem=it;
                long long index=it->first;
                while(tem!=m.end()&& tem->first==index){
                    if(tem->second<=0)break;
                    tem->second--;
                    index++;
                    tem++;
                }
            }
            if(it->second==0){
                it++;
            }
        }
        cout<<count<<endl;
    }
}