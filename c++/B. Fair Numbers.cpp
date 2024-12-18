#include<bits/stdc++.h>
using namespace std;
bool checkdivisible(long long n){
    long long tem=n;
    while(tem!=0){
        long long x=tem%10;
        if(x!=0&& n%x!=0){
            return false;
        }
        tem=tem/10;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        while (true)
        {
            if(checkdivisible(n)){
            break;
           } 
           n=n+1;
        }
        cout<<n<<endl;
    }
}