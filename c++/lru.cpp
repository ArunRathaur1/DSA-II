#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<climits>
using namespace std;
int Pagefualt(vector<int> pages,int n,int capcity){
    int pagefault=0;
    unordered_map<int,int>m;
    unordered_set<int>st;
    int p=0;
    int index=0;
    while(p<capcity){
        if(st.find(pages[index])==st.end()){
            st.insert(pages[index]);
            m[pages[index]]=index;
            p++;
            pagefault++;
        }
        index++;
    }
    for(int i=index;i<n;i++){
        if(st.find(pages[i])==st.end()){
            pagefault++;
            int e;
            int m1=-1;
            for(auto element: st){
                if(m[element]<m1){
                    e=element;
                    m1=m[element];
                }
            }
            st.erase(e);
            st.insert(pages[i]);
            m[pages[i]]=i;
        }
    }
    return pagefault;
}
int main(){
      vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int p = Pagefualt(pages,pages.size(),4);
    cout << "Total page faults: " << p << endl;
}