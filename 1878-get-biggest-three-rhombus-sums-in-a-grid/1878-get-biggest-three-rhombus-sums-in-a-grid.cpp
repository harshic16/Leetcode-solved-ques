class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Prefix sum arrays for diagonal directions
        // diagonalSumDownRight[i][j]: cumulative sum along down-right diagonal ending at (i-1, j-1)
        vector<vector<int>> diagonalSumDownRight(rows + 1, vector<int>(cols + 2));
        // diagonalSumDownLeft[i][j]: cumulative sum along down-left diagonal ending at (i-1, j-1)
        vector<vector<int>> diagonalSumDownLeft(rows + 1, vector<int>(cols + 2));
      
        // Build prefix sums for both diagonal directions
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                // Down-right diagonal: from top-left to bottom-right
                diagonalSumDownRight[i][j] = diagonalSumDownRight[i - 1][j - 1] + grid[i - 1][j - 1];
                // Down-left diagonal: from top-right to bottom-left
                diagonalSumDownLeft[i][j] = diagonalSumDownLeft[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
      
        // Use set to maintain unique sums in sorted order
        set<int> uniqueSums;
      
        // Iterate through each cell as potential rhombus center
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                // Calculate maximum possible rhombus radius from this center
                int maxRadius = min({i - 1, rows - i, j - 1, cols - j});
              
                // Add single cell value (rhombus of size 0)
                uniqueSums.insert(grid[i - 1][j - 1]);
              
                // Try all possible rhombus sizes with current cell as center
                for (int radius = 1; radius <= maxRadius; ++radius) {
                    // Calculate sum of four edges of the rhombus
                    // Right edge: from center going down-right to bottom vertex
                    int rightEdge = diagonalSumDownRight[i + radius][j] - diagonalSumDownRight[i][j - radius];
                    // Bottom edge: from center going down-left to right vertex
                    int bottomEdge = diagonalSumDownRight[i][j + radius] - diagonalSumDownRight[i - radius][j];
                    // Left edge: from center going down-left to bottom vertex
                    int leftEdge = diagonalSumDownLeft[i][j - radius] - diagonalSumDownLeft[i - radius][j];
                    // Top edge: from center going down-right to left vertex
                    int topEdge = diagonalSumDownLeft[i + radius][j] - diagonalSumDownLeft[i][j + radius];
                  
                    // Calculate total rhombus sum
                    // Subtract bottom vertex (counted twice) and add top vertex (not included in edges)
                    int rhombusSum = rightEdge + bottomEdge + leftEdge + topEdge 
                                   - grid[i + radius - 1][j - 1] + grid[i - radius - 1][j - 1];
                    uniqueSums.insert(rhombusSum);
                }
              
                // Keep only the 3 largest sums by removing smallest elements
                while (uniqueSums.size() > 3) {
                    uniqueSums.erase(uniqueSums.begin());
                }
            }
        }
      
        // Return the largest 3 (or fewer) sums in descending order
        return vector<int>(uniqueSums.rbegin(), uniqueSums.rend());
    }
};
