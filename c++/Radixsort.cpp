#include<bits/stdc++.h>
using namespace std;
vector<int>countsort(vector<int>ar,int index){
    vector<int>array(10,0);
    int x=ar.size();
    vector<int>output(x,0);
    for(int i=0;i<x;i++){
        int p=(ar[i]/index)%10;
        array[p]++;
    }
    for(int i=1;i<10;i++){
        array[i]=array[i]+array[i-1];
    }
    for(int i=x-1;i>=0;i--){
        int p=(ar[i]/index)%10;
        output[array[p]-1]=ar[i];
        array[p]--;
    }
    return output;

}
void radixsort(vector<int>&ar,int n){
    int m=*max_element(ar.begin(),ar.end());
    int digits=to_string(m).length();
    int index=1;
    for(int i=0;i<digits;i++){
       vector<int>csort=countsort(ar,index);
       ar=csort;
       index=index*10;
    }
}
int compareVersion(string version1, string version2) {
        stringstream ss(version1);
        vector<string>ar1;
        string g;
        while(getline(ss,g,'.')){
            ar1.push_back(g);
        }
    }
int main(){
    vector<int>ar={10,20,500,375,30};
    int bucketsize=10;
    vector<int>tem={INT_MAX,INT_MIN};
     vector<vector<int>>buckets(bucketsize,vector<int>(2,tem));
    radixsort(ar,5);
    for(int i=0;i<5;i++){
        cout<<ar[i]<<' ';
    }
}