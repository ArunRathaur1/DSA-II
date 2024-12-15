#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,d;
        cin>>n>>d;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        sort(ar.begin(),ar.end());
        int count=0;
        int values=n;
        for(int i=n-1;i>=0;i--){
            int k=ar[i];
            int index=1;
            while(k<=d){
                k=k+ar[i];
                index++;
            }
            values=values-index;
            if(values<0)break;
            count++;
        }
        cout<<count<<'\n';
}