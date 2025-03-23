#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n ;
    vector<long long> ar(n);
    map<long long, vector<long long>> m;
    set<long long>st;
    long long sum=0;
    for (long long i = 0; i < n; i++)
    {
        cin >> ar[i];
        m[ar[i]].push_back(i+1);
        sum=sum+ar[i];
    }
    for(long long i=0;i<n;i++){
        long long p=sum-2*ar[i];
        if(m.find(p)!=m.end()){
            for(auto i: m[p]){
                st.insert(i);
            }
        }
    }
    cout<<st.size()<<endl;
    for(auto i:st){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}