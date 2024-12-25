#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> ar(n), br(n), cr(n);

        for (int i = n-1; i >=0; i--) cin >> ar[i];
        for (int i = n-1; i >=0; i--)  cin >> br[i];
        for (int i = n-1; i >=0; i--) cin >> cr[i];
        int curror = 0;
        bool possible = false;
        while(true){
            int count=0;

            if(ar.size()>0&& (x|ar[ar.size()-1])==x){
                curror=curror|ar[ar.size()-1];
                ar.pop_back();
                if(curror==x){
                    possible=true;
                    break;
                }
                count++;
            }
            if(br.size()>0&& (x|br[br.size()-1])==x){
                curror=curror|br[br.size()-1];
                br.pop_back();
                if(curror==x){
                    possible=true;
                    break;
                }
                count++;
            }
            if(cr.size()>0&& (x|cr[cr.size()-1])==x){
                curror=curror|cr[cr.size()-1];
                cr.pop_back();
                if(curror==x){
                    possible=true;
                    break;
                }
                count++;
            }
            if(count==0){
                break;
            }
        }
        if(curror==x){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}
