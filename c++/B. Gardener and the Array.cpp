#include<bits/stdc++.h>
using namespace std;
string solve(){
     long long n;
        cin>>n;
        vector<vector<long long>>ar;
        vector<long long>size(n,0);
        map<long long,long long>m;
        for(long long i=0;i<n;i++){
            cin>>size[i];
            vector<long long>tem(size[i],-1);
            for(long long j=0;j<size[i];j++){
                cin>>tem[j];
                m[tem[j]]++;
            }
            ar.push_back(tem);
        }
        for(auto i: ar){
            long long flag=0;
            for(long long j:i){
                if(m[j]-1<=0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return "Yes";
            }
        }
        return "No";
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        string ans=solve();
        cout<<ans<<endl;
    }
}