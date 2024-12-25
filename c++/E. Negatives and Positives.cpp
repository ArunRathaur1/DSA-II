#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long sum=0;
        long long negative=0;
        long long m=INT_MAX;
        for(long long i=0;i<n;i++){
            long long x;
            cin>>x;
            if(x<0){
                negative++;
            }
            sum=sum+abs(x);
            m=min(m,abs(x));
        }
        if(negative%2==0){
            cout<<sum<<endl;
        }else{
            cout<<sum-2*m<<endl;
        }
    }
}