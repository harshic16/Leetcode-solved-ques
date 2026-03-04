class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // Get matrix dimensions
        int numRows = mat.size();
        int numCols = mat[0].size();
      
        // Arrays to store the sum of each row and column
        vector<int> rowSum(numRows, 0);
        vector<int> colSum(numCols, 0);
      
        // Calculate the sum of 1s in each row and column
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                rowSum[row] += mat[row][col];
                colSum[col] += mat[row][col];
            }
        }
      
        // Count special positions
        int specialCount = 0;
      
        // A position is special if:
        // 1. The element at that position is 1
        // 2. The sum of its row is 1 (only one 1 in the row)
        // 3. The sum of its column is 1 (only one 1 in the column)
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (mat[row][col] == 1 && rowSum[row] == 1 && colSum[col] == 1) {
                    specialCount++;
                }
            }
        }
      
        return specialCount;
    }
};
