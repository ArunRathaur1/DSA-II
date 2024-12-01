#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        if(n%2==0){
            cout<<n/2<<" "<<n/2<<endl;
        }
        else{
            int hcf=1;
            int num1=0;
            int num2=0;
            for(int i=1;i<n;i=i+2){
                if((n-i)*i%hcf==0){
                    num1=i;
                    num2=n-i;
                    hcf++;
                } 
            }
            cout<<num1<<" "<<num2<<endl;
        }
    }
    return 0;
}
