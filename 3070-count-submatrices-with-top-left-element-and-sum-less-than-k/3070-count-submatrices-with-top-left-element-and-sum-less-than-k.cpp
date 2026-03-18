class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // Get dimensions of the grid
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Create a 2D prefix sum array with padding
        // prefixSum[i][j] represents the sum of all elements in the submatrix 
        // from (0,0) to (i-1,j-1) in the original grid
        vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1, 0));
      
        // Counter for valid submatrices
        int count = 0;
      
        // Build prefix sum array and count valid submatrices
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                // Calculate prefix sum using inclusion-exclusion principle
                // Current sum = sum above + sum to the left - overlap + current element
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] 
                                 - prefixSum[i - 1][j - 1] + grid[i - 1][j - 1];
              
                // Check if the sum of submatrix from (0,0) to current position is <= k
                if (prefixSum[i][j] <= k) {
                    ++count;
                }
            }
        }
      
        return count;
    }
};
