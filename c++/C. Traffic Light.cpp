#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        char ch;
        cin>>ch;
        string s;
        cin>>s;
        s=s.append(s);
        int total=INT_MIN;
        vector<int>green;
        for(int i=0;i<2*n;i++){
            if(s[i]=='g'){
                green.push_back(i);
            }
        }
        int size=green.size();
        int index=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                int tem=i;
                while (tem>green[index]7)
                {
                    index++;
                }
                total=max(total,green[index]-i);
            }
        }
        cout<<total<<endl;
    }
    
}