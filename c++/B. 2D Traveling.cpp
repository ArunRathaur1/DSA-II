#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long k;
        cin>>k;
        long long start,end;
        cin>>start>>end;
        vector<long long>xcor,ycor;
        for(long long i=0;i<n;i++){
            long long x,y;
            cin>>x>>y;
            xcor.push_back(x);
            ycor.push_back(y);
        }
        long long case1=abs(xcor[start-1]-xcor[end-1])+abs(ycor[start-1]-ycor[end-1]);
        if(k==0){
            cout<<case1<<endl;
            continue;
        }
            long long pricea_major=LLONG_MAX;
            long long priceb_major=LLONG_MAX;
            for(long long i=0;i<k;i++){
                pricea_major=min(pricea_major,abs(xcor[start-1]-xcor[i])+abs(ycor[start-1]-ycor[i]));
                priceb_major=min(priceb_major,abs(xcor[end-1]-xcor[i])+abs(ycor[end-1]-ycor[i]));
            }
            long long case2=pricea_major+priceb_major;
            cout<<min(case1,case2)<<endl;
    }
}