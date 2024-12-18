#include<bits/stdc++.h>
using namespace std;
unordered_set<string>getsubarray(string s){
    int n=s.length();
    unordered_set<string>ans;
    for(int i=0;i<n;i++){
        string g="";
        for(int j=i;j<n;j++){
            g=g+s[j];
            ans.insert(g);
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int l1=s1.length();
        int l2=s2.length();
        unordered_set<string>st=getsubarray(s1);
        int minoperation=l1+l2;
        for(auto i: st){
            int x=s2.find(i);
            if(x!=std::string::npos){
                int tem=i.length();
                minoperation=min(minoperation,l1-tem+l2-tem);
            }
        }
        cout<<minoperation<<endl;
    }
}