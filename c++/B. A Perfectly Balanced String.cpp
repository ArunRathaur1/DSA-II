#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<char>ch;
        unordered_set<char>c;
        int l=s.length();
        for(int i=0;i<l;i++){
            if(c.find(s[i])==c.end()){
                ch.push_back(s[i]);
                c.insert(s[i]);
            }
        }
        int index=0;
        int flag=0;
        for(int i=0;i<l;i++){
            if(s[i]==ch[index]){
                index++;
                if(index==ch.size())index=0;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}