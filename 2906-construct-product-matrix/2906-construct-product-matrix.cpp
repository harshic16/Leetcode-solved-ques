class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Initialize result matrix
        vector<vector<int>> result(rows, vector<int>(cols));
      
        // First pass: Calculate suffix products
        // Traverse from bottom-right to top-left
        long long suffixProduct = 1;
        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                // Store the product of all elements after current position
                result[row][col] = suffixProduct;
                // Update suffix product for next iteration
                suffixProduct = (suffixProduct * grid[row][col]) % MOD;
            }
        }
      
        // Second pass: Multiply with prefix products
        // Traverse from top-left to bottom-right
        long long prefixProduct = 1;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // Multiply suffix product with prefix product
                // This gives product of all elements except current one
                result[row][col] = (result[row][col] * prefixProduct) % MOD;
                // Update prefix product for next iteration
                prefixProduct = (prefixProduct * grid[row][col]) % MOD;
            }
        }
      
        return result;
    }
};
