#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,l;
        cin>>n>>l;
        string s;
        cin>>s;
        int black=0;
        int white=0;
        for(int i=0;i<l;i++){
            if(s[i]=='W'){
                  white++;
            }
        }
        int left=0;
        int right=l;
        int mincount=white;
        while(right<n){
            if(s[left]=='W'){
                white--;
            }
            if(s[right]=='W'){
                white++;
            }
            right++;
            left++;
            mincount=min(mincount,white);
        }
        cout<<mincount<<endl;
    }
    
}