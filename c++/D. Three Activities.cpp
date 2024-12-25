#include<bits/stdc++.h>
using namespace std;
void takeinput(vector<pair<long long,long long>>&ar,long long n){
    long long index=0;
    for(long long i=0;i<n;i++){
        long long x;
        cin>>x;
        if(ar.size()<3){
            ar.push_back({x,index});
        }
        else{
             long long minelement = INT_MAX;
            long long minidex = -1;
            for (long long j = 0; j < 3; j++) {
                if (ar[j].first < minelement) {
                    minelement = ar[j].first;
                    minidex = j;
                }
            }
            if (x > minelement) {
                ar[minidex] = {x, index};
            }
        }
        index++;
    }
}
int main(){
    long long t;
    cin>>t;
    while (t--)
    {
       long long n;
       cin>>n;
       vector<pair<long long,long long>>ar,br,cr;
       takeinput(ar,n);
       takeinput(br,n);
       takeinput(cr,n);
       long long m=0;
       for(long long i=0;i<3;i++){
        for(long long j=0;j<3;j++){
            for(long long k=0;k<3;k++){
                if(ar[i].second!=br[j].second&& br[j].second!=cr[k].second&& cr[k].second!=ar[i].second){
                    m=max(m,ar[i].first+br[j].first+cr[k].first);
                }
               }
            }
        }
        cout<<m<<endl;
       }
    }  