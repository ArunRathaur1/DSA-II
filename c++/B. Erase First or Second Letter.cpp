#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_set<char>st;
        int substring=0;
        for(int i=0;i<n;i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
                substring=substring+(n-i);
            }
        }
        cout<<substring<<endl;
    }
}