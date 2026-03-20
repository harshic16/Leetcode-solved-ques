class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Initialize result matrix with dimensions (rows - k + 1) x (cols - k + 1)
        vector<vector<int>> result(rows - k + 1, vector<int>(cols - k + 1, 0));
      
        // Iterate through all possible k x k subgrids
        for (int startRow = 0; startRow <= rows - k; ++startRow) {
            for (int startCol = 0; startCol <= cols - k; ++startCol) {
              
                // Collect all elements from the current k x k subgrid
                vector<int> subgridElements;
                for (int row = startRow; row < startRow + k; ++row) {
                    for (int col = startCol; col < startCol + k; ++col) {
                        subgridElements.push_back(grid[row][col]);
                    }
                }
              
                // Sort elements to find minimum absolute difference between adjacent distinct values
                sort(subgridElements.begin(), subgridElements.end());
              
                // Find minimum absolute difference between consecutive distinct elements
                int minDifference = INT_MAX;
                for (int i = 1; i < subgridElements.size(); ++i) {
                    // Only consider distinct consecutive elements
                    if (subgridElements[i] != subgridElements[i - 1]) {
                        int currentDifference = abs(subgridElements[i] - subgridElements[i - 1]);
                        minDifference = min(minDifference, currentDifference);
                    }
                }
              
                // If no distinct elements found (all elements are same), set difference to 0
                result[startRow][startCol] = (minDifference == INT_MAX) ? 0 : minDifference;
            }
        }
      
        return result;
    }
};
