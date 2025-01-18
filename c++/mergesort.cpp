#include<bits/stdc++.h>
using namespace std;
void addarray(vector<int>&ar,int mid,int left,int right){
    //first left->mid
    //second mid+1,right
    vector<int>sorted;
    int i=left;
    int j=mid+1;
    while(i<=mid&& j<=right){
        if(ar[i]>ar[j]){
            sorted.push_back(ar[j]);
            j++;
        }
        else{
            sorted.push_back(ar[i]);
            i++;
        }
    }
    while(i<=mid){
        sorted.push_back(ar[i]);
        i++;
    }
    while(j<=right){
        sorted.push_back(ar[j]);
        j++;
    }
    int index=0;
    for(int i=left;i<=right;i++){
        ar[i]=sorted[index];
        index++;
    }
}
void mergersort(vector<int>&ar,int left,int right){
    if(left<right){
         int mid=(left+right)/2;
        mergersort(ar,left,mid);
        mergersort(ar,mid+1,right);
        addarray(ar,mid,left,right);
    }
}
int main(){
    vector<int>ar={1,3,2,5,1};
    mergersort(ar,0,4);
    for(int i=0;i<5;i++){
        cout<<ar[i]<<' ';
    }
    cout<<endl;
}