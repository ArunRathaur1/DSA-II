#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        vector<long long>ar(n);
        for(long long i=0;i<n;i++)cin>>ar[i];
        long long count=0;
        for(long long i=0;i<30;i++){
            long long c=0;
            for(long long j=0;j<n;j++){
                if(ar[j]>=pow(2,i)&& ar[j]<pow(2,i+1)){
                    c++;
                }
            }
            if(c>=2){
                count=count+(c*(c-1))/2;
            }
        }
        cout<<count<<endl;
    }
    
}