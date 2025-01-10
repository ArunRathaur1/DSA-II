#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[ar[i]%k]++;
        }
        int count=0;
        if(m[0]>0){
            count++;
        }
        for(int i=1;i<=k/2;i++){
            if(m[i]>0||m[k-i]>0){
                if(i==k-i){
                    count++;
                }
                else{
                    int x=m[i];
                    int y=m[k-i];
                    count++;
                    if(x>y){
                        count=count+max(0,x-y-1);
                    }
                    else{
                        count=count+max(0,y-x-1);
                    }
                }
            }
        }
        cout<< count<<endl;
    }
}