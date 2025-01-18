#include<bits/stdc++.h>
using namespace std;
void insertionsort(vector<int>&ar,int index,int n){
    if(index>n)return;
    int value=ar[index];
    int j=index-1;
    while (j>=0&ar[j]>value)
    {
        ar[j+1]=ar[j];
        j--;
    }
    ar[j+1]=value;
    insertionsort(ar,index+1,n);
    
}
int main(){
    vector<int>ar={1,3,2,5,1};
    insertionsort(ar,1,4);
    for(int i=0;i<5;i++){
        cout<<ar[i]<<' ';
    }
    cout<<endl;
}