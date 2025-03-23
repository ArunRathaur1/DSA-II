#include<bits/stdc++.h>
using namespace std;
int main(){
        string s;
        cin>>s;
        long long n=s.length();
        long long wcountleft=0;
        long long wcountright=0;
        long long vcount=0;
        for(long long i=0;i<n;i++){
            if(s[i]=='v')vcount++;
            else{
                if(vcount<1)continue;
                wcountright+=vcount-1;
                vcount=0;
            }
        }
        if(vcount>1)wcountright=wcountright+vcount-1;
        vcount=0;
        long long ans=0;
        for(long long i=0;i<n;i++){
            if(s[i]=='v')vcount++;
            else{
                if(vcount>1){
                    wcountleft=wcountleft+vcount-1;
                    wcountright=wcountright-(vcount-1);
                    ans=ans+wcountleft*wcountright;
                }
                else if(s[i]=='o'){
                    ans=ans+wcountleft*wcountright;
                }
                vcount=0;
            }
        }
        cout<<ans<<endl;
    }