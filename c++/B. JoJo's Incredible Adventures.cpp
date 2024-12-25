#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long m=0;
        s=s+s;
        long long n=s.length();
        long long count=0;
        for(long long i=0;i<n;i++){
            if(s[i]=='1')count++;
            else{
                m=max(m,count);
                count=0;
            }
        }
        m=max(m,count);
        if(m>n/2){
            cout<<(n/2)*(n/2)<<endl;
            continue;
        }
        m=m+1;
        if(m%2==0){
            cout<<(m/2)*(m/2);
        }
        else{
            cout<<(m/2)*(m/2+1);
        }
        cout<<endl;
    }
}