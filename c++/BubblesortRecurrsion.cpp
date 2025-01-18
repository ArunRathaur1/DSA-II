#include<bits/stdc++.h>
using namespace std;
void bubblesort(vector<int>&ar,int index,int n){
    if(index>=n)return;
    int currmin=ar[index];
    int currindex=index;
    for(int i=index+1;i<n;i++){
        if(currmin>ar[i]){
            currmin=ar[i];
            currindex=i;
        }
    }
    swap(ar[currindex],ar[index]);
    bubblesort(ar,index+1,n);
}
int main(){
    vector<int>ar={1,3,2,5,3,2,5};
    bubblesort(ar,0,7);
    for(int i=0;i<7;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}