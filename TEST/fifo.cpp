#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>pages={1,2,4,3,2,1,4,2,1,2,3,5,3,2,1};
     set<int>st;
     queue<int>q;
     int capcity=4;
     int pagefault=0;
     int index=0;
     int p=0;
     while(p<capcity){
        if(st.find(pages[index])==st.end()){
            st.insert(pages[index]);
            q.push(pages[index]);
            pagefault++;
            p++;
        }
        index++;
     }
     for(int i=index;i<pages.size();i++){
        if(st.find(pages[i])==st.end()){
            pagefault++;
            int x=q.front();
            q.pop();
            q.push(pages[i]);
            st.erase(x);
            st.insert(pages[i]);
        }
     }
     cout<<pagefault<<endl;
}