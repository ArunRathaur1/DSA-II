#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>ar(n);
        for(long long i=0;i<n;i++)cin>>ar[i];
        if(ar[n-1]<0){
            long long flag=0;
            for(long long i=1;i<n;i++){
                if(ar[i-1]>ar[i]){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                cout<<-1<<endl;
            }else{
                cout<<0<<endl;
            }
            continue;
            
        }
        if(ar[n-2]>ar[n-1]){
            cout<<-1<<endl;
        }
        else{
            long long op=0;
            vector<vector<long long>>tem;
            for(long long i=n-3;i>=0;i--){
                if(ar[i]>ar[i+1]){
                    op++;
                    ar[i]=ar[i+1]-ar[n-1];
                    tem.push_back({i+1,i+2,n});
                }
            }
            cout<<op<<endl;
            for(long long i=0;i<op;i++){
                cout<<tem[i][0]<<' '<<tem[i][1]<<' '<<tem[i][2]<<endl;
            }
        }
    }
}