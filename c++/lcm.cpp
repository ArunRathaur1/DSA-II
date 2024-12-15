#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p=sqrt(n);
        int lcm=0;
        int num1=-1;
        int num2=-1;
        int maxnumber=INT_MIN;
        if(n%2==0){
            cout<<n/2<<' '<<n/2<<endl;
            continue;
        }
        for(int i=1;i<=p;i++){
            if(n%i==0){
                int factor1=i;
                int factor2=n/i;
                if((factor1==1||factor1>factor2)){
                    if(factor1>maxnumber){
                        num1=factor1;
                        num2=n-factor1;
                        maxnumber=factor1;
                    }
                }
                else{
                    if(factor2>maxnumber){
                         num1=factor2;
                        num2=n-factor2;
                        maxnumber=factor2;
                    }
                }

            }
        }
        cout<<num1<<" "<<num2<<endl;
    }
}