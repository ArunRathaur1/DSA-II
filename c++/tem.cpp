#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int c=0;
        while(i<n){
            if(arr[i]==i){
                c++;
            }
            else{
                int tem=arr[i];
                while(i<=tem){
                    if(arr[i]>tem){
                        tem=arr[i];
                    }
                    i++;
                }
                c++;
            }
        }
        cout<<c<<endl;
    }
};
int main(){
    Solution ob;
    //[4,3,2,1,0]
    vector<int>ar={4,3,2,1,0};
    ob.maxChunksToSorted(ar);
}