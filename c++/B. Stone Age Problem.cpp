#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>ar(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        sum=sum+ar[i];
    }
    map<int,int>chang1;
    int chang2=-1;
    int chang2value=0;
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int index,value;
            cin>>index>>value;
            index--;
            if(chang1[index]>chang2){
                sum=sum-ar[index]+value;
            }
            else{
                sum=sum+value-chang2value;
            }
            chang1[index]=i;
            ar[index]=value;
            cout<<sum<<endl;
        }
        else{
            int value;
            cin>>value;
            sum=value*n;
            cout<<sum<<endl;
            chang2=i;
            chang2value=value;
        }
    }
}