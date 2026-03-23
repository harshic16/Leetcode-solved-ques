using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        // dp[i][j][0] stores minimum product to reach (i,j)
        // dp[i][j][1] stores maximum product to reach (i,j)
        // We track both min and max because negative numbers can flip min to max
        vector<vector<vector<ll>>> dp(rows, vector<vector<ll>>(cols, vector<ll>(2)));
      
        // Initialize starting point
        dp[0][0][0] = grid[0][0];  // min at (0,0)
        dp[0][0][1] = grid[0][0];  // max at (0,0)
      
        // Initialize first column (can only come from above)
        for (int i = 1; i < rows; ++i) {
            dp[i][0][0] = dp[i - 1][0][0] * grid[i][0];
            dp[i][0][1] = dp[i - 1][0][1] * grid[i][0];
        }
      
        // Initialize first row (can only come from left)
        for (int j = 1; j < cols; ++j) {
            dp[0][j][0] = dp[0][j - 1][0] * grid[0][j];
            dp[0][j][1] = dp[0][j - 1][1] * grid[0][j];
        }
      
        // Fill the dp table for remaining cells
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                int currentValue = grid[i][j];
              
                if (currentValue >= 0) {
                    // For positive numbers:
                    // - minimum stays minimum after multiplication
                    // - maximum stays maximum after multiplication
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * currentValue;
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * currentValue;
                } else {
                    // For negative numbers:
                    // - maximum becomes minimum after multiplication
                    // - minimum becomes maximum after multiplication
                    dp[i][j][0] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * currentValue;
                    dp[i][j][1] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * currentValue;
                }
            }
        }
      
        // Get the maximum product at destination
        ll maxProduct = dp[rows - 1][cols - 1][1];
      
        // Return -1 if the maximum product is negative, otherwise return modulo result
        return maxProduct < 0 ? -1 : static_cast<int>(maxProduct % MOD);
    }
};
