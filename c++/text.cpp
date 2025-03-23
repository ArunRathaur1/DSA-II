#include<bits/stdc++.h>
using namespace std;
void insertion(vector<int>&ar){
    for(int i=1;i<ar.size();i++){
        int key=ar[i];
        int j=i-1;
        while(j>=0&& ar[j]>key){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=key;
    }
}
void selection(vector<int>&ar){
    for(int i=0;i<ar.size();i++){
        int key=ar[i];
        int index=i;
        for(int j=i+1;j<ar.size();j++){
            if(key>ar[j]){
                key=ar[j];
                index=j;
            }
        }
        swap(ar[i],ar[index]);
    }
}
void bubblesort(vector<int>&ar){
    int n=ar.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(ar[j+1]<ar[j]){
                swap(ar[j+1],ar[j]);
            }
        }
    }
}
void countingsort(vector<int>&ar){
    vector<int>counts(*max_element(ar.begin(),ar.end())+1,0);
    for(int i=0;i<ar.size();i++){
        counts[ar[i]]++;
    }
    int index=0;
    for(int i=0;i<counts.size();i++){
        int p=0;
        while(p<counts[i]){
           ar[index]=i;
           index++;
           p++; 
        }
    }
}

void quicksort(vector<int>&ar,int left,int right){
    if(left>=right)return;
    int p=ar[left];
    int l=left+1;
    int r=right;
    while(l<=r){
        if(p>ar[l]){
            l++;
        }
        else if(p<ar[r]){
            r--;
        }
        else{
            swap(ar[l],ar[r]);
            l++;
            r--;
        }
    }
    swap(ar[r],ar[left]);
    quicksort(ar,left,r);
    quicksort(ar,r+1,right);
}
void merge(vector<int>&ar,int mid,int left,int right){
    vector<int>x1,x2;
    for(int i=left;i<=mid;i++){
        x1.push_back(ar[i]);
    }
    for(int i=mid+1;i<=right;i++){
        x2.push_back(ar[i]);
    }
    int n1=x1.size();
    int n2=x2.size();
    int i1=0,i2=0;
    int index=left;
    while(i1<n1&& i2<n2){
        if(x1[i1]>=x2[i2]){
            ar[index]=x2[i2];
            i2++;
            index++;
        }
        else{
            ar[index]=x1[i1];
            i1++;
            index++;
        }
    }
    while(i1<n1){
        ar[index] = x1[i1];
        i1++;
        index++;
    }
    while(i2<n2){
        ar[index] = x2[i2];
        i2++;
        index++;
    }
}
void meregersort(vector<int>&ar,int left,int right)
{
    if(left>=right)return ;
    int mid=(left+right)/2;
    meregersort(ar,left,mid);
    meregersort(ar,mid+1,right);
    merge(ar,mid,left,right);
}
void heapify(vector<int>&ar,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&ar[left]>ar[largest]){
        largest=left;
    }
    else if(right<n&& ar[right]>ar[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(ar[largest],ar[i]);
        heapify(ar,n,largest);
    }
}
void heapsort(vector<int>&ar,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(ar,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(ar[i],ar[0]);
        heapify(ar,i,0);
    }
}
int getdigit(int n){
    int x=0;
    while(n!=0){
        n=n/10;
        x++;
    }
    return x;
}
void radixcounting(vector<int>&ar,int d){
    vector<int>counts(10,0);
    vector<int>ans(ar.size(),0);
    for(int i=0;i<ar.size();i++){
        int p=ar[i]/(pow(10,d));
        int index=p%10;
        counts[index]++;
    }
    for(int i=1;i<10;i++){
        counts[i]=counts[i-1]+counts[i];
    }
    for(int i=0;i<ar.size();i++){
        int p = ar[i] / (pow(10, d));
        int index = p % 10;
        ans[counts[index]-1]=ar[i];
        counts[index]--;
    }
    for(int i=0;i<ans.size();i++){
        ar[i]=ans[i];
    }
}
void radixsort(vector<int>&ar){
    int p=*max_element(ar.begin(),ar.end());
    int x=getdigit(p);
    for(int i=0;i<x;i++){
        radixcounting(ar,i);
    }
}
void bucketsort(vector<int>&ar){
    int n=*max_element(ar.begin(),ar.end())+1;
    vector<vector<int>>bucket(4);
    for(int i=0;i<ar.size();i++){
        double p=double(ar[i])/double(n);
        int index=p*4;
        cout<<index<<endl;
        bucket[index].push_back(ar[i]);
    }
    for(int i=0;i<bucket.size();i++){
        for(int j=0;j<bucket[i].size();j++){
            cout<<bucket[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<int >ar={5,3,5,6,2,2,5};
    bucketsort(ar);
}