class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // Calculate the total sum of all elements in the grid
        long long totalSum = 0;
        for (const auto& row : grid) {
            for (int value : row) {
                totalSum += value;
            }
        }
      
        // If total sum is odd, we cannot partition into two equal halves
        if (totalSum % 2 != 0) {
            return false;
        }
      
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Try to partition horizontally (cut between rows)
        long long prefixSum = 0;
        for (int i = 0; i < rows; ++i) {
            // Add current row's sum to prefix sum
            for (int value : grid[i]) {
                prefixSum += value;
            }
          
            // Check if we've reached half of total sum and not at the last row
            if (prefixSum * 2 == totalSum && i + 1 < rows) {
                return true;
            }
        }
      
        // Try to partition vertically (cut between columns)
        prefixSum = 0;
        for (int j = 0; j < cols; ++j) {
            // Add current column's sum to prefix sum
            for (int i = 0; i < rows; ++i) {
                prefixSum += grid[i][j];
            }
          
            // Check if we've reached half of total sum and not at the last column
            if (prefixSum * 2 == totalSum && j + 1 < cols) {
                return true;
            }
        }
      
        // No valid partition found
        return false;
    }
};
