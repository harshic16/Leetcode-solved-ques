class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Create prefix sum array with extra padding for easier calculation
        // prefixSum[i][j][0] stores count of 'X' from (0,0) to (i-1,j-1)
        // prefixSum[i][j][1] stores count of 'Y' from (0,0) to (i-1,j-1)
        vector<vector<vector<int>>> prefixSum(rows + 1, 
                                              vector<vector<int>>(cols + 1, 
                                              vector<int>(2, 0)));
      
        int result = 0;
      
        // Build prefix sum array and count valid submatrices
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                // Calculate prefix sum for 'X' count using inclusion-exclusion principle
                prefixSum[i][j][0] = prefixSum[i - 1][j][0] 
                                    + prefixSum[i][j - 1][0] 
                                    - prefixSum[i - 1][j - 1][0]
                                    + (grid[i - 1][j - 1] == 'X' ? 1 : 0);
              
                // Calculate prefix sum for 'Y' count using inclusion-exclusion principle
                prefixSum[i][j][1] = prefixSum[i - 1][j][1] 
                                    + prefixSum[i][j - 1][1] 
                                    - prefixSum[i - 1][j - 1][1]
                                    + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
              
                // Check if current submatrix from (0,0) to (i-1,j-1) is valid
                // Valid means: contains at least one 'X' and equal number of 'X' and 'Y'
                if (prefixSum[i][j][0] > 0 && prefixSum[i][j][0] == prefixSum[i][j][1]) {
                    ++result;
                }
            }
        }
      
        return result;
    }
};
