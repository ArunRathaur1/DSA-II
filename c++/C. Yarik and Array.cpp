#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a;
        cin>>a;
        int sum=a;
        int maxsum=a;
        int parity=abs(a)%2;
        for(int i=1;i<n;i++){
            int b;
            cin>>b;
            if(abs(b)%2!=parity){
                sum=sum+b;
            }
            else{
                sum=b;
            }
            if(sum<b){
                sum=b;
            }
            maxsum=max(maxsum,sum);
             parity=abs(b)%2;
        }
        cout<<maxsum<<endl;
    }
}