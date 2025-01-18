#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    long long numVertices;
    cin >> numVertices;

    vector<string> adjacencyMatrix(numVertices);
    for (long long i = 0; i < numVertices; ++i) {
        cin >> adjacencyMatrix[i];
    }

    vector<long long> permutation(numVertices);
    iota(permutation.begin(), permutation.end(), 0);

    sort(permutation.begin(), permutation.end(), [&](long long vertexA, long long vertexB) {
        if (vertexA < vertexB) {
            return adjacencyMatrix[vertexA][vertexB] == '1';
        }
        return adjacencyMatrix[vertexB][vertexA] == '0';
    });

    for (long long i = 0; i < numVertices; ++i) {
        cout << permutation[i] + 1 << (i + 1 == numVertices ? "\n" : " ");
    }
}

int main() {
    long long testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
