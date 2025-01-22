#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findKRotation(vector<int> &ar) {
        // Code Here
        int min=INT_MAX;
        int index=0;
        int left=0;
        int right=ar.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(ar[mid]>=ar[left]){
                if(min>ar[left]){
                    index=left;
                    min=ar[left];
                }
                left=mid+1;
            }
            else{
                if(min>ar[mid]){
                    index=mid;
                    min=ar[mid];
                }
                right=mid-1;
            }
        }
        return index;
    }
};
int main(){
    vector<int>ar={39, 6, 11, 14, 18, 36, 37, 38};
    Solution ob;
    int x=ob.findKRotation(ar);
    cout<<x;
}