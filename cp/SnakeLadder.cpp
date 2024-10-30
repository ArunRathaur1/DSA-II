#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int bfsTraversal(vector<vector<int>>& board, unordered_map<int, int>& snake, unordered_map<int, int>& ladder) {
    int n = board.size();
    vector<int> visited(n * n + 1, 0);  // Visited array for cells 1 to 100
    queue<pair<int, int>> q;  // Queue to store (position, move count)
    
    q.push({1, 0});  // Start from cell 1 with 0 moves
    visited[1] = 1;
    
    while (!q.empty()) {
        pair<int, int> front = q.front();  // Replace auto [pos, moves]
        int pos = front.first;
        int moves = front.second;
        q.pop();

        // If we reach cell 100, return the move count
        if (pos == 100) return moves;

        // Roll the dice from 1 to 6
        for (int i = 1; i <= 6; i++) {
            int nextPos = pos + i;
            if (nextPos > 100) continue;

            // Check if nextPos has a snake or ladder
            if (snake.count(nextPos)) nextPos = snake[nextPos];
            else if (ladder.count(nextPos)) nextPos = ladder[nextPos];

            // If the cell is not visited, mark as visited and add to queue
            if (!visited[nextPos]) {
                visited[nextPos] = 1;
                q.push({nextPos, moves + 1});
            }
        }
    }

    return -1;  // Return -1 if there's no way to reach cell 100
}

int main() {
    vector<vector<int>> board(10, vector<int>(10, 0));
    
    unordered_map<int, int> snake = {
        {50, 29}, {25, 10}, {89, 2}
    };
    unordered_map<int, int> ladder = {
        {4, 15}, {30, 55}, {67, 93}
    };
    
    int moves = bfsTraversal(board, snake, ladder);
    if (moves != -1)
        cout << "Minimum moves to reach cell 100: " << moves << endl;
    else
        cout << "No way to reach cell 100" << endl;

    return 0;
}
