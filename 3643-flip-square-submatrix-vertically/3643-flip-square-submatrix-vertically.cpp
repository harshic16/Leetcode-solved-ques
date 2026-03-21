class Solution {
public:
    /**
     * Reverses a k×k submatrix vertically (flip rows top to bottom)
     * @param grid - The input 2D matrix to be modified
     * @param x - Starting row index of the submatrix
     * @param y - Starting column index of the submatrix
     * @param k - Size of the square submatrix (k×k)
     * @return The modified grid with the submatrix reversed
     */
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // Iterate through the first half of rows in the submatrix
        for (int row = x; row < x + k / 2; row++) {
            // Calculate the corresponding row from the bottom to swap with
            int mirrorRow = x + k - 1 - (row - x);
          
            // Swap elements in all columns of the current row with the mirror row
            for (int col = y; col < y + k; col++) {
                swap(grid[row][col], grid[mirrorRow][col]);
            }
        }
      
        return grid;
    }
};
