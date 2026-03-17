class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // Get matrix dimensions
        int numRows = matrix.size();
        int numCols = matrix[0].size();
      
        // Transform matrix: each cell stores the consecutive 1s above it (including itself)
        // This creates a histogram representation for each row
        for (int row = 1; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (matrix[row][col] == 1) {
                    // Add the height of consecutive 1s from the row above
                    matrix[row][col] = matrix[row - 1][col] + 1;
                }
            }
        }
      
        // Find the maximum area rectangle
        int maxArea = 0;
      
        // Process each row to find the largest rectangle ending at that row
        for (auto& currentRow : matrix) {
            // Sort heights in descending order to maximize rectangle area
            // Larger heights come first, allowing us to form wider rectangles
            sort(currentRow.rbegin(), currentRow.rend());
          
            // Calculate the maximum area for rectangles in this row
            // Width is (col + 1), height is the minimum height up to this column
            for (int col = 0; col < numCols; ++col) {
                int currentArea = (col + 1) * currentRow[col];
                maxArea = max(maxArea, currentArea);
            }
        }
      
        return maxArea;
    }
};
