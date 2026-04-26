class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Track visited cells to avoid revisiting
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
      
        // Direction vectors for moving up, right, down, left
        const vector<int> directions = {-1, 0, 1, 0, -1};

        // Check each cell as a potential starting point for a cycle
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // Skip if this cell has already been visited
                if (!visited[row][col]) {
                    // BFS to detect cycle starting from current cell
                    // Queue stores: {current_row, current_col, parent_row, parent_col}
                    queue<array<int, 4>> bfsQueue;
                    bfsQueue.push({row, col, -1, -1});
                    visited[row][col] = true;

                    while (!bfsQueue.empty()) {
                        auto current = bfsQueue.front();
                        bfsQueue.pop();
                      
                        int currentRow = current[0];
                        int currentCol = current[1];
                        int parentRow = current[2];
                        int parentCol = current[3];

                        // Explore all 4 adjacent cells
                        for (int dir = 0; dir < 4; ++dir) {
                            int nextRow = currentRow + directions[dir];
                            int nextCol = currentCol + directions[dir + 1];
                          
                            // Check if next cell is within grid bounds
                            if (nextRow >= 0 && nextRow < rows && 
                                nextCol >= 0 && nextCol < cols) {
                              
                                // Skip if different character or if it's the parent cell
                                if (grid[nextRow][nextCol] != grid[currentRow][currentCol] || 
                                    (nextRow == parentRow && nextCol == parentCol)) {
                                    continue;
                                }
                              
                                // Cycle detected: found a visited cell with same character
                                // that is not the parent
                                if (visited[nextRow][nextCol]) {
                                    return true;
                                }
                              
                                // Mark as visited and add to queue for further exploration
                                bfsQueue.push({nextRow, nextCol, currentRow, currentCol});
                                visited[nextRow][nextCol] = true;
                            }
                        }
                    }
                }
            }
        }
      
        // No cycle found in the entire grid
        return false;
    }
};