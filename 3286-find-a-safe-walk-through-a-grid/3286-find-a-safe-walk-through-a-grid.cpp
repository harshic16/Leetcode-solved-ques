class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // Get grid dimensions
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Initialize distance matrix to track minimum cost to reach each cell
        // dist[i][j] represents the minimum health lost to reach cell (i, j)
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
      
        // Starting point cost is the value at grid[0][0]
        dist[0][0] = grid[0][0];
      
        // BFS queue to explore cells
        queue<pair<int, int>> bfsQueue;
        bfsQueue.emplace(0, 0);
      
        // Direction vectors for moving up, right, down, left
        // dirs[i] and dirs[i+1] form (dx, dy) pairs
        int dirs[5] = {-1, 0, 1, 0, -1};
      
        // BFS to find minimum cost path
        while (!bfsQueue.empty()) {
            // Get current cell coordinates
            auto [currentX, currentY] = bfsQueue.front();
            bfsQueue.pop();
          
            // Explore all 4 adjacent cells
            for (int i = 0; i < 4; ++i) {
                int nextX = currentX + dirs[i];
                int nextY = currentY + dirs[i + 1];
              
                // Check if next cell is within bounds and if we found a better path
                if (nextX >= 0 && nextX < rows && 
                    nextY >= 0 && nextY < cols && 
                    dist[nextX][nextY] > dist[currentX][currentY] + grid[nextX][nextY]) {
                  
                    // Update minimum cost to reach the next cell
                    dist[nextX][nextY] = dist[currentX][currentY] + grid[nextX][nextY];
                  
                    // Add the cell to queue for further exploration
                    bfsQueue.emplace(nextX, nextY);
                }
            }
        }
      
        // Check if we can reach destination with remaining health
        return dist[rows - 1][cols - 1] < health;
    }
};
