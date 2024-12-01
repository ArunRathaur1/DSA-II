#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>ar={1,2,4,3,2,1,4,2,1,2,3,5,3,2,1};
    set<int>st;
    map<int,int>m;
    int capcity=4;
    int index=0;
    int p=0;
    int pagefault=0;
    while(p<capcity){
        if(st.find(ar[index])==st.end()){
            st.insert(ar[index]);
            pagefault++;
            p++;
        }
        m[ar[index]]=index;
        index++;
    }
    for(int i=index;i<ar.size();i++){
        if(st.find(ar[i])==st.end()){
            pagefault++;
            int value=-1,id=INT_MAX;
            for(auto I : st){
                if(m[I]<id){
                    value=I;
                    id=m[I];
                }
            }
            st.insert(ar[i]);
            st.erase(value);
        }
        m[ar[i]]=i;
    }
    cout<<pagefault<<endl;

}