class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
      
        // Try all 4 possible rotations (0°, 90°, 180°, 270°)
        for (int rotationCount = 0; rotationCount < 4; ++rotationCount) {
            // Create a new matrix to store the rotated result
            vector<vector<int>> rotatedMatrix(n, vector<int>(n));
          
            // Perform 90-degree clockwise rotation
            // For element at position (i, j) in original matrix,
            // it moves to position (j, n-1-i) after rotation
            for (int row = 0; row < n; ++row) {
                for (int col = 0; col < n; ++col) {
                    rotatedMatrix[row][col] = mat[col][n - row - 1];
                }
            }
          
            // Check if the rotated matrix matches the target
            if (rotatedMatrix == target) {
                return true;
            }
          
            // Update mat for the next rotation iteration
            mat = rotatedMatrix;
        }
      
        // No rotation matched the target
        return false;
    }
};
