#include<bits/stdc++.h>
using namespace std;
// Function to calculate LCM
long long lcm(long long a, long long b) {
    return (a * b) / __gcd(a, b);
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,x,y;
        cin>>n>>x>>y;
        long long p1=n/x;
        long long p2=n/y;
        long long p3=n/(lcm(x,y));
        long long n1=p1-p3;
        long long n2=p2-p3;
        long long sum=(n1*(2*n-(n1-1)))/2-(n2*(n2+1))/2;
        cout<<sum<<endl;
    }
}