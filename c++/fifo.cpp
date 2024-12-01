#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int Pagefault(vector<int>pages){
    set<int>ar;
    int pagefault=0;
    int limit=4;
    set<int>s;
    int p=0;
    int index=0; queue<int>q;
    while(p<limit){
        if(s.find(pages[index])==s.end()){
            s.insert(pages[index]);
            q.push(pages[index]);
            p++;
            pagefault++;
        }
        index++;
    }
    for(int i=index;i<pages.size();i++){
        if(s.find(pages[i])==s.end()){
            pagefault++;
            int x=q.front();
            q.pop();
            s.erase(x);
            s.insert(pages[i]);
            q.push(pages[i]);
        }
    }
    return pagefault;
}
int main(){
    vector<int>pages={7,0,1,2,0,3,0,4,2,3,0,3,2};
    int p=Pagefault(pages);
    cout<<p<<endl;
}

// #include<iostream>
// #include<vector>
// #include<set>
// #include<queue>
// using namespace std;

// int Pagefault(vector<int> pages) {
//     set<int> s;  // To store pages currently in memory
//     int pagefault = 0;
//     int limit = 4;  // Max number of pages that can be in memory
//     queue<int> q;   // Queue to simulate FIFO page replacement

//     for (int i = 0; i < pages.size(); i++) {
//         // If the page is not in memory
//         if (s.find(pages[i]) == s.end()) {
//             // If memory is full, remove the oldest page
//             if (s.size() == limit) {
//                 int x = q.front();
//                 q.pop();
//                 s.erase(x);
//             }
//             // Insert the new page and add it to the queue
//             s.insert(pages[i]);
//             q.push(pages[i]);
//             pagefault++;
//         }
//     }
//     return pagefault;
// }

// int main() {
//     vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
//     int p = Pagefault(pages);
//     cout << "Total page faults: " << p << endl;
// }
