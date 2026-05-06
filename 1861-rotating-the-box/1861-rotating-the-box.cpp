class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();
      
        // Create result matrix with dimensions swapped (rotated 90 degrees clockwise)
        vector<vector<char>> rotatedBox(cols, vector<char>(rows));
      
        // Step 1: Rotate the box 90 degrees clockwise
        // Original position (i, j) maps to (j, rows - 1 - i) after rotation
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                rotatedBox[col][rows - row - 1] = box[row][col];
            }
        }
      
        // Step 2: Apply gravity - make stones fall down in each column
        for (int col = 0; col < rows; ++col) {
            queue<int> emptyPositions;  // Track empty positions where stones can fall
          
            // Process from bottom to top (gravity pulls stones down)
            for (int row = cols - 1; row >= 0; --row) {
                if (rotatedBox[row][col] == '*') {
                    // Obstacle found - clear all empty positions above it
                    queue<int> newQueue;
                    swap(emptyPositions, newQueue);
                } 
                else if (rotatedBox[row][col] == '.') {
                    // Empty space - add to available positions
                    emptyPositions.push(row);
                } 
                else if (rotatedBox[row][col] == '#' && !emptyPositions.empty()) {
                    // Stone found and there's an empty position below
                    // Move stone to the lowest available empty position
                    int targetRow = emptyPositions.front();
                    emptyPositions.pop();
                  
                    rotatedBox[targetRow][col] = '#';  // Place stone at target
                    rotatedBox[row][col] = '.';         // Current position becomes empty
                    emptyPositions.push(row);           // Add current position as available
                }
            }
        }
      
        return rotatedBox;
    }
};
