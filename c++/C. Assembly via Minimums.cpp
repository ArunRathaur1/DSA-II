#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p=(n*(n-1))/2;
        vector<int> arr(p);
        
        // Reading input into arr
        for (int i = 0; i < p; i++) {
            cin >> arr[i];
        }
        
        // Sorting arr in descending order
        sort(arr.begin(), arr.end(), greater<int>());
        // Building the ar array
        vector<int> ar;
        ar.push_back(arr[0] ); // Adding the first element
        int count = 1; // Track consecutive elements
        int temcount=1;
        for (int i = 0; i <p; i++) {
            if (count == temcount) { // Add new element when condition matches
                ar.push_back(arr[i]);
                temcount++;
                count = 0; // Reset count
            }
            count++;
        }
        
        // Printing the result
        for (int i = 0; i < n; i++) {
            cout << ar[i] << ' ';
        }
        cout << endl; // Newline for the next test case
    }
    return 0;
}
