class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        // Get matrix dimensions
        int numRows = mat.size();
        int numCols = mat[0].size();
      
        // Optimize k by taking modulo with number of columns
        // since shifting by numCols positions returns to original state
        k %= numCols;
      
        // Check each row to verify if matrix remains similar after k shifts
        for (int row = 0; row < numRows; ++row) {
            // Check each element in the current row
            for (int col = 0; col < numCols; ++col) {
                // For odd-indexed rows (1, 3, 5, ...), perform left shift
                // Left shift by k is equivalent to comparing with element at (col + k) % numCols
                if (row % 2 == 1) {
                    int shiftedCol = (col + k) % numCols;
                    if (mat[row][col] != mat[row][shiftedCol]) {
                        return false;
                    }
                }
              
                // For even-indexed rows (0, 2, 4, ...), perform right shift
                // Right shift by k is equivalent to comparing with element at (col - k + numCols) % numCols
                if (row % 2 == 0) {
                    int shiftedCol = (col - k + numCols) % numCols;
                    if (mat[row][col] != mat[row][shiftedCol]) {
                        return false;
                    }
                }
            }
        }
      
        // All elements match their shifted positions
        return true;
    }
};
