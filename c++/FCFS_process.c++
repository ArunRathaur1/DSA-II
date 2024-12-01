#include<bits/c++io.h>
#include<vector>
#include<iostream>
using namespace std;
vector<int> completionTime(vector<int>ar,vector<int>br,int size){
    vector<int>ct(size);
    ct[0]=(ar[0]+br[0]);
    for(int i=1;i<size;i++){
        int t=max(ct[i-1],ar[i]);
        ct[i]=(t+br[i]);
    }
    return ct;
}
int main(){
    vector<int>ar={0,1,3,7,9};
    vector<int> br={2,5,6,3,7};
    vector<int>ct=completionTime(ar,br,ar.size());
    for(int i=0;i<ar.size();i++){
        cout<<ct[i]<<" "<<endl;
    }
}