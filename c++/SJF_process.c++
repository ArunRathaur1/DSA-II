#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int>Completed(vector<int>ar,vector<int>br,int size){
    int ct=0;
    int count=0;
    vector<int>ans(size);
    vector<int>Completed(size);
    while(count<size){
        int minbrust=INT_MAX;
        int index=-1;
        for(int i=0;i<size;i++){
            if(ar[i]<ct&& Completed[i]==0&& br[i]<minbrust){
                index=i;
                minbrust=br[i];
            }
        }
        if(index==-1){
            ct++;
            continue;
        }
        ct=ct+br[index];
        ans[index]=ct;
        count++;
        Completed[index]=1;
    }
    return ans;
}
vector<int>CompletionTime(vector<int>ar,vector<int>br,int size){
    int ctime=0;
    vector<int>cr(size);
    vector<int>completed(size,0);
    int cp=0;
    while(cp<size){
        int minbrust=INT_MAX;
        int index=-1;
        for(int i=0;i<ar.size();i++){
            if(ar[i]<=ctime&& completed[i]==0&& br[i]<minbrust){
                index=i;
                minbrust=br[i];
            }
        }
        if(index==-1){
            ctime++;
            continue;
        }
        ctime=ctime+br[index];
        cr[index]=ctime;
        cp++;
        completed[index]=1;
    }
    return cr;
}
int main(){
   
    vector<int>ar={0,1,3,7,9};
    vector<int>br={2,5,6,3,7};
    vector<int>cr=CompletionTime(ar,br,ar.size());
    for(int i=0;i<cr.size();i++){
        cout<<cr[i]<<" ";
    }

}