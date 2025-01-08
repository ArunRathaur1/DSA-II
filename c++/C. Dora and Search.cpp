#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ar(n);
        for(int i=0;i<n;i++)cin>>ar[i];
        vector<int>ns=ar;
        sort(ar.begin(),ar.end());
        int left=0;
        int right=n-1;
        int l1=0;
        int l2=n-1;
        int flag=-1;
        while(left<right){
            if(ns[left]==ar[l1]){
                left++;
                l1++;
            }
            else if(ns[left]==ar[l2]){
                left++;
                l2--;
            }
            else if(ns[right]==ar[l1]){
                right--;
                l1++;
            }
            else if(ns[right]==ar[l2]){
                right--;
                l2--;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag==1)
        cout<<left+1<<" "<<right+1<<endl;
        else{
            cout<<-1<<endl;
        }
    }
}