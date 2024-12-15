#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long w,h;
        cin>>w>>h;
        long long d,u,r,l;
        cin>>d;
        vector<long long>down(d,0);
        for(int i=0;i<d;i++)cin>>down[i];
        cin>>u;
        vector<long long>up(u,0);
        for(int i=0;i<u;i++)cin>>up[i];
        cin>>l;
        vector<long long>left(l,0);
        for(int i=0;i<l;i++)cin>>left[i];
        cin>>r;
        vector<long long>right(r,0);
        for(int i=0;i<r;i++)cin>>right[i];
        long long int choice1=(down[d-1]-down[0])*h;
        long long int choice2=(up[u-1]-up[0])*h;
        long long int choice3=(left[l-1]-left[0])*w;
        long long int choice4=(right[r-1]-right[0])*w;
        long long int ans=max({choice1,choice2,choice3,choice4});
        cout<<ans<<endl;
    }
}