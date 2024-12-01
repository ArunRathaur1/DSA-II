#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> Completion(vector<int> ar, vector<int> br, int size, int quantum) {
    int start=0;
    int count=0;
    queue<int>q;
    vector<int>ans(ar.size());
    for(int i=0;i<ar.size();i++){
        if(ar[i]<=start){
            q.push(i);
            ar[i]=-1;
        }
    }
    while(!q.empty()||count<size){
        if(!q.empty()){
            int x=q.front();
            q.pop();
            if(br[x]>quantum){
                br[x]=br[x]-quantum;
                start=start+quantum;
                for(int i=0;i<ar.size();i++){
                    if(ar[i]<=start&& ar[i]>=0){
                        q.push(i);
                        ar[i]=-1;
                    }
                }
                q.push(x);
            }
            else{
                start=start+br[x];
                br[x]=0;
                ans[x]=start;
                count++;
                for(int i=0;i<ar.size();i++){
                    if(ar[i]<=start&& ar[i]>=0){
                        q.push(i);
                    }
                }
            }
        }
        else{
            for(int i=0;i<ar.size();i++){
                if(ar[i]>=0){
                    start=ar[i];
                    q.push(ar[i]);
                    break;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arrivalTime = {0, 4, 6, 8, 10};
    vector<int> burstTime = {3, 6, 4, 5, 2};
    int quantum = 2;

    // Call the Completiontime function
    vector<int> completionTime = Completion(arrivalTime, burstTime, arrivalTime.size(), quantum);

    // Print the results
    cout << "Completion Times:\n";
    for (int time : completionTime) {
        cout << time << " ";
    }
    cout << endl;

    return 0;
}