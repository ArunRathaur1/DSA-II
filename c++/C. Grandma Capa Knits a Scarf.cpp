#include<bits/stdc++.h>
using namespace std;
int diff(string s,int n,char ch,int left,int right){
        char c=ch;
        int leftcount=0;
        int flag1=0;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else if((s[left]!=s[right])&&(s[left]==c)){
                left++;
                leftcount++;
            }
            else if((s[left]!=s[right])&&(s[right]==c)){
                right--;
                leftcount++;
            }
            else {
                flag1=1;
                break;
            }
        }
        return (flag1==1)?-1:leftcount;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int left=0;
        int right=n-1;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else break;
        }
        int leftcount=diff(s,n,s[left],left,right);
        int rightcount=diff(s,n,s[right],left,right);
        if(leftcount==-1&& rightcount==-1){
            cout<<-1<<endl;
        }
        else if(leftcount==-1){
            cout<<rightcount<<endl;
        }
        else if(rightcount==-1){
            cout<<leftcount<<endl;
        }
        else{
            cout<<min(leftcount,rightcount)<<endl;
        }
    }
}