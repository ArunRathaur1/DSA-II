#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<vector<long long>>monsters;
        for(long long i=0;i<n;i++){
            long long size;
            cin>>size;
            vector<long long>tem(size);
            for(long long i=0;i<size;i++){
                cin>>tem[i];
            }
            monsters.push_back(tem);
        }
        vector<pair<long long,long long>>io;
        long long index=0;
        for(auto monster:monsters){
            long long currmin=INT_MIN;
            int count=0;
            long long size=monster.size();
            for(long long i=0;i<size;i++){
                currmin=max(currmin,monster[i]+1-count);
                count++;
            }
            io.push_back({currmin,index});
            index++;
        }
        sort(io.begin(),io.end());
        long long currmin=INT_MIN;
        int count=0;
        for(auto x:io) {
            long long index=x.second;
            vector<long long>monster=monsters[index];
            long long size=monster.size();
            for(long long i=0;i<size;i++){
                currmin=max(currmin,monster[i]+1-count);
                count++;
            }

        } 
        cout<<currmin<<endl;
    }
}