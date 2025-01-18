#include<bits/stdc++.h>
using namespace std;
void quicksort(vector<int>&ar,int left,int right){
    if(left>=right)return;
    int pivot=ar[left];
    int i=left,j=right;
    while(i<=j){
        if(ar[i]<=pivot){
            i++;
        }
        else if(ar[j]>=pivot){
            j--;
        }
        else{
            swap(ar[j],ar[i]);
        }
    }
    swap(ar[left],ar[j]);
    quicksort(ar,left,j-1);
    quicksort(ar,j+1,right);
}
int main(){
    vector<int>ar={4 ,1, 3 ,9, 7};
    quicksort(ar,0,4);
    for(int i=0;i<5;i++){
        cout<<ar[i]<<' ';
    }
    cout<<endl;
}