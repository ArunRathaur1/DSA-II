#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long  a,b;
        cin>>a>>b;
        if(a>b){
            long long op=0;
            while(a>b){
                if(a%8==0&&a/8>=b){
                    op++;
                    a=a/8;
                }
                else if(a%4==0&&a/4>=b){
                    op++;
                    a=a/4;
                }
                else if(a%2==0&&a/2>=b){
                    op++;
                    a=a/2;
                }
                else{
                    break;
                }
            }
            cout<<(a!=b?-1:op)<<endl;
        }
        else if(b>a){
             long long op=0;
            while(b>a){
                if(a*8<=b){
                    op++;
                    a=a*8;
                }
                else if(a*4<=b){
                    op++;
                    a=a*4;
                }
                else if(a*2<=b){
                    op++;
                    a=a*2;
                }
                else{
                    break;
                }
            }
            cout<<(a!=b?-1:op)<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}