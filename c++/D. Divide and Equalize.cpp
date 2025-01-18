#include<bits/stdc++.h>
using namespace std;
void findprimefactors(long long n, map<long long, long long>& m) {
    while (n % 2 == 0) {
        m[2]++;
        n /= 2;
    }
    for (long long x = 3; x <= sqrt(n); x += 2) {
        while (n % x == 0) {
            m[x]++;
            n /= x;
        }
    }
    if (n > 2) {
        m[n]++;
    }
}

bool solve(){
    long long n;
        cin>>n;
        vector<long long>ar(n);
        for(long long i=0;i<n;i++)cin>>ar[i];
        map<long long,long long>m;
        for(long long i=0;i<n;i++){
            findprimefactors(ar[i],m);
        }
        for(auto i:m){
            if(i.second%n!=0)return false;
        }
        return true;
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        bool ans=solve();
        cout<<(ans==1?"YES":"NO")<<endl;
    }
}