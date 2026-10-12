#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> lake(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> lake[i][j];
        }
    }
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int maxFish = 0;
    
    // Directions for adjacent cells (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (lake[i][j] > 0 && !visited[i][j]) {
                // Found a new water cell, start BFS to find connected component
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int currentFish = 0;
                
                while (!q.empty()) {
                    auto [row, col] = q.front();
                    q.pop();
                    currentFish += lake[row][col];
                    
                    // Check all 4 adjacent cells
                    for (auto& dir : directions) {
                        int newRow = row + dir.first;
                        int newCol = col + dir.second;
                        
                        // Check bounds and if it's a water cell and not visited
                        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && 
                            lake[newRow][newCol] > 0 && !visited[newRow][newCol]) {
                            visited[newRow][newCol] = true;
                            q.push({newRow, newCol});
                        }
                    }
                }
                
                // Update maximum fish count
                maxFish = max(maxFish, currentFish);
            }
        }
    }
    
    cout << maxFish << endl;
    
    return 0;
}