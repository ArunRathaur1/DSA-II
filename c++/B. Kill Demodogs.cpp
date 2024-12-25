#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to calculate the MEX of a set of values
int calculateMex(const unordered_set<int>& friends_values) {
    int mex = 0;
    // Find the smallest non-negative integer not in the set
    while (friends_values.count(mex)) {
        mex++;
    }
    return mex;
}

int main() {
    int t;  // Number of test cases
    cin >> t;
    
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        
        // Initialize a vector to store the MEX values of dragons
        vector<int> a(n, 0);  // All dragons start with value 0
        
        // Convert 1-based indexing to 0-based for internal use
        x--; 
        y--;
        
        bool changed;
        
        // Keep iterating until no values change
        do {
            changed = false;
            
            // Temporary vector to store the new MEX values
            vector<int> new_a = a;

            // Iterate over all dragons and calculate their MEX values
            for (int i = 0; i < n; ++i) {
                // Set to hold the values of the neighboring dragons
                unordered_set<int> friends_values;
                
                // Left and right neighbors (circular)
                friends_values.insert(a[(i - 1 + n) % n]);  // Left neighbor
                friends_values.insert(a[(i + 1) % n]);      // Right neighbor
                
                // Add the values of x and y if they are friends
                if (i == x) friends_values.insert(a[y]);
                if (i == y) friends_values.insert(a[x]);
                
                // Calculate the MEX for this dragon
                int new_mex = calculateMex(friends_values);
                
                // If the value has changed, mark that we need to process again
                if (new_mex != a[i]) {
                    new_a[i] = new_mex;  // Update the value
                    changed = true;
                }
            }
            
            // Update the vector with new MEX values for the next iteration
            a = new_a;
            
        } while (changed);  // Continue looping as long as there are changes
        
        // Output the resulting MEX values for all dragons
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
