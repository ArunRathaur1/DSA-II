#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        int x=0;
        int tem=ar[n-1];
        for(int i=n-1;i>=0;i--){
            if(tem==ar[i])x++;
            else break;
        }
        int count=0;
        while(x<n){
            count=count+1;
            int index=n-2*x-1;
            int p=0;
            while(index>=0&& tem==ar[index]){
                index--;
                p++;
            }
            x=2*x+p;
        }

        cout<<count<<endl;
    }
}