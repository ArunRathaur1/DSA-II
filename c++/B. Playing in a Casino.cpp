#include<bits/stdc++.h>
using namespace std;
vector<vector<long long>> tranpose(vector<vector<long long>>ar,long long m,long long n){
    vector<vector<long long>>arr(m,vector<long long>(n));
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            arr[j][i]=ar[i][j];
        }
    }return arr;
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<vector<long long>>arr(n,vector<long long>(m));
        for(long long i=0;i<n;i++){
            for(long long j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        vector<vector<long long>>ar=tranpose(arr,m,n);
        for(long long i=0;i<m;i++){
            sort(ar[i].begin(),ar[i].end());
        }
        long long total=0;
        for(long long i=0;i<m;i++){
            for(long long j=0;j<n;j++){
                total=total+(n-j-1)*(ar[i][j])*-1+j*ar[i][j];
            }
        }
        cout<<total<<endl;
    }
}