#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        cin>>n;
        vector<int>ar(n),br(n);
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        for(int i=0;i<n;i++){
            cin>>br[i];
        }
        int i=0,j=0;
        set<int>st;
        while(i<n&&j<n){
            if(st.find(ar[i])!=st.end())i++;
            else if(ar[i]==br[i]){
                i++;
                j++;
            }
            else{
                st.insert(br[i]);
                j++;
            }
        }
        for(auto i: st){
            cout<<i<<' ';
        }
        cout<<endl;
        while(i<n){
            st.insert(ar[i]);
        }
        cout<<st.size()<<endl;
    }