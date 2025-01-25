#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>ar2={7,12,14,15};
    vector<int>ar1={1,2,3,4,9,11};
    int left=0;
    int right=max(ar1.size(),ar2.size())-1;
    int medianindex=((ar1.size()+ar2.size())/2);
    int ans=0;
    int l1=0,l2=0,u1=0,u2=0;
    while(left<=right){
        int mid=(left+right)/2;
         l1=ar1[medianindex-mid];
         l2=ar2[mid];
         u1=ar1[medianindex-mid+1];
         u2=ar2[mid+1];
        if(l1<=u2&& l2>=u1){
            break;
        }
        else if(l1>u2){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<l1<<' '<<u1<<endl;
    cout<<l2<<' '<<u2<<endl;
}